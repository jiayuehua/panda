#include <boost/spirit/include/karma.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>

#include <list>
#include <string>
#include <iostream>
#include <complex>
#include <boost/assign.hpp>
#include <boost/ref.hpp>
template<class OutIt>
void generator_numbers2(OutIt oi, const std::list<double> &dl)
{
	using boost::spirit::karma::double_;
	using boost::spirit::ascii::space;
	boost::spirit::karma::generate(oi,double_%",", dl);
}
template<class OutIt>
void generator_numbers(OutIt oi, const std::list<double> &dl)
{
	using boost::spirit::karma::double_;
	using boost::spirit::ascii::space;
	boost::spirit::karma::generate_delimited(oi,double_<<*double_, space, dl);
}
void foo(double & d);
struct Foo{
	void operator()(double& d, boost::spirit::unused_type, boost::spirit::unused_type)const
	{
		d = 1000;
	}
};
template<class OutIt>
void generator_num(OutIt oi)
{
	using boost::spirit::karma::double_;
	using boost::spirit::ascii::space;
	//boost::spirit::karma::generate(oi,double_[&foo]);
	boost::spirit::karma::generate(oi,double_[Foo()]);
}
template<class OutIt>
void generator_complex(OutIt oi, std::complex<double> c)
{
	using boost::spirit::karma::double_;
	using boost::spirit::karma::eps;
	using boost::spirit::karma::omit;
	using boost::spirit::karma::_1;
	using boost::spirit::ascii::space;
	boost::spirit::karma::generate(oi, !(double_(0.0))<<double_<<" "<<double_|omit[double_]<<double_,c.imag(),c.real(),c.imag() );
}
void foo(double & d)
{
	d = 1.23456;
}

int main()
{
	using namespace boost::assign;
	std::list<double> sl;
	std::complex<double> c1(2.0,5.0);
	std::complex<double> c2(2.3,0);
	sl += 1,3,44.33;
	std::string s;
	std::string s1;
	std::string s2;
	std::string s3;

	generator_numbers2(std::back_inserter(s), sl);
	std::cout<<s<<"\n";
	std::cout<<"\n------------\n";
	s.clear();
	generator_numbers(std::back_inserter(s), sl);
	generator_num(std::back_inserter(s1) );
	generator_complex(std::back_inserter(s2),c1);
	generator_complex(std::back_inserter(s3),c2);
	std::cout<<s<<"\n";
	std::cout<<s1<<"\n";
	std::cout<<s2<<"\n";
	std::cout<<s3<<"\n";
	std::cout<<s2<<"\n";
	std::cout<<s3<<"\n";
}