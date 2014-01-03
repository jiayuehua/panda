//#include <include/sys/stat.h>
#include <sstream>
#include <string>
#include <iostream>
#include <boost/ref.hpp>
int stringstream_main()
{
    {
	std::string s;
	std::ostringstream os(boost::ref(s));
	os << "world";
	std::cout<<s;
    }
    system("pause");
	return 0;
}