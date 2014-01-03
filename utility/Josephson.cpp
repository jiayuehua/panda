#include <iostream>
#include <map>
#include <iterator>
#include <utility>
int josephson_cycle(bool a[], int len, int start, int out)
{
	int l = len;
	start = (start-1)%len;
	std::ostream_iterator<int> oit(std::cout," ");
	while (l>0)
	{
		int out1 = out%l;
		if (out1 == 0)
		{
			out1 = l;
		}
		for (int i = 0; i<out1;)
		{
			start = (start+1)%len;
			if (a[start] == 1)
			{
				++i;
			}
		}
		a[start] = 0;
		--l;
		std::copy(a, a+len,oit);
		std::cout<<"\n";
	}
	return start;
}

int josephson_main()
{
	bool a[] = {1,1,1,1,1,1,1,1,1,1};
	std::cout<<josephson_cycle(a,sizeof(a)/sizeof(bool), 2, 3)<<std::endl;
	return 0;
}
class A{
public:
	A(const A&)
	{
		std::cout<<"A copy\n";
	}
	A(){}
	bool operator<(const A&)const
	{
		return false;
	}
};
class B{
public:
	B(const B&)
	{
		std::cout<<"B copy\n";
	}
	B(){}
};
int josephson_main1()
{
	const A& ww = A();
	std::map<A,B> m;
	m.insert(std::make_pair(A(), B()));
	return 0;

}