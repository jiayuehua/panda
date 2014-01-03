#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_object.hpp>
#include <boost/fusion/include/io.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <string>
#include <iostream>
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
struct Employee{
	int salary;
	std::string firstname;
	std::string lastname;
	int age;
};
BOOST_FUSION_ADAPT_STRUCT
(   
	Employee, 
	(int,salary)
	(std::string,firstname)
	(std::string,lastname)
	(int,age)
)

template <class Iterator>
class Grammar2:public qi::grammar<Iterator, Employee(), ascii::space_type>
{
public:
	Grammar2():Grammar2::base_type(start)
	{
		using qi::lit;
		using qi::lexeme;
		using qi::int_;
		using ascii::char_;
		start %= lit("employee")>>
			'{'>>
			int_>>','>>
			name>>','>>
			name>>','>>
			int_>>
			'}';
		name %= lexeme['"'>>*(char_-'"')>>'"'] ;

	}
private:
	qi::rule<Iterator,std::string(), ascii::space_type> name;
	qi::rule<Iterator,Employee(), ascii::space_type> start;
};


int main()
{
	std::string s;
	while (std::getline(std::cin, s))
	{
		if ( s == "q")
		{
			break;
		}
		else
		{
			typedef Grammar2<std::string::iterator> GRAMMAR2;
			GRAMMAR2 gramm;
			Employee employee;
			qi::phrase_parse(s.begin(),s.end(),gramm, ascii::space, employee);
			boost::fusion::tuple_open('[');
			boost::fusion::tuple_close(']');
			boost::fusion::tuple_delimiter(',');
			std::cout<<boost::fusion::as_vector(employee);
		}
	}
}