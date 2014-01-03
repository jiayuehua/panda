#include <boost/mpl/apply.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/not_equal_to.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/greater.hpp>
#include <boost/mpl/multiplies.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/type_traits.hpp>
#include <boost/function_types/is_function_pointer.hpp>
#include <loki/TypeTraits.h>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
namespace mpl = boost::mpl;
template <typename N, typename Predicate >
struct next_if: mpl::eval_if<
	typename mpl::apply<Predicate, N>::type,
	typename mpl::next<N>,
	mpl::identity<N>
>
{};

struct IsEven{
	template <class T>
	struct apply{
		typedef typename  mpl::bool_<T::value%2>::type  type;
	};
};

template< typename N1, typename N2>
struct formula:
	boost::mpl::if_<
	  mpl::not_equal_to<N1,N2>
	, typename mpl::if_<
	mpl::greater<N1,N2>
	,typename mpl::minus<N1,N2>::type
		,N1
		>::type
	, typename mpl::plus<
		N1,
		typename mpl::multiplies<N1, mpl::int_<2> >::type
		>::type
	>::type
{

};
template< typename N1, typename N2>
struct formula2:
	mpl::eval_if<
	  mpl::not_equal_to<N1,N2>
	, typename mpl::eval_if<
		mpl::greater<N1,N2>
		,mpl::minus<N1,N2>
		,mpl::identity<N1>
		>
	, typename mpl::plus<
		N1,
		mpl::multiplies<N1, mpl::int_<2> >
		>
	>
{

};


struct A{
	int a;
	void foo(){}
};


template <class T>
struct RetType:public mpl::if_
	<
	typename boost::is_const<T>::type,
	typename T::const_iterator,
	typename T::iterator
	>
{};
template <class Container, class Value>
typename RetType<Container>::type
container_find(Container& c, const Value& v)
{
	return std::find(c.begin(),c.end(),v);
}

template<class T>
struct Is_free_function_pointer: public 
	mpl::and_
	<
		boost::is_pointer<T>
		,boost::is_function<typename boost::remove_pointer<T>::type >
	>
{

};

void f(){}
int ch04_main()
{
	const std::vector<int> v;
	std::vector<int> v1;
	std::vector<int>::const_iterator it=	container_find(v,1);
	std::vector<int>::iterator it1 =	container_find(v1,1);
	
	typedef int  A::*DataMem;
	typedef void (A::*FunMem)();
	typedef void (*FreeFunc)();
	typedef void FreeFunc2();
	//
	//std::cout<<"-------------------------- is_member_obj_pointer---------------\n";
	std::cout<<	mpl::apply<mpl::and_<boost::is_member_pointer<mpl::_1>, mpl::not_< boost::is_member_function_pointer<mpl::_1> > >, DataMem >::type::value<<std::endl;
	std::cout<<	mpl::apply<mpl::and_<boost::is_member_pointer<mpl::_1>, mpl::not_< boost::is_member_function_pointer<mpl::_1> > >, FunMem >::type::value<<std::endl;
	//std::cout<<"-------------------------- is_free_funciton_pointer---------------\n";
	std::cout<<Is_free_function_pointer<FreeFunc>::type::value<<std::endl;
	std::cout<<	mpl::apply<mpl::and_<boost::is_pointer<mpl::_1>, boost::is_function< boost::remove_pointer<	mpl::_1> >  >, FreeFunc >::type::value<<std::endl;



	//typedef const int & CI;
	//typedef  int & RI;

	//std::cout<<"-------------------------- is reference to not const ----------------\n";
	//std::cout<<	mpl::apply<mpl::and_<boost::is_reference<mpl::_1> , mpl::not_< boost::is_const<boost::remove_reference<mpl::_1> > > >, RI >::type::value<<std::endl;
	//std::cout<<	mpl::apply<mpl::and_<boost::is_reference<mpl::_1> , mpl::not_< boost::is_const<boost::remove_reference<mpl::_1> > > >, CI >::type::value<<std::endl;
	/*std::cout<<	mpl::apply<boost::is_member_pointer<mpl::_1>, FunMem >::type::value<<std::endl;
	std::cout<<	mpl::apply<boost::is_member_function_pointer<mpl::_1>, FunMem >::type::value<<std::endl;*/
	//std::cout<<"----------------formula        ----------------------------------\n";
	//std::cout<<formula<mpl::int_<3>, mpl::int_<1> >::type::value<<std::endl;//2
	//std::cout<<formula<mpl::int_<1>, mpl::int_<3> >::type::value<<std::endl;//1
	//std::cout<<formula<mpl::int_<3>, mpl::int_<3> >::type::value<<std::endl;//9
	//std::cout<<"----------------formula  2     ----------------------------------\n";
	//std::cout<<formula2<mpl::int_<3>, mpl::int_<1> >::type::value<<std::endl;//2
	//std::cout<<formula2<mpl::int_<1>, mpl::int_<3> >::type::value<<std::endl;//1
	//std::cout<<formula2<mpl::int_<3>, mpl::int_<3> >::type::value<<std::endl;//9

	//std::cout<<"----------------next if  2     ----------------------------------\n";
	//std::cout<<next_if<mpl::int_<5>, IsEven>::type::value<<std::endl; 
	//std::cout<<next_if<mpl::int_<6>, IsEven>::type::value<<std::endl; 
	//std::cout<<"-----------------------------------------------------------------\n";

	return 0;
}