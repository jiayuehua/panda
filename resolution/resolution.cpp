#include <iostream>
#include <boost/type_traits.hpp>
#include <boost/bind.hpp>
#include <boost/functional/forward_adapter.hpp>
#include <boost/utility.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
class F{
public:
	template <class > struct result;
	template<class F1,class U>
	struct result<F1(U)> {
		typedef void type;
	};
	void operator ()(int a)
	{
		std::cout<<a<<std::endl;
	}
};

void f(){}

int resolution_main()
{
	const char a[] = "hello";
	const char b[] = "hello";

	//std::cout<<(a==b)<<std::endl;
	typedef void(*F)();
	F f1 = f;
	(*f1)();
	using namespace boost::tuples;
	make_tuple(&f).get<0>()();

	int i (100);
	double d (103.33);
	std::string s  ("string");
	int i1;
	double d1;
	std::string s1;
	tie(i1,d1,s1) = make_tuple(i,d,s);
	tuple<int,double,std::string> t1(10,3.22,"world");
	tuple<double,int,std::string> t3(1033.3,322,"world");
	tuple<int&,double&,std::string&> t2(i,d,s);
	std::cout<<i1<<" "<<d1<<" "<<s1<<std::endl;
	std::cout<<t1<<std::endl;
	get<0>(t1) = 1000;
	std::cout<<t1<<std::endl;
	get<0>(t2) = 1000;
	std::cout<<i<<std::endl;
	t1 = t3;
	std::cout<<t1<<std::endl;


	return 0;
}