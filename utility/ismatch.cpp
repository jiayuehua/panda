#include <string>
#include <iosfwd>
#include <iostream>
#include <stack>

#include <map>
#include <boost/bimap/bimap.hpp>

using namespace boost::bimaps;

typedef bimap< set_of<char>, set_of<char> > bimap_type;
bool is_match(std::string str, const bimap_type & bm )
{
	typedef bimap_type::left_map map_type;
	const	map_type & m = bm.left;

	typedef bimap_type::right_map reverse_map_type;
	const reverse_map_type & rm = bm.right;
	reverse_map_type::const_iterator ci;

	int sz = str.size();
	std::stack<char> s;
	for (int i = 0 ; i < sz; ++i)
	{
		if (m.find(str[i]) != m.end())
		{
			s.push(str[i]);
		}
		else if ( (ci = rm.find(str[i])) != rm.end() )
		{
			if (!s.empty()&&(s.top() == ci->second) )
			{
				s.pop();
			}
			else
			{
				return false;
			}
		}
	}
	return s.empty();
}

int is_match_main()
{
	bimap_type bm;
	typedef bimap_type::left_map map_type;
	map_type & m = bm.left;
	m.insert(std::make_pair('(',')'));
	m.insert(std::make_pair('[',']'));
	m.insert(std::make_pair('{','}'));
	
	std::string str ("{nihao[world<you>like]moon}");
	std::cout<<std::boolalpha<<is_match(str,bm)<<std::endl;
	return 0;
}