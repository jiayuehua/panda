#include <iostream>
#include <vector>
int compute_array(int a[], int len, std::vector<int> & b)
{
	if (b[len-1])
	{
		return b[len-1];
	}
	if (len == 1)
	{
		return 0;
	}
	if (a[0] >= len-1)
	{
		return 1;
	}
	int step =  a[0];
	int min_s = len;
	for (int i = 0; i < step; ++i)
	{
		int m = compute_array(&a[i+1], len-1 -i, b); 
		if (m < min_s)
		{
			min_s = m;
		}
	}
	return b[len-1] = 1+min_s;
}

int compute_array_main()
{
	int a[] = {2,1,1,3,1,1,1};
	std::vector<int> b(sizeof(a)/ sizeof(int));
	std::cout<<compute_array(a, sizeof(a)/sizeof(int), b)<<"\n";
	return 0;
}