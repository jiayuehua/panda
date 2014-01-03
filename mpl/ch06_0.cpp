#include <boost/mpl/vector.hpp>
#include <boost/mpl/copy.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/sizeof.hpp>
#include <boost/mpl/inserter.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/less.hpp>
#include <loki/NullType.h>
#include <iostream>
namespace mpl = boost::mpl;
using namespace mpl::placeholders;

template <class Prev, class Element>
struct SmallType:mpl::if_<
	typename mpl::less<
		mpl::sizeof_<Element>,
		mpl::sizeof_<typename Prev::type>
	>::type,
	mpl::identity<Element>,
	Prev
>
{ };

template <class Seq>
struct smallest:mpl::copy<Seq,  mpl::inserter< mpl::identity<typename mpl::front<Seq>::type>, SmallType<_,_> > >::type
{ 

};
int main()
{
	std::cout<<boost::is_same<char, smallest<mpl::vector<int,char,double> >::type >::value<<std::endl;
}

