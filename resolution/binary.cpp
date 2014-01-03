#include <boost/static_assert.hpp>
template< unsigned long N>
class binary
{
public:
	BOOST_STATIC_ASSERT((N%10>=0||N%10<=1));
	enum{value = binary<N/10>::value*2 + N%10 };
};
template<>
class binary<0>
{
public:
	enum{value = 0};
};

#include <iostream>
int binary_main()
{
	std::cout<<binary<100>::value<<std::endl;
	return 0;
}