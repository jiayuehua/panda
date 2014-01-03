#include <boost/ref.hpp>
#include <iostream>
class A
{
public:
	A(){}
	A(const A&)
	{
		std::cout<<"Copy construct \n";
	}
};
template<class T>
void foo(T t)
{
}
int test_ref_main()
{
	A a;
	std::cout<<"---origin--\n";
	foo(a);
	std::cout<<"-----ref---\n";
	foo(boost::ref(a));
	return 0;
}