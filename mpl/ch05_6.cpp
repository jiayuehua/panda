// by Nico Gau
#include <boost/static_assert.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/iterator_tags.hpp>
namespace mpl = boost::mpl;
template <typename T>
struct num_dimensions
{
	static const int dimensions = 0;
	//BOOST_STATIC_CONSTANT(dimensions, = 0);
};
template <typename T, std::size_t N>
struct num_dimensions<T[N]>
{
	static const int dimensions = num_dimensions<T>::dimensions + 1;
	//BOOST_STATIC_CONSTANT(dimensions, = 1);
};
template <typename T, int N>
struct nth_dimension;
template <typename T, std::size_t N, int Size>
struct nth_dimension<T[Size], N>
	: mpl::eval_if<mpl::bool_<N >= num_dimensions<T>::dimensions>,
							  mpl::int_<Size>,
							  nth_dimension<T, N> >
{
};
struct dimensions_tag;
template <typename Array>
struct dimensions
{
	typedef Array array_type;
	typedef dimensions_tag tag;
};
template <typename S, int Pos>
struct dimensions_iterator
{
	typedef mpl::forward_iterator_tag category;
	typedef typename nth_dimension<typename S::array_type, Pos> type;
	typedef dimensions_iterator<S, Pos + 1> next;
};
namespace boost { namespace mpl {
	template <>
	struct begin_impl<dimensions_tag>
	{
		template <typename S>
		struct apply
		{
			typedef dimensions_iterator<S, 0> type;
		};
	};
	template <>
	struct end_impl<dimensions_tag>
	{
		template <typename S>
		struct apply 
		{
			typedef num_dimensions<typename S::array_type> num;
			typedef dimensions_iterator<S, num::dimensions > type;
		};
	};
}}
typedef nth_dimension<char [10][5][2], 0>::type first_dimension;
typedef nth_dimension<char [10][5][2], 1>::type second_dimension;
typedef nth_dimension<char [10][5][2], 2>::type third_dimension;
BOOST_STATIC_ASSERT(( first_dimension::type::value == 2 ));
BOOST_STATIC_ASSERT(( second_dimension::type::value == 5 ));
BOOST_STATIC_ASSERT(( third_dimension::type::value == 10 ));
typedef dimensions<char [10][5][2]> seq;
BOOST_STATIC_ASSERT(( mpl::size<seq>::type::value == 3 ));
BOOST_STATIC_ASSERT(( mpl::at_c<seq, 0>::type::value == 2 ));
BOOST_STATIC_ASSERT(( mpl::at_c<seq, 1>::type::value == 5 ));
BOOST_STATIC_ASSERT(( mpl::at_c<seq, 2>::type::value == 10 ));