//
//#include <boost/type_traits.hpp>
//#include <boost/mpl/next.hpp>
//#include <boost/mpl/prior.hpp>
//#include <boost/mpl/at.hpp>
//#include <boost/mpl/int.hpp>
//#include <boost/mpl/plus.hpp>
//#include <boost/mpl/minus.hpp>
//#include <boost/mpl/clear.hpp>
//#include <boost/mpl/equal.hpp>
//#include <boost/mpl/push_front.hpp>
//#include <boost/mpl/pop_front.hpp>
//#include <boost/mpl/pop_back.hpp>
//#include <boost/mpl/insert.hpp>
//#include <boost/mpl/erase.hpp>
//#include <boost/mpl/begin.hpp>
//#include <boost/mpl/advance.hpp>
//#include <boost/mpl/distance.hpp>
//#include <boost/mpl/push_back.hpp>
//#include <boost/mpl/size.hpp>
//#include <boost/mpl/iterator_tags.hpp>
//#include <boost/mpl/vector_c.hpp>
//#include <boost/mpl/vector.hpp>
//#include <loki/NullType.h>
//
//#include <iostream>
//
//
//namespace mpl = boost::mpl;
//
//class fibonacci_tag{};
//struct fibonacci_seq
//{
//	typedef fibonacci_tag tag;
//};
//
//template <class N>
//struct fibonacci_iterator
//{
//	typedef fibonacci_iterator type;
//	typedef boost::mpl::random_access_iterator_tag category;
//};
//template < int N>
//struct fibonacci_at:mpl::plus<typename fibonacci_at<N-1>::type, typename fibonacci_at<N-2>::type >
//{
//
//};
//
//template <>
//struct fibonacci_at<0>
//{
//	typedef mpl::int_<0> type;
//};
//
//
//template <>
//struct fibonacci_at<1>
//{
//	typedef mpl::int_<1> type;
//};
//
//namespace boost{
//	namespace mpl{
//		template<class N>
//		struct next<fibonacci_iterator<N> >
//		{
//				typedef fibonacci_iterator<typename next<N>::type > type;
//		};
//
//		template<class N>
//		struct prior<fibonacci_iterator<N> >
//		{
//				typedef fibonacci_iterator< typename prior<N>::type > type;
//		};
//		template<>
//		struct begin_impl<fibonacci_tag>
//		{
//			template <class Sequence>
//			struct apply
//			{
//				typedef fibonacci_iterator< int_<0> > type;
//			};
//		};
//		template<>
//		struct at_impl<fibonacci_tag>
//		{	template <class Seq, class N>
//			struct apply
//			;
//			template <class N>
//			struct apply<fibonacci_seq,N>: fibonacci_at<N::value>
//			{};
//		
//		};
//		template<class N>
//		struct deref<fibonacci_iterator<N> >:at<fibonacci_seq,N>
//		{
//		};
//		template<class Pos, class N>
//		struct advance <fibonacci_iterator<Pos>,N >:fibonacci_iterator<plus<Pos,N> >
//		{
//		};
//		template<class Pos, class N>
//		struct distance <fibonacci_iterator<Pos>,fibonacci_iterator<N> >:minus<N,Pos >
//		{
//			
//		};
//		
//	}
//}
//namespace mpl = boost::mpl;
//int fibo_main()
//{
//	typedef mpl::advance<mpl::begin<fibonacci_seq>::type, mpl::int_<6>>::type  It;
//	typedef mpl::advance<It, mpl::int_<4>>::type  It2;
//	typedef mpl::advance_c<It,4>::type  It3;
//	std::cout<<mpl::deref<It>::type::value<<std::endl;
//	std::cout<<mpl::deref<It2>::type::value<<std::endl;
//	std::cout<<mpl::deref<It3>::type::value<<std::endl;
//	return 0;
//}