/*=============================================================================
    Copyright (c) 2001-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
///////////////////////////////////////////////////////////////////////////////
//
//  A Roman Numerals Parser (demonstrating the symbol table). This is
//  discussed in the "Symbols" chapter in the Spirit User's Guide.
//
//  [ JDG August 22, 2002 ] spirit1
//  [ JDG March 13, 2007 ]  spirit2
//
///////////////////////////////////////////////////////////////////////////////

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>

#include <iostream>
#include <string>

    namespace qi = boost::spirit::qi;
    namespace ascii = boost::spirit::ascii;
	//struct BINNUM :qi::symbols<char,int>
	//{
	//	
	//	BINNUM()
	//	{
	//		add("0",0);
	//		add("1",1);
	//	}
	//}binnum;
	//struct OCTNUM :qi::symbols<char,int>
	//{
	//	
	//	OCTNUM()
	//	{
	//		add("0",0);
	//		add("1",1);
	//		add("2",2);
	//		add("3",3);
	//		add("4",4);
	//		add("5",5);
	//		add("6",6);
	//		add("7",7);
	//	}
	//}octnum;
	struct HEXNUM :qi::symbols<char,int>
	{
		
		HEXNUM()
		{
			add("0",0);
			add("1",1);
			add("2",2);
			add("3",3);
			add("4",4);
			add("5",5);
			add("6",6);
			add("7",7);
			add("8",8);
			add("9",9);
			add("a",10);
			add("A",10);
			add("b",11);
			add("B",11);
			add("c",12);
			add("C",12);
			add("d",13);
			add("D",13);
			add("e",14);
			add("E",14);
			add("f",15);
			add("F",15);
		}
	}hexnum;
	template<class Iter>
	class Grama:public qi::grammar<Iter, int()>
	{
	public:
		Grama():Grama::base_type(hexrule){
			using qi::_val;
			using qi::_1;
			using qi::eps;
			using qi::lit;
			using qi::char_;

			hexrule = (lit("0x")[_val=1]|lit("0X")[_val=0])>> 
					hexnum[_val=_1]>>*(hexnum [_val = 16*_val+_1] );
		/*	octrule = (*char_('0'))[_val=0]||
					octnum[_val=_1]>>*(octnum [_val = 8*_val+_1] );
			binrule = (char_('b'))[_val=0]>>
					binnum[_val=_1]>>*(binnum [_val = 2*_val+_1] );
			numrule = octrule|binrule|hexrule;*/
			//numrule = binrule|octrule;
		}
	private:
		qi::rule<Iter, int()> hexrule;
		//qi::rule<Iter, int()> octrule;
		//qi::rule<Iter, int()> numrule;
		//qi::rule<Iter, int()> binrule;
	};


int
main()
{
    std::cout << "/////////////////////////////////////////////////////////\n\n";
    std::cout << "\t\tHex,OCT,BINARY Numerals Parser\n\n";
    std::cout << "/////////////////////////////////////////////////////////\n\n";
    std::cout << "Type a Hex,OCT,BINARY  Numeral ...or [q or Q] to quit\n\n";

    typedef std::string::const_iterator iterator_type;
    typedef Grama<iterator_type> GRAMA;

	GRAMA grama;

    std::string str;
    unsigned result;
    while (std::getline(std::cin, str))
    {
        if (str.empty() || str[0] == 'q' || str[0] == 'Q')
            break;

        std::string::const_iterator iter = str.begin();
        std::string::const_iterator end = str.end();
        //[tutorial_roman_grammar_parse
        bool r = parse(iter, end, grama, result);

        if (r && iter == end)
        {
            std::cout << "-------------------------\n";
            std::cout << "Parsing succeeded\n";
            std::cout << "result = " << result << std::endl;
            std::cout << "-------------------------\n";
        }
        else
        {
            std::string rest(iter, end);
            std::cout << "-------------------------\n";
            std::cout << "Parsing failed\n";
            std::cout << "stopped at: \": " << rest << "\"\n";
            std::cout << "-------------------------\n";
        }
        //]
    }

    std::cout << "Bye... :-) \n\n";
    return 0;
}


