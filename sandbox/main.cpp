#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
template <class T>
struct A{};
template <>
struct A<int>;
void foo(int)
{
	std::cout<<"int\n";
}
void foo(unsigned)
{
	std::cout<<"unsigned\n";
}
int main()
{
	std::ifstream ifs ("hi.txt");//add some t
	std::ofstream ofs("o.txt");//add some te
	std::string str;//add some text in the 
	std::getline(ifs, str, char(-1));//add

	std::string a("\n");
	std::string bb("\n\n\n\n\n");
	boost::replace_all(str,a, bb);

	a.assign("¡ª¡ª");
	bb.assign("\n		");
	boost::replace_all(str,a, bb);
	std::cout<<str;
	ofs<<str;
	ofs.close();

	//std::getline()
	//unsigned a = -3;
	//int b = 1;
	//foo(a+b);
	//std::cout<<((a+b)<-1)<<std::endl;
	//A<double> c;
	//A<int> d;
}