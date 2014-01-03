// by jiayuehua
#include <boost/static_assert.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/iterator_tags.hpp>
namespace mpl = boost::mpl;

template <class T> 
struct num_dims{
	static const int value = 0;
};
template <class T, int n> 
struct num_dims<T[n]>{
	static const int value = 1+ num_dims<T>::value;
	//typedef typename mpl::next<typename num_dims<T>::type>::type type;
};


template <class T, int n>
struct nth_dim;
template <class T, int n, int size>
struct nth_dim<T[size], n>:mpl::eval_if<mpl::bool_< n >= num_dims<T>::value >, mpl::int_<size>, nth_dim<T,n> >
{

};

struct Dimensions_tag;

template <class T>
struct Dimensions
{
	typedef T Array;
	typedef Dimensions_tag tag;
};

template <class Dims, int n>
struct Dim_iterator
{
	typedef mpl::forward_iterator_tag category;
	typedef nth_dim<typename Dims::Array,n> type;
	typedef Dim_iterator<Dims,n+1> next;
};

namespace boost{
	namespace mpl{
		template <>
		struct end_impl<Dimensions_tag>
		{
			template <class Seq>
			struct apply
			{
				typedef Dim_iterator<Seq, num_dims<typename Seq::Array>::value > type;
			};
		};
		template <>
		struct begin_impl<Dimensions_tag>
		{
			template <class Seq>
			struct apply
			{
				typedef Dim_iterator<Seq, 0> type;
			};
		};
	}
}

typedef nth_dim<char [10][5][2], 0>::type first_dimension;
typedef nth_dim<char [10][5][2], 1>::type second_dimension;
typedef nth_dim<char [10][5][2], 2>::type third_dimension;
BOOST_STATIC_ASSERT(( first_dimension::type::value == 2 ));
BOOST_STATIC_ASSERT(( second_dimension::type::value == 5 ));
BOOST_STATIC_ASSERT(( third_dimension::type::value == 10 ));
typedef Dimensions<char [10][5][2]> seq;
BOOST_STATIC_ASSERT(( mpl::size<seq>::type::value == 3 ));
BOOST_STATIC_ASSERT(( mpl::at_c<seq, 0>::type::value == 2 ));
BOOST_STATIC_ASSERT(( mpl::at_c<seq, 1>::type::value == 5 ));
BOOST_STATIC_ASSERT(( mpl::at_c<seq, 2>::type::value == 10 ));
