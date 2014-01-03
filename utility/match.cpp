#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
std::list<std::string> match_b(int n)
{
	std::list<std::string> res;
	if (n == 0)
	{
		res.push_back(std::string());
	}
	else if (n == 1)
	{
		res.push_back(std::string("()"));
	}
	else
	{
		for (int i = 0; i<n; ++i)
		{
			std::list<std::string> lstrs = match_b(i);
			std::list<std::string> rstrs = match_b(n-1 -i);
			for (std::list<std::string>::iterator it = lstrs.begin(); it != lstrs.end(); ++it)
			{
				std::string lstr = "("+ *it + ")";
				for(std::list<std::string>::iterator it2 = rstrs.begin(); it2 != rstrs.end(); ++it2)
				{
					res.push_back(lstr + *it2);
				}
			}
		}
	}
	return res;
}
int match_main()
{
	int i;
	for (;;)
	{
		std::cin>>i;
		if (i == -1)
		{
			break;
		}
		std::list<std::string> strs = match_b(i);
		std::copy(strs.begin(), strs.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	}
	return 0;
}