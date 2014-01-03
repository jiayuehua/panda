#include <iostream>
#include <cmath>
#include <vector>
#include <iterator>
#include <map>
bool is_prime(int n)
{
	int t = std::sqrt(double(n));
	for (int i = 2; i <= t; ++i)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}

class Next_prime
{
	int find_next_prime()
	{
		++low_;
		for (int i = low_; ; ++i)
		{
			if (is_prime(i))
			{
				return i;
			}
		}
		return low_;
	}
	int low_;
public:
	Next_prime():low_(1){}
	int operator++()
	{
		return find_next_prime();
	}
};

void prime_vec(int num, std::vector<int>* res)
{
	Next_prime np;
	while (num != 1)
	{
		int t = ++np;
		while (!(num%t))
		{
			res->push_back(t);
			num /= t;
		}
	}
}

int prime_main()
{
	int n;
	while ( (std::cout<<"> "<<std::flush )&& (std::cin>>n) )
	{
		std::vector<int> v;
		prime_vec(n, &v);
		std::ostream_iterator<int> os(std::cout, " ");
		std::copy(v.begin(), v.end(), os);
		std::cout<<"\n";
		std::map<int, int> m;
		for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
		{
			++m[*i];
		}
		for (std::map<int, int>::iterator i = m.begin(); i!= m.end(); ++i)
		{
			std::cout<<"{"<<i->first<<", "<<i->second<<"} ";
		}
		std::cout<<"\n";
	}
    return 0;
}