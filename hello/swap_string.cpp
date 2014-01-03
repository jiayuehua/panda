#include <iostream>
#include <algorithm>
void swap_char(char &a, char&b)
{
	a -= b;
	b += a;
	a = b-a;
}
void swap(char* str)
{
	int i = -1;
	while (*(str + ++i)){;}
	std::cout<<i<<std::endl;
	if(i%2 == 0)
	{
		i /= 2;
		str = str+i;
		for (i = 0;*(str+i);++i)
		{
			swap_char(*(str+i), *(str-1-i));
		}
	}
	else
	{
		i /= 2;
		i += 1;
		str = str+i;
		for (i = 0;*(str+i);++i)
		{
			//std::swap(*(str+i), *(str-2-i));
			swap_char(*(str+i), *(str-2-i));
		}
	}
}
int swap_string_main()
{
	char a[] = "hello,world";
	swap(a);
	std::cout<<a;
	return 0;
}