#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <algorithm>
void rotate(char *p, int len ,char * p1)
{
	for (int i = 0; i<len; ++i)
	{
		for (int j = 0; j<len; ++j)
		{
			*(p1 + j*len +   (len-1 -i) ) = *(p + i*len+j) ;
		}
	}
}
char calculate(const char *inputs)
{
	int len = std::strlen(inputs);
	int l = std::sqrt((double)len);
	if (l*l != len)
	{
		return 0;
	}
	int h = 0x1, v = 0x1<<1, r = 0x1<<2;
	for ( int i =0; h&&(i<l); ++i )
	{
		for (int j = 0;h&& (j<l/2); ++j)
		{
			if ( *( inputs+ i*l+j) != *( inputs + i*l + l-1 -j))
			{
				h = 0;
			}
		}
	}
	
	for (int j = 0;v&& (j<l); ++j)
	{
		for ( int i =0; v&&(i<l/2); ++i )
		{
			if ( *( inputs+ i*l+j) != *( inputs + (l-1-i)*l + j))
			{
				v = 0;
			}
		}
	}
	char * p1 = new char[len+1];
	char * p2 = new char[len+1];
	std::strcpy(p1,inputs);
	for (int k = 0; (k<3) &&r; ++k)
	{
		rotate(p1, l, p2 );
		if (std::strcmp(p1,p2) != 0)
		{
			r = 0;
		}
		std::swap(p1,p2);
	}
	delete []p1;
	delete []p2;
	return h|v|r;
}

