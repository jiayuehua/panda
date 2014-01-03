#include <boost/parameter/name.hpp>
#include <boost/parameter.hpp>
#include <boost/parameter/preprocessor.hpp>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <boost/foreach.hpp>
#include <boost/assign.hpp>
#include <boost/utility.hpp>
#include <boost/swap.hpp>
#include <boost/bind.hpp>
namespace foo{
	BOOST_PARAMETER_NAME(left_arg)
	BOOST_PARAMETER_NAME(center_arg)
	BOOST_PARAMETER_NAME(right_arg)
}
	namespace foo{
		using namespace boost::parameter;
BOOST_PARAMETER_FUNCTION
(
 (int), my_max, tag,
(required(left_arg, *))
(optional
(center_arg, *, 2)
(right_arg, *, 2)
)
)
{
	std::cout<<"  "<<center_arg<<std::endl;
	return (left_arg+right_arg);
}
	}
	
int para_main()
{
	using namespace boost::assign;
	//std::cout<<foo::my_max(5,56,2)<<std::endl;
	//std::cout<<foo::my_max(5,foo::_right_arg=45)<<std::endl;
	//std::cout<<foo::my_max(false,22)<<std::endl;
	//std::cout<<foo::my_max(false,"world")<<std::endl;
	std::vector<int> iv;
	iv += 3,1,5,1,4,5,2,6;
	int a[] = {3,35,21,34,45,52,26};
	std::vector<int>::iterator i = iv.begin();
	//std::cout<<*boost::next(i,5)<<std::endl;
	BOOST_FOREACH(int& i, iv)
	{
		i *= 2;
	}
	
	BOOST_FOREACH(int i, iv)
	{
		//i *= 2;
		//std::cout<<i<<"  ";
	}
	
	BOOST_FOREACH(int i, a)
	{
		//i *= 2;
		//std::cout<<i<<"  ";
	}
	std::cout<<BOOST_BINARY(10101100);
	return 0;
}
