#include <boost/mpl/lambda.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/apply.hpp>

#include <boost/type_traits.hpp>
#include <vector>
#include <iostream>
namespace mpl = boost::mpl;
struct add_pointer_f1
{
	template <class T>
	struct apply:boost::add_pointer<T>{};
};
//typedef mpl::lambda<mpl::lambda<mpl::_1> >::type t1;
//typedef mpl::apply<mpl::_1,mpl::plus<mpl::_1, mpl::_2 > >::type t2;
//typedef mpl::apply<mpl::_1, std::vector<int> >::type t3;
//typedef mpl::apply<mpl::_1, std::vector<mpl::_1> >::type t4;
//typedef mpl::apply<mpl::lambda<mpl::_1>, mpl::plus<mpl::_1, mpl::_2 > >::type t5;
//typedef mpl::apply<mpl::lambda<mpl::_1>, std::vector<int> >::type t6;
//typedef mpl::apply<mpl::lambda<mpl::_1>, std::vector<mpl::_1> >::type t7;
//typedef mpl::apply<mpl::_1, mpl::lambda<mpl::plus<mpl::_1, mpl::_2 >>>::type t10;

template <class F,class T>
struct Twice2
	: mpl::apply<F, typename mpl::apply<F,T>::type>
{}; 
typedef mpl::lambda<Twice2<mpl::_1, mpl::_2> >::type t11;
int ch03_main()
{
	//std::cout<<boost::is_same<int,t1::template apply<int>::type >::value<<std::endl;
	//std::cout<<boost::is_same<t2, mpl::plus<mpl::_1,mpl::_2> >::value<<std::endl;
	//std::cout<<boost::is_same<t3, std::vector<int> >::value<<std::endl;
	//std::cout<<boost::is_same<t4, std::vector<mpl::_1> >::value<<std::endl;
	//std::cout<<boost::is_same<t5, mpl::lambda<mpl::plus<mpl::_1, mpl::_2 >>::type >::value<<std::endl;
	//std::cout<<boost::is_same<t6, std::vector<int> >::value<<std::endl;
	//std::cout<<boost::is_same<t7, mpl::lambda<std::vector<mpl::_1> >::type >::value<<std::endl;
	//std::cout<<boost::is_same<t10, mpl::lambda<mpl::plus<mpl::_1, mpl::_2 >> >::value<<std::endl;
	std::cout<<boost::is_same<int**, mpl::apply<add_pointer_f1,mpl::apply<add_pointer_f1, int >::type >::type >::value<<std::endl;
	std::cout<<boost::is_same<int**, Twice2<add_pointer_f1, int >::type >::value<<std::endl;
	std::cout<<boost::is_same<int**, t11::template apply<add_pointer_f1, int >::type >::value<<std::endl;
	return 0;
}
 