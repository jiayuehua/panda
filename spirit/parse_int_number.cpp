#include <boost/spirit/include/qi.hpp>
#include <boost/range.hpp>
#include <boost/range/algorithm.hpp>
#include <iostream>
#include <iterator>
#include <cstring>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_algorithm.hpp>
#include <boost/spirit/include/phoenix_container.hpp>
void print(int x)
{
	std::cout<<x;
}
int parse_int_number_main()
{
	namespace qi = boost::spirit::qi;
	
	using qi::parse;
	using qi::phrase_parse;
	using qi::int_;
	using qi::double_;
	using qi::ascii::space;
	using qi::_1;
	using boost::phoenix::ref;
	using boost::phoenix::push_back;
	char * a = "(12e2,12223)";
	char * a_end = a+strlen(a) ;
	char * b = "(1233)";
	char * b_end = b+strlen(b);
	char * c = "1  , 2,3,4,5,6,7,8,10,13";
	char * c_end = b+strlen(b) ;
	int n = 0;

	std::vector<int> iv;

	phrase_parse(c,c_end, int_%',', space, iv);
	std::ostream_iterator <int> oi(std::cout, ",");
	boost::copy(iv,oi);
	std::cout<<"\n";
	return 0;
}