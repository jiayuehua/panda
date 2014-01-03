template<class RanIt, class T>
RanIt binary_search_rotate(RanIt b, RanIt e, T t)
{
	RanIt low = b;
	RanIt high = e-1;
	RanIt mid = e-1;
	while (low <= high)
	{
		RanIt mid = low + (high - low)/2;//因为迭代器间不能相加，所以不能写成(low+high)/2;
		if (*mid == t )
		{
			return mid;
		}
		if (*low <= *mid)
		{
			if(t>=*low && t<*mid )
			{
				high = mid-1;
			}
			else 
			{
				low = mid +1;
			}
		}
		if( *mid <= *high)
		{
			if(t>*mid && t<=*high)
			{ 
				low = mid+1;
			} 
			else 
			{
				high = mid -1;
			}
		}
	}
	return e;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
int binary_search_rotate_main()
{
	int a[] = {4,5,6,7,8,9,10,0,1,2,3};
	std::deque<int> v(sizeof(a)/sizeof(int));
	std::copy(a, a+sizeof(a)/sizeof(int), v.begin());
	for (int i = 0; i<sizeof(a)/sizeof(int); ++i)
	{
		int *n1 = binary_search_rotate(a,a+sizeof(a)/sizeof(int),i);
		std::cout<<(n1-a)<<std::endl;
	}
	std::cout<<"coding so happy!\n";
	for (int i = 0; i<sizeof(a)/sizeof(int); ++i)
	{
		std::deque<int>::iterator it = binary_search_rotate(v.begin(),v.end(),i);
		std::cout<<(it - v.begin())<<std::endl;
	}
	return 0;
}