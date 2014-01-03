#include <boost/type_traits.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/prior.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/clear.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/pop_back.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/erase.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/advance.hpp>
#include <boost/mpl/distance.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/iterator_tags.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/vector.hpp>
#include <loki/NullType.h>

#include <iostream>


namespace mpl = boost::mpl;

class fibo_tag{};
template <int n>
struct fibo_seq
{
	typedef fibo_tag tag;
};

template <class N>
struct fibo_iterator
{
	typedef fibo_iterator type;
	typedef boost::mpl::random_access_iterator_tag category;
};
template < int N>
struct fibo_at:mpl::plus<typename fibo_at<N-1>::type, typename fibo_at<N-2>::type >
{

};

template <>
struct fibo_at<0>
{
	typedef mpl::int_<0> type;
};


template <>
struct fibo_at<1>
{
	typedef mpl::int_<1> type;
};

namespace boost{
	namespace mpl{
		template<class N>
		struct next<fibo_iterator<N> >
		{
				typedef fibo_iterator<typename next<N>::type > type;
		};

		template<class N>
		struct prior<fibo_iterator<N> >
		{
				typedef fibo_iterator< typename prior<N>::type > type;
		};
		template<>
		struct begin_impl<fibo_tag>
		{
			template <class Sequence>
			struct apply
			{
				typedef fibo_iterator< int_<0> > type;
			};
		};
		template<>
		struct front_impl<fibo_tag>
		{
			template <class Sequence>
			struct apply
			{
				typedef typename  deref< typename mpl::begin<Sequence>::type >::type type;
			};
		};
		template<>
		struct back_impl<fibo_tag>
		{
			template <class Sequence>
			struct apply
			{
				typedef typename  deref<typename mpl::prior<typename mpl::end<Sequence>::type >::type > ::type type;
			};
		};
		template<>
		struct end_impl<fibo_tag>
		{
			template <class Sequence>
			struct apply
			{
				typedef fibo_iterator< typename size<Sequence>::type > type;
			};
		};
		template<>
		struct at_impl<fibo_tag>
		{	template <class Seq, class N>
			struct apply: fibo_at<N::value>
			{};
		
		};
		template<class N>
		struct deref<fibo_iterator<N> >:fibo_at<N::value>
		{
		};
		template<class Pos, class N>
		struct advance <fibo_iterator<Pos>,N >:fibo_iterator<plus<Pos,N> >
		{
		};
		template<class Pos, class N>
		struct distance <fibo_iterator<Pos>,fibo_iterator<N> >:minus<N,Pos >
		{
		};
		template<>
		struct size_impl<fibo_tag>
		{
			template <class t >
			struct apply;
			template <int n>
			struct apply<fibo_seq<n> >:int_<n>{
			};
		};
	}
}
namespace mpl = boost::mpl;
int ch05_fibo_n_main()
{
	typedef mpl::advance<mpl::begin<fibo_seq<9> >::type, mpl::int_<6>>::type  It;
	typedef mpl::advance<It, mpl::int_<4>>::type  It2;
	typedef mpl::advance_c<It,4>::type  It3;

	std::cout<<mpl::deref<It>::type::value<<std::endl;
	std::cout<<mpl::deref<It2>::type::value<<std::endl;
	std::cout<<mpl::deref<It3>::type::value<<std::endl;
	std::cout<<mpl::back<fibo_seq<8> >::type::value<<std::endl;
	std::cout<<mpl::size<fibo_seq<8> >::type::value<<std::endl;
	return 0;
}