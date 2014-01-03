//#include <boost/spirit/include/qi.hpp>
//#include <boost/spirit/include/phoenix_object.hpp>
//#include <boost/spirit/include/phoenix_operator.hpp>
//#include <boost/spirit/include/phoenix_core.hpp>
//#include <boost/fusion/include/adapt_struct.hpp>
//#include <boost/fusion/include/io.hpp>
//
//#include <iostream>
//#include <string>
//namespace qi = boost::spirit::qi;
//namespace ascii = boost::spirit::ascii;
//
//
//struct Employee{
//	int salary;
//	std::string firstname;
//	std::string secondname;
//	int age;
//};
//
//BOOST_FUSION_ADAPT_STRUCT (
//	Employee,
//	(int,salary)
//	(std::string,firstname)
//	(std::string,secondname)
//	(int,age)
//)
//
//template <class Iterator>
//class Grammar1:public qi::grammar<Iterator,Employee(), ascii::space_type>
//{
//public:
//	Grammar1():Grammar1::base_type(start){
//		using ascii::char_;
//		using qi::int_;
//		using qi::lit;
//		name %= qi::lexeme['"'>>+(char_-'"' )>>'"'];
//		start %= lit("employee")>> '{'>>
//			int_>>','>>
//			name>>','>>
//			name>>','>>
//			int_>>'}';
//	}
//private:
//	qi::rule<Iterator, std::string(), ascii::space_type> name;
//	qi::rule<Iterator, Employee(), ascii::space_type> start;
//};
//
//int main()
//{
//	std::string str;
//	std::getline(std::cin, str);
//	typedef Grammar1<std::string::iterator> Gra;
//	Gra g;
//	Employee e;
//	qi::phrase_parse(str.begin(),str.end(),g,ascii::space, e);
//	std::cout<<e.firstname<<std::endl;
//	std::cout<<"worlds"<<std::endl;
//	boost::fusion::tuple_open('[');
//	boost::fusion::tuple_close(']');
//	boost::fusion::tuple_delimiter(',');
//	
//	std::cout<<boost::fusion::as_vector(e);
//}
