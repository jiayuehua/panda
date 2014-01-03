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
//struct BraceExpr;
//typedef boost::variant<
//std::string,
//boost::recursive_wrapper<BraceExpr>
//>BraceNode;
//
//struct BraceExpr
//{
//	BraceNode left;
//	std::string data;
//	BraceNode right;
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
//struct BinTreePrinter;
//struct BinTreeNodePrinter: public boost::static_visitor<>
//{
//	BinTreeNodePrinter(int tabstop = 0):tabstop_(tabstop){}
//	void operator()(const std::string& s)const
//	{
//	}
//	void operator()(const BraceExpr& m_xml)const;
//private:
//	int tabstop_;
//};
//struct BinTreePrinter
//{
//	BinTreePrinter(int tabstop = 0):tabstop_(tabstop){}
//	void operator()(const BraceExpr & m_xml)const
//	{
//		printtab(tabstop_);std::cout<<"("<<std::endl;
//		boost::apply_visitor(BinTreeNodePrinter(tabstop_+tabsize),m_xml.left);
//		printtab(tabstop_);std::cout<<")"<<std::endl;
//		boost::apply_visitor(BinTreeNodePrinter(tabstop_),m_xml.right);
//	}
//private:
//	int tabstop_;
//};
//void BinTreeNodePrinter::operator()(const BraceExpr& m_xml)const
//{
//	BinTreePrinter m(tabstop_);
//	m(m_xml);
//}
//
//BOOST_FUSION_ADAPT_STRUCT
//(BraceExpr,
// (BraceNode,left)
// (std::string,data)
// (BraceNode,right)
// )
//
//template <typename Iterator>
//class Grammar: public qi::grammar<Iterator, BraceExpr(),ascii::space_type>
//{
//public:
//	Grammar():Grammar::base_type(brace_expr){
//		using ascii::char_;
//		using ascii::string;
//		using qi::lit;
//		using namespace qi::labels;
//		using qi::lexeme;
//		start_tag = '(' ;
//		end_tag = ')';
//		node %= brace_expr| text;
//		text %= lexeme[*(char_ - '('-')')] ;
//		brace_expr  %= start_tag
//			>> node>>text
//			>> end_tag>>node;
//	}
//private:
//	qi::rule<Iterator, BraceExpr(),ascii::space_type> brace_expr;
//	qi::rule<Iterator, void(),ascii::space_type> start_tag;
//	qi::rule<Iterator, void(),ascii::space_type> end_tag;
//	qi::rule<Iterator, std::string(),ascii::space_type> text;
//	qi::rule<Iterator, BraceNode(),ascii::space_type> node;
//};
//int main(int argc, char** argv)
//{
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
//    std::ifstream in(filename, std::ios_base::in);
//
//    if (!in)
//    {
//        std::cerr << "Error: Could not open input file: "
//            << filename << std::endl;
//        return 1;
//    }
//    std::string storage; // We will read the contents here.
//    in.unsetf(std::ios::skipws); // No white space skipping!
//    std::copy(
//        std::istream_iterator<char>(in),
//        std::istream_iterator<char>(),
//        std::back_inserter(storage));
//	Grammar<std::string::const_iterator> grammar;
//	BraceExpr ast;
//    std::string::const_iterator iter = storage.begin();
//    std::string::const_iterator end = storage.end();
//	bool r = qi::phrase_parse(iter, end, grammar , ascii::space, ast);
//
//    if (r && iter == end)
//    {
//        std::cout << "-------------------------\n";
//        std::cout << "parsing succeeded\n";
//        std::cout << "-------------------------\n";
//        BinTreePrinter printer;
//        printer(ast);
//        return 0;
//    }
//    else
//    {
//        std::string context(iter, (end-iter)>30?iter+30:end);
//        std::cout << "-------------------------\n";
//        std::cout << "parsing failed\n";
//        std::cout << "stopped at: \": " << context << "...\"\n";
//        std::cout << "-------------------------\n";
//        return 1;
//    }
//}