#include <iostream>
#include <vector>
#include <boost/assign.hpp>
using namespace boost::assign;
template <class It>
struct Range{
    It b;
    It e;
	int sum;
};
template <class It>
Range<It> subrange_max(It b, It e)
{
    Range<It> r1,r2;
    r1.b = r1.e = b;
    if (b == e)
    {
        return r1;
    }
    r1.sum = *b;
    r2 = r1;
    if (++b == e)
    {
        return r1;
    }
	for (; b != e; ++b)
	{
		if ( r2.sum <0 )
		{
            r2.b =  b;
            r2.sum = *b;
		}
        else 
        {
            r2.sum += *b;
        }
        r2.e = b;
        if (r2.sum > r1.sum)
        {
            r1 = r2;
        }
	}
    ++r1.e;
    return r1;
}
int main()
{
    typedef std::vector<int>::iterator It1;
    std::vector<int> v;
    v += 1, 2, 3, -1, -1, 2, 3, 5;
    Range<It1> r = subrange_max(v.begin(), v.end());
    std::cout<<r.b-v.begin()<<" "
        <<r.e - v.begin()<<" "
        <<r.sum<<std::endl;
}