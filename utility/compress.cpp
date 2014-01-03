#include <boost/lexical_cast.hpp>
#include <string>
#include <iostream>
#include <cstring>
std::string compress(const char* src)
{
	std::string res;
	int len = std::strlen(src);
	if (len)
	{
		char c = src[0];
		int sublen = 1;
		for (int i = 1; i<len+1; ++i)
		{
			if (src[i] == c)
			{
				++sublen;
			} 
			else
			{
				if (sublen>1)
				{
					res += boost::lexical_cast<std::string>(sublen);
				}
				res += c;
				sublen = 1;
				c = src[i];
			}
		}
	}
	return res;
}

int compress_main()
{
	const char* str = ("aaabcccccccccccccddd");
	std::cout<<compress(str)<<std::endl;
	return 0;
}