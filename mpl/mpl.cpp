#include <boost/mpl/or.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/next.hpp>
#include <iostream>
#include <loki/Sequence.h>
namespace mympl = boost::mpl;

template <bool x>
struct Bool1_
{
	static const bool value = x;
	BOOST_STATIC_ASSERT((true));
	typedef Bool1_<x> type;
	operator bool(){return x;}
};

template <bool x>
struct Bool2_
{
	static const bool value = x;
	BOOST_STATIC_ASSERT((true));
	typedef Bool2_<x> type;
	operator bool(){return x;}
};

template <bool x>
struct Bool3_
{
	static const bool value = x;
	BOOST_STATIC_ASSERT((true));
	typedef Bool3_<x> type;
	operator bool(){return x;}
};

template <bool x>
struct Bool4_
{
	static const bool value = x;
	BOOST_STATIC_ASSERT((true));
	typedef Bool4_<x> type;
	operator bool(){return x;}
};

template <bool x>
struct Bool5_
{
	static const bool value = x;
	BOOST_STATIC_ASSERT((false));
	typedef Bool5_<x> type;
	operator bool(){return x;}
};


template<bool L1, class R>
struct logical_or_impl{
	static const bool value = true;
};

template<class R>
struct logical_or_impl<false, R>
{
	static const bool value = R::value;
};

template <class T>
struct logical_or_impl_by_seq;

template <class T1, class T2>
struct logical_or_impl_by_seq< Loki::Seq<T1, T2> >
{
	static const bool value = logical_or_impl<T1::value,T2>::value;
};

template <class T1, class T2, class T3>
struct logical_or_impl_by_seq< Loki::Seq<T1, T2, T3> >
{
	static const bool value = logical_or_impl<T1::value ,logical_or_impl_by_seq<Loki::Seq<T2,T3> > >::value;
};

template <class T1, class T2, class T3, class T4>
struct logical_or_impl_by_seq< Loki::Seq<T1, T2, T3, T4> >
{
	static const bool value = logical_or_impl<T1::value ,logical_or_impl_by_seq<Loki::Seq<T2,T3, T4 > > >::value;
};

template <class T1, class T2, class T3, class T4, class T5>
struct logical_or_impl_by_seq< Loki::Seq<T1, T2, T3, T4, T5> >
{
	static const bool value = logical_or_impl<T1::value ,logical_or_impl_by_seq<Loki::Seq<T2, T3, T4, T5> > >::value;
};

template<class T1, class T2, class T3 = Loki::NullType, class T4 = Loki::NullType, class T5 = Loki::NullType>
struct logical_or
{
	typedef logical_or<T1, T2,T3,T4,T5> type;
	static const bool value = logical_or_impl_by_seq<Loki::Seq<T1,T2,T3,T4,T5> >::value;
};

template<bool L1, class R>
struct logical_and_impl
{
	static const bool value = false;
};

template<class R>
struct logical_and_impl<true, R>
{
	static const bool value = R::value;
};

template <class T>
struct logical_and_impl_by_seq;

template <class T1, class T2>
struct logical_and_impl_by_seq< Loki::Seq<T1, T2> >
{
	static const bool value = logical_and_impl<T1::value,T2>::value;
};

template <class T1, class T2, class T3>
struct logical_and_impl_by_seq< Loki::Seq<T1, T2, T3> >
{
	static const bool value = logical_and_impl<T1::value ,logical_and_impl_by_seq< Loki::Seq<T2,T3> > >::value;
};

template <class T1, class T2, class T3, class T4>
struct logical_and_impl_by_seq< Loki::Seq<T1, T2, T3, T4> >
{
	static const bool value = logical_and_impl<T1::value ,logical_and_impl_by_seq< Loki::Seq<T2,T3, T4 > > >::value;
};

template <class T1, class T2, class T3, class T4, class T5>
struct logical_and_impl_by_seq< Loki::Seq<T1, T2, T3, T4, T5> >
{
	static const bool value = logical_and_impl<T1::value ,logical_and_impl_by_seq< Loki::Seq<T2, T3, T4, T5> >  >::value;
};

template<class T1, class T2, class T3 = Loki::NullType, class T4 = Loki::NullType, class T5 = Loki::NullType>
struct logical_and
{
	typedef logical_and<T1, T2,T3,T4,T5> type;
	static const bool value = logical_and_impl_by_seq<Loki::Seq<T1,T2,T3,T4,T5> >::value;
};

int logical_and_main()
{
	std::cout<<logical_and<
		Bool1_<true>, 
		Bool2_<false> >::value<<std::endl;
	std::cout<<logical_or<
		Bool1_<true>, 
		Bool2_<true> >::value<<std::endl;
	std::cout<<logical_and<
		Bool1_<true>, 
		Bool2_<true>, 
		Bool3_<true>, 
		Bool4_<false>, 
		Bool5_<false> >::value<<std::endl;
	std::cout<<logical_or<
		Bool1_<false>, 
		Bool2_<false>, 
		Bool3_<false>, 
		Bool4_<true>, 
		Bool5_<true> >::value<<std::endl;
	return 0;
}