//#include <boost/spirit/include/qi.hpp>
//#include <boost/spirit/include/phoenix_core.hpp>
//#include <boost/spirit/include/phoenix_operator.hpp>
//#include <boost/spirit/include/phoenix_stl.hpp>
//#include <boost/fusion/include/adapt_struct.hpp>
//#include <boost/variant/recursive_variant.hpp>
//#include <algorithm>
//#include <vector>
//#include <string>
//#include <iostream>
//#include <fstream>
//namespace qi = boost::spirit::qi;
//namespace ascii = boost::spirit::ascii;
//
//struct mini_xml;
//typedef boost::variant<
//std::string,
//boost::recursive_wrapper<mini_xml>
//>mini_xml_node;
//
//struct mini_xml
//{
//	std::string tag;
//	std::vector<mini_xml_node> children;
//};
//
//const int tabsize = 4;
//void printtab(int tabstop)
//{
//	for (int i = 0; i < tabstop; ++i)
//	{
//		std::cout<<" ";
//	}
//}
//struct mini_xml_printer;
//struct mini_xml_node_printer: public boost::static_visitor<>
//{
//	mini_xml_node_printer(int tabstop = 0):tabstop_(tabstop){}
//	void operator()(const std::string& s)const
//	{
//		printtab(tabstop_);std::cout<<s<<std::endl;
//	}
//	void operator()(const mini_xml& m_xml)const;
//private:
//	int tabstop_;
//};
//struct mini_xml_printer
//{
//	mini_xml_printer(int tabstop = 0):tabstop_(tabstop){}
//	void operator()(const mini_xml & m_xml)const
//	{
//
//		printtab(tabstop_);std::cout<<m_xml.tag<<std::endl;
//		printtab(tabstop_);std::cout<<"{"<<std::endl;
//		BOOST_FOREACH(const mini_xml_node& node, m_xml.children)
//		{
//			boost::apply_visitor(mini_xml_node_printer(tabstop_+tabsize),node);
//		}
//		printtab(tabstop_);std::cout<<"}"<<std::endl;
//	}
//private:
//	int tabstop_;
//};
//void mini_xml_node_printer::operator()(const mini_xml& m_xml)const
//{
//	mini_xml_printer m(tabstop_);
//	m(m_xml);
//}
//
//BOOST_FUSION_ADAPT_STRUCT
//(mini_xml,
// (std::string,tag)
// (std::vector<mini_xml_node>,children)
// )
//
//template <typename Iterator>
//class Grammar: public qi::grammar<Iterator, mini_xml(),qi::locals<std::string>,ascii::space_type>
//{
//public:
//	Grammar():Grammar::base_type(xml){
//		using ascii::char_;
//		using ascii::string;
//		using qi::lit;
//		using namespace qi::labels;
//		using qi::lexeme;
//		start_tag %= '<'
//			>> !lit("/")
//			>> lexeme[+(char_ - '>')]
//			>> '>';
//		end_tag = "</"
//			>> string(_r1)
//			>> '>';
//		node %= xml| text;
//		text %= lexeme[+(char_ - '<')] ;
//		xml  %= start_tag[_a = _1]
//			>> *node
//			>> end_tag(_a);
//	}
//private:
//	qi::rule<Iterator, mini_xml(),qi::locals<std::string>,ascii::space_type> xml;
//	qi::rule<Iterator, std::string(),ascii::space_type> start_tag;
//	qi::rule<Iterator, void(std::string),ascii::space_type> end_tag;
//	qi::rule<Iterator, std::string(),ascii::space_type> text;
//	qi::rule<Iterator, mini_xml_node(),ascii::space_type> node;
//};
//int main(int argc, char** argv)
//{
//
//    char const* filename;
//    if (argc > 1)
//    {
//        filename = argv[1];
//    }
//    else
//    {
//        std::cerr << "Error: No input file provided." << std::endl;
//        return 1;
//    }
//
//    std::ifstream in(filename, std::ios_base::in);
//
//    if (!in)
//    {
//        std::cerr << "Error: Could not open input file: "
//            << filename << std::endl;
//        return 1;
//    }
//
//    std::string storage; // We will read the contents here.
//    in.unsetf(std::ios::skipws); // No white space skipping!
//    std::copy(
//        std::istream_iterator<char>(in),
//        std::istream_iterator<char>(),
//        std::back_inserter(storage));
//	Grammar<std::string::const_iterator> grammar;
//	mini_xml xml;
//	qi::phrase_parse(storage.begin(),storage.end(), grammar, ascii::space, xml);
//	mini_xml_printer()(xml);
//}