#include <string>
#include <iostream>
#include <boost/fusion/include/algorithm.hpp>
#include <boost/fusion/include/sequence.hpp>

#include <boost/fusion/container/map.hpp>
#include <boost/fusion/include/map.hpp>
#include <boost/fusion/container/set.hpp>
#include <boost/fusion/include/set.hpp>
#include <boost/fusion/container/set/set_fwd.hpp>
#include <boost/fusion/include/set_fwd.hpp>

#include <boost/fusion/adapted/struct/adapt_struct_named.hpp>
#include <boost/fusion/include/adapt_struct_named.hpp>
#include <boost/ref.hpp>
#include <boost/fusion/iterator/deref_data.hpp>
#include <boost/fusion/include/deref_data.hpp>
#include <boost/fusion/adapted/struct/adapt_struct.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
struct print_xml
{
	template <class T>
	void operator()(const T& x)const
	{
		//std::cout<<typeid(x).name()<<": "<<x<<std::endl;
	}
};
namespace fields{
	struct name;
	struct age;
}
struct saver{
	template <class T>
	void operator()(T t)const{
		std::cout<<t.second<<" ";
	}
};
struct saver2{
	template <class T>
	void operator()(T t)const{
		std::cout<<t<<" ";
	}
};
template < class T>
void save(const T& t)
{
	boost::fusion::for_each(t, saver());
}
template < class T>
void save2(const T& t)
{
	boost::fusion::for_each(t, saver2());
}
struct employee
{
	std::string name;
	int age;
};

BOOST_FUSION_ADAPT_STRUCT(
employee,
(std::string, name)
(int, age))
int my_fusion_main()
{
	namespace fusion = boost::fusion;
	typedef fusion::map<
		fusion::pair<fields::name, std::string>
		, fusion::pair<fields::age, int> >
		person;
	using namespace fields;
	person a_person(fusion::make_pair<name>(std::string("world")),fusion::make_pair<age>(345));
	std::cout<<"**"<<*fusion::begin(a_person)<<std::endl;
	std::cout<<"*--- "<<fusion::deref(fusion::begin(a_person))<<std::endl;
	std::cout<<"*--*"<<fusion::deref_data(fusion::begin(a_person))<<std::endl;
	employee e;
	fusion::at_c<0>(e) = "aho";
	fusion::at_c<1>(e) = 1234;


	//save2(e);
	//std::cout<<fusion::at_c<0>(e);
	std::cout<<"\n-------------\n";
	std::string person_name = fusion::at_key<name>(a_person);
	int person_age = fusion::at_key<age>(a_person);
	//save(a_person);
	//fusion::for_each(a_person, saver<std::ostream>(std::cout));
	fusion::vector<int,double,std::string> f1(100,2.45, "world");
	//fusion::for_each(f1,print_xml());
	typedef fusion::set<int,float> S;
	S s(12,5.5f);
	//std::cout<<fusion::at_key<int>(s)<<std::endl;
	//std::cout<<fusion::has_key<double>(s)<<std::endl;
	return 0;
}