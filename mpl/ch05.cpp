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
#include <boost/mpl/iterator_tags.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/vector.hpp>
#include <loki/NullType.h>

#include <iostream>


namespace mpl = boost::mpl;

class tiny_tag{};

template <class T0 = Loki::NullType, class T1 = Loki::NullType, class T2 = Loki::NullType>
struct tiny{
	typedef tiny_tag tag;
	typedef tiny type;
	typedef T0 t0;
	typedef T1 t1;
	typedef T2 t2;
};


class tiny_iterator_tag{};
template <class T, class N>
struct tiny_iterator
{
	typedef tiny_iterator type;
	typedef tiny_iterator_tag tag;
	typedef boost::mpl::random_access_iterator_tag category;
};
template <class T, int N>
struct tiny_at;

template <class T0,class T1, class T2>
struct tiny_at<tiny<T0,T1,T2>,0>
{
	typedef T0 type;
};


template <class T0,class T1, class T2>
struct tiny_at<tiny<T0,T1,T2>,1>
{
	typedef T1 type;
};

template <class T0,class T1, class T2>
struct tiny_at<tiny<T0,T1,T2>,2>
{
	typedef T2 type;
};
namespace boost{
	namespace mpl{
		template<class T,class N>
		struct next<tiny_iterator<T,N> >
		{
				typedef tiny_iterator<T, typename next<N>::type > type;
		};

		template<class T,class N>
		struct prior<tiny_iterator<T,N> >
		{
				typedef tiny_iterator<T, typename prior<N>::type > type;
		};
		template<>
		struct begin_impl<tiny_tag>
		{
			template <class Sequence>
			struct apply
			{
				typedef tiny_iterator<Sequence, int_<0> > type;
			};
		};
		template<>
		struct end_impl<tiny_tag>
		{
			template <class Sequence>
			struct apply
			{
				typedef tiny_iterator<Sequence, typename size<Sequence>::type > type;
			};
		};
		template<>
		struct at_impl<tiny_tag>
		{
			template <class Sequence, class N>
			struct apply: tiny_at<Sequence,N::value>
			{};
		};
		template<class T,class N>
		struct deref<tiny_iterator<T,N> >:at<T,N>
		{
		};
		template<class T,class Pos, class N>
		struct advance <tiny_iterator<T,Pos>,N >:tiny_iterator<T,plus<Pos,N> >
		{
		};
		template<class T,class Pos, class N>
		struct distance <tiny_iterator<T,Pos>,tiny_iterator<T,N> >:minus<N,Pos >
		{
			
		};
		template<>
		struct clear_impl<tiny_tag>
		{
			template <class Sequence>
			struct apply :tiny<>
			{
			};
		};
		template<class Seq, class T, int n>
		struct push_front_tiny
		{
			typedef typename  tiny<T, typename Seq::t0, typename Seq::t1>::type type;
		};
		template<class tiny, class T>
		struct push_front_tiny< tiny, T, 3>;
		template<>
		struct push_front_impl<tiny_tag>
		{
			template <class Sequence, class T>
			struct apply 
			{
				typedef push_front_tiny<Sequence, T, size<Sequence>::value> type;
			};
		};

		template <class Sequence, int pos1,  int pos2, bool valid>//pos iterator
		struct erase_tiny;
		template<class Sequence>
		struct erase_tiny<Sequence, 0, 0, true>
		{
			typedef Sequence type;
		};
		template<class Sequence>
		struct erase_tiny<Sequence, 0, 1, true>
		{
			typedef tiny<typename Sequence::t1,typename  Sequence::t2> type;
		};
		template<class Sequence>
		struct erase_tiny<Sequence, 0, 2, true>
		{
			typedef tiny<typename Sequence::t2> type;
		};
		template<class Sequence>
		struct erase_tiny<Sequence, 0, 3, true>
		{
			typedef tiny<> type;
		};
		
		template<class Sequence>
		struct erase_tiny<Sequence, 1, 1, true>
		{
			typedef Sequence type;
		};
		template<class Sequence>
		struct erase_tiny<Sequence, 1, 2, true>
		{
			typedef tiny<typename Sequence::t0, typename Sequence::t2> type;
		};
		template<class Sequence>
		struct erase_tiny<Sequence, 1, 3, true>
		{
			typedef tiny<typename Sequence::t0> type;
		};
		template<class Sequence>
		struct erase_tiny<Sequence, 2, 2, true>
		{
			typedef Sequence type;
		};
		template<class Sequence>
		struct erase_tiny<Sequence, 2, 3, true>
		{
			typedef tiny<typename Sequence::t0, typename Sequence::t1> type;
		};
		template<class Sequence>
		struct erase_tiny<Sequence, 3, 3, true>
		{
			typedef Sequence type;
		};
		template <>
		struct erase_impl<tiny_tag>
		{
			template <class Sequence, class Pos1, class Pos2>//pos iterator
			struct apply;
			template <class Sequence, class Pos1, class Pos2>//pos iterator
			struct apply <Sequence, tiny_iterator<Sequence, Pos1>, tiny_iterator<Sequence, Pos2> >
			{
				typedef tiny_iterator<Sequence, Pos1> POS1;
				typedef tiny_iterator<Sequence, Pos2> POS2;
				static const int pos3 = distance<POS2, typename end<Sequence>::type>::value ;
				static const int pos1 = distance<typename begin<Sequence>::type, POS1>::value ;
				static const int pos2 = distance<typename begin<Sequence>::type, POS2>::value ;
				static const int valid = pos3>=0;
				typedef typename erase_tiny<Sequence, pos1, pos2, valid>::type type;
			};
			template <class Sequence, class Pos1, class Pos6>//pos iterator
			struct apply <Sequence, tiny_iterator<Sequence, Pos1>, Pos6>
			{
				typedef tiny_iterator<Sequence, Pos1> POS1;
				typedef typename mpl::next<Pos1>::type Pos2;
				typedef tiny_iterator<Sequence, Pos2> POS2;
				static const int pos3 = distance<POS2, typename end<Sequence>::type>::value ;
				static const int pos1 = distance<typename begin<Sequence>::type, POS1>::value ;
				static const int pos2 = distance<typename begin<Sequence>::type, POS2>::value ;
				static const int valid = pos3>=0;
				typedef typename erase_tiny<Sequence, pos1, pos2, valid>::type type;
			};
		};
		template <class Sequence, class pos, class T, bool valid>//pos iterator
		struct insert_tiny;
		template<class Sequence, class T >
		struct insert_tiny<Sequence,tiny_iterator<Sequence ,int_<0> >, T, true>
		{
			typedef tiny<T, typename Sequence::t0, typename Sequence::t1> type;

		};
		template<class Sequence, class T >
		struct insert_tiny<Sequence,tiny_iterator<Sequence ,int_<1> >, T, true>
		{
			typedef tiny< typename Sequence::t0, T, typename Sequence::t1> type;

		};
		template<class Sequence, class T >
		struct insert_tiny<Sequence,tiny_iterator<Sequence ,int_<2> >, T, true>
		{
			typedef tiny< typename Sequence::t0,  typename Sequence::t1, T> type;

		};
		template <>
		struct insert_impl<tiny_tag>
		{
			template <class Sequence, class Pos, class T>//pos iterator
			struct apply 
			{
				typedef typename insert_tiny<Sequence, Pos,T, distance<Pos, typename end<Sequence>::type >::type::value >=0 >::type type;
			};
		};
		template <class Sequence, int n>
		struct pop_back_tiny;
		template <class Sequence>
		struct pop_back_tiny<Sequence, 1>
		{
			typedef tiny<> type;
		};
		template <class Sequence>
		struct pop_back_tiny<Sequence, 2>
		{
			typedef tiny<typename Sequence::t0> type;
		};
		template <class Sequence>
		struct pop_back_tiny<Sequence, 3>
		{
			typedef tiny<typename Sequence::t0, typename Sequence::t1> type;
		};
		template<>
		struct pop_back_impl<tiny_tag>
		{
			template <class Sequence>
			struct apply 
			{
				typedef typename pop_back_tiny<Sequence , size<Sequence>::value >::type type;
			};
		};
		template <class Sequence, int n>
		struct pop_front_tiny
		{
			typedef tiny<typename Sequence::t1, typename Sequence::t2> type;
		};
		template <class Sequence>
		struct pop_front_tiny<Sequence, 0> ;
		template<>
		struct pop_front_impl<tiny_tag>
		{
			template <class Sequence>
			struct apply 
			{
				typedef typename pop_front_tiny<Sequence , size<Sequence>::value >::type type;
			};

		};
		template<>
		struct push_back_impl<tiny_tag>
		{
			template <class Sequence, class T>
			struct apply 
			{
				typedef typename insert<Sequence, typename end<Sequence>::type,T >::type type;
			};

			/*template <class Sequence, class T>
			struct apply ;
			template <class T>
			struct apply<tiny<>, T > :tiny<T>
			{
			};
			template <class T0, class T>
			struct apply <tiny<T0>,T >:tiny <T0, T>
			{
			};
			template <class T0, class T1, class T>
			struct apply <tiny<T0, T1>, T >:tiny <T0, T1, T>
			{
			};*/
		};
		template<>
		struct size_impl<tiny_tag>
		{
			template <class Sequence>
			struct apply;
			template <class T>
			struct apply<tiny<T> >:int_<1>{
			};
			template <>
			struct apply<tiny<> >:int_<0>{
			};
			template <class T0,class T1>
			struct apply<tiny<T0,T1> >:int_<2>{
			};
			template <class T0,class T1, class T2>
			struct apply<tiny<T0,T1, T2> >:int_<3>{
			};
		};
	}
}

template <class T>
struct mydimensions;

namespace mpl = boost::mpl;
template <class T, int n1>
struct mydimensions<T[n1]>
	: public  mpl::vector<
	mpl::int_<n1> 
	>
{
};
template <class T, int n2, int n1>
struct mydimensions<T[n2][n1]>
	: public  mpl::vector<
	mpl::int_<n1>, 
	mpl::int_<n2> 
	>
{
};
template <class T, int n1,int n2, int n3>
struct mydimensions<T[n3][n2][n1]>
	: public  mpl::vector<
	mpl::int_<n1>, 
	mpl::int_<n2>, 
	mpl::int_<n3> 
	>
{
};
template <class T, int n1,int n2, int n3, int n4>
struct mydimensions<T[n4][n3][n2][n1]>
	: public  mpl::vector<
	mpl::int_<n1>, 
	mpl::int_<n2>, 
	mpl::int_<n3>, 
	mpl::int_<n4>
>
{
};
template <class T, int n1,int n2, int n3, int n4, int n5>
struct mydimensions<T[n5][n4][n3][n2][n1]>
	: public  mpl::vector<
	mpl::int_<n1>, 
	mpl::int_<n2>, 
	mpl::int_<n3>, 
	mpl::int_<n4>, 
	mpl::int_<n5> 
>
{
};
//template <class T, int N>
//struct mydimensions<T[N]>
//{
//	typedef mpl::vector_c<int,N> type;
//};
//template <class T, int N>
//struct mydimensions<T[N]>
//{
//	typedef mpl::vector_c<int,N> type;
//};
//template <class T, int N>
//struct mydimensions<T[N]>
//{
//	typedef mpl::vector_c<int,N> type;
//};



int ch05_main()
{
	//std::cout<<mpl::size<tiny<int,int,int> >::type::value<<std::endl;
	//std::cout<<mpl::equal< mpl::insert<tiny<int,double>,mpl::int_<0>, float>::type, tiny<float,int,double>::type >::type::value<<std::endl;
	//std::cout<<mpl::equal< mpl::insert<tiny<int,double>,mpl::int_<1>, float>::type, tiny<int,float,double>::type >::type::value<<std::endl;
	//std::cout<<mpl::equal< mpl::insert<tiny<int,double>,mpl::int_<2>, float>::type, tiny<int,double,float>::type >::type::value<<std::endl;
	//std::cout<<mpl::equal< mpl::insert<tiny<int>,mpl::int_<1>, float>::type, tiny<int,double,float>::type >::type::value<<std::endl;
	//std::cout<<mpl::equal< mpl::insert<tiny<int>, mpl::begin<tiny<int> >::type, float>::type, tiny<float,int>::type >::type::value<<std::endl;
	//std::cout<<mpl::equal< mpl::push_back<tiny<int,double>, float>::type, tiny<int,double, float>::type >::type::value<<std::endl;
	//std::cout<<mpl::equal< mpl::pop_back<tiny<int,double,float> >::type, tiny<int,double> >::type::value<<std::endl;

	//std::cout<<mpl::equal< mpl::pop_front<tiny<int,double,float> >::type, tiny<double,float> >::type::value<<std::endl;
	typedef tiny_iterator<tiny<int , double, float>, mpl::int_<0> > i0;
	typedef tiny_iterator<tiny<int , double, float>, mpl::int_<1> > i1;
	typedef tiny_iterator<tiny<int , double, float>, mpl::int_<2> > i2;
	typedef tiny_iterator<tiny<int , double, float>, mpl::int_<3> > i3;
	std::cout<<mpl::equal< mpl::erase<tiny<int,double,float>, i0,i1 >::type, tiny<double,float> >::type::value<<std::endl;
	std::cout<<mpl::equal< mpl::erase<tiny<int,double,float>, i0,i2 >::type, tiny<float> >::type::value<<std::endl;
	std::cout<<mpl::equal< mpl::erase<tiny<int,double,float>, i0 >::type, tiny<double,float> >::type::value<<std::endl;
	std::cout<<mpl::at_c<mydimensions<int[10][2]>, 0>::type::value;
	std::cout<<std::endl;
	std::cout<<mpl::at_c<mydimensions<int[10][2]>, 1>::type::value;
	std::cout<<std::endl;
	std::cout<<mpl::at_c<mydimensions<int[1][3][5][10][2]>, 1>::type::value;
	std::cout<<std::endl;
	std::cout<<mpl::at_c<mydimensions<int[1][3][5][10][2]>, 4>::type::value;
	std::cout<<std::endl;
	/*int i = 0;
	std::cout<<mpl::deref<mpl::begin<mydimensions<int[10]> >::type>::type::value<<std::endl;
	std::cout<<mpl::equal<mpl::push_back<mydimensions<int[10]> ,mpl::int_<5> >::type,mpl::vector<mpl::int_<10>, mpl::int_<5> > >::value<<std::endl;
	std::cout<<mpl::equal<mpl::push_back<mpl::vector<mpl::int_<10> > ,mpl::int_<5> >::type,mpl::vector<mpl::int_<10>, mpl::int_<5> > >::value<<std::endl;
	*/
	return 0;
}