static const char * testcases[] = {
	// All symmetries
	"ffffffff"
	"ffffffff"
	"ffffffff"
	"ffffffff"
	"ffffffff"
	"ffffffff"
	"ffffffff"
	"ffffffff" ,

	"tttttttt"
	"tttttttt"
	"tttttttt"
	"tttttttt"
	"tttttttt"
	"tttttttt"
	"tttttttt"
	"tttttttt" ,

	"tttttttt"
	"ffffffff"
	"tttttttt"
	"ffffffff"
	"ffffffff"
	"tttttttt"
	"ffffffff"
	"tttttttt" ,

	"tttttttt"
	"tfffffft"
	"tfffffft"
	"tfffffft"
	"tfffffft"
	"tfffffft"
	"tfffffft"
	"tttttttt" ,

	"tfffffft"
	"ftfffftf"
	"fftfftff"
	"fffttfff"
	"fffttfff"
	"fftfftff"
	"ftfffftf"
	"tfffffft" ,

	"fffttfff"
	"fftfftff"
	"ftfffftf"
	"tfffffft"
	"tfffffft"
	"ftfffftf"
	"fftfftff"
	"fffttfff" ,

	"fffttfff"
	"fffttfff"
	"fffttfff"
	"tttttttt"
	"tttttttt"
	"fffttfff"
	"fffttfff"
	"fffttfff" ,

	"ttfffftt"
	"ttfffftt"
	"ttfffftt"
	"tttttttt"
	"tttttttt"
	"ttfffftt"
	"ttfffftt"
	"ttfffftt" ,

	// Horizontal symmetry only
	"ffffffff"
	"ffffffff"
	"ffffffff"
	"ffffffff"
	"tttttttt"
	"tttttttt"
	"tttttttt"
	"tttttttt" ,

	"ttfffftt"
	"ttfffftt"
	"ffttttff"
	"ffttttff"
	"ttfffftt"
	"ttfffftt"
	"ffttttff"
	"ffttttff" ,

	"tttttttt"
	"fttttttf"
	"ffttttff"
	"fffttfff"
	"tfffffft"
	"ttfffftt"
	"tttffttt"
	"tttttttt" ,

	"tfffffft"
	"ftfffftf"
	"fftfftff"
	"fffttfff"
	"tfffffft"
	"ftfffftf"
	"fftfftff"
	"fffttfff" ,

	"ttfffftt"
	"ttfffftt"
	"fttffttf"
	"fttffttf"
	"ffttttff"
	"ffttttff"
	"fffttfff"
	"fffttfff" ,

	"tfffffft"
	"ttfffftt"
	"fttffttf"
	"ffttttff"
	"fffttfff"
	"fffttfff"
	"fffttfff"
	"fffttfff" ,

	"ffttttff"
	"fttffttf"
	"fttffttf"
	"ffttttff"
	"fttttttf"
	"ttfffftt"
	"ttfffftt"
	"ffttttff" ,

	"fffttfff"
	"ffttttff"
	"fttffttf"
	"ttfffftt"
	"tttttttt"
	"tttttttt"
	"ttfffftt"
	"ttfffftt" ,

	// Vertical symmetry only
	"ttttffff"
	"ttttffff"
	"ttttffff"
	"ttttffff"
	"ttttffff"
	"ttttffff"
	"ttttffff"
	"ttttffff" ,

	"ttffttff"
	"ttffttff"
	"ffttfftt"
	"ffttfftt"
	"ffttfftt"
	"ffttfftt"
	"ttffttff"
	"ttffttff" ,

	"fffffftt"
	"ffffttff"
	"ffttffff"
	"ttffffff"
	"ttffffff"
	"ffttffff"
	"ffffttff"
	"fffffftt" ,

	"tttttttt"
	"tttttttf"
	"ttttttff"
	"ffffffff"
	"ffffffff"
	"ttttttff"
	"tttttttf"
	"tttttttt" ,

	"ffttttff"
	"fttttttf"
	"ttfffftt"
	"ttffffff"
	"ttffffff"
	"ttfffftt"
	"fttttttf"
	"ffttttff" ,

	"ttttffff"
	"ttttttff"
	"ttfffttf"
	"ttfffftt"
	"ttfffftt"
	"ttfffttf"
	"ttttttff"
	"ttttffff" ,

	"tttttttt"
	"tttttttt"
	"ttffffff"
	"tttttttt"
	"tttttttt"
	"ttffffff"
	"tttttttt"
	"tttttttt" ,

	"ttttttff"
	"ttfffftt"
	"ttfffftt"
	"ttttttff"
	"ttttttff"
	"ttfffftt"
	"ttfffftt"
	"ttttttff" ,

	// No symmetry
	"ttttffff"
	"ttttffff"
	"ttttffff"
	"ttttffff"
	"ffffffff"
	"ffffffff"
	"ffffffff"
	"ffffffff" ,

	"ftffffff"
	"ffffffff"
	"ffffffff"
	"ffffffff"
	"ffffffff"
	"ffffffff"
	"ffffffff"
	"ffffffff" ,

	"ftffffff"
	"tffffttf"
	"ftfffttf"
	"tfffffff"
	"ftttffff"
	"fffttttf"
	"fffffttf"
	"tffftttf" ,

	"ttfffttf"
	"ffttffft"
	"tfffttff"
	"fttffftt"
	"fffttfff"
	"ttfffttf"
	"ffttffft"
	"tfffttff" ,

	"tttttttt"
	"tttttttt"
	"fffffttf"
	"ffffttff"
	"fffttfff"
	"ffttffff"
	"fttfffff"
	"ttffffff" ,

	"tttttttt"
	"tttttttt"
	"ttffffff"
	"tttttttt"
	"tttttttt"
	"ttffffff"
	"ttffffff"
	"ttffffff" ,

	"ffttttff"
	"fttttttf"
	"ttfffftt"
	"ttffffff"
	"ttfftttt"
	"ttffffft"
	"tttttttf"
	"ffttttff" ,

	"fffffftt"
	"fffffftt"
	"fffffftt"
	"fffffftt"
	"fffffftt"
	"ttfffftt"
	"fttffttf"
	"ffttttff" };

int sm_main()
{
	enum{ H = 0x1, V = 0x1<<1, R = 0x1<<2};
	std::ofstream ofs("ofs.txt");

	for (int i1 = 0; i1< sizeof(testcases)/sizeof(const char*); ++i1)
	{	
		for (int i = 0; i<8; ++i)
		{
			for (int j = 0; j<8; ++j)
			{
				ofs<<*(testcases[i1]+i*8+j);
			}
			ofs<<std::endl;
		}
		ofs<<i1<<std::endl;
		int r = calculate(testcases[i1]);
		
		if (r&H)
		{
			ofs<<"H";
		}
		else
		{
			ofs<<"-";
		}
		if (r&V)
		{
			ofs<<"V";
		}
		else
		{
			ofs<<"-";
		}
		if (r&R)
		{
			ofs<<"R";
		}
		else
		{
			ofs<<"-";
		}
		ofs<<std::endl;
		ofs<<std::endl;
		ofs<<std::endl;

	}
	return 0;
}