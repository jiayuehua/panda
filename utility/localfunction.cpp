
// Copyright (C) 2009-2012 Lorenzo Caminiti
// Distributed under the Boost Software License, Version 1.0
// (see accompanying file LICENSE_1_0.txt or a copy at
// http://www.boost.org/LICENSE_1_0.txt)
// Home at http://www.boost.org/libs/local_function


#include <boost/assign.hpp>
#include <boost/range.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/local_function.hpp>
#include <boost/detail/lightweight_test.hpp>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <boost/bind.hpp>
int localfunction_main(void) {                            // Some local scope.
	using namespace boost::assign;
	void BOOST_LOCAL_FUNCTION(void) {
	void BOOST_LOCAL_FUNCTION(void) {
	std::string s1("010");
	std::string s2("-000");
	std::string s3("-001");
	std::string s4("-011");
	std::vector<std::string> sv;
	sv+=s2,s3,s4;
	std::ostream_iterator<std::string> oi(std::cout,"\n");
	//boost::copy(sv, oi);
	//std::cout<<"-------------\n";
	} BOOST_LOCAL_FUNCTION_NAME(print_phone_number2)
	print_phone_number2();
	print_phone_number2();
	print_phone_number2();
	print_phone_number2();
	print_phone_number2();

	std::string s1("010");
	std::string s2("-000");
	std::string s3("-001");
	std::string s4("-011");
	std::vector<std::string> sv;
	sv+=s2,s3,s4;
	void BOOST_LOCAL_FUNCTION( std::string s1,  std::string str1) {
		std::cout<<s1+str1<<std::endl;
	} BOOST_LOCAL_FUNCTION_NAME(print_phone)
	void BOOST_LOCAL_FUNCTION(const bind & s1, const std::string& str1) {
		//std::cout<<s1+str1<<std::endl;
	} BOOST_LOCAL_FUNCTION_NAME(print_phone_number)
	boost::for_each(sv, print_phone_number);     // Pass it to an algorithm.
	boost::for_each(sv, boost::bind(print_phone, "hello", _1 ));     // Pass it to an algorithm.
	} BOOST_LOCAL_FUNCTION_NAME(print_phone_number3)
		print_phone_number3();
		print_phone_number3();
		print_phone_number3();
	return 0;
}
//]
