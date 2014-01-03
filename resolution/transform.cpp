#include <boost/mpl/transform.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/multiplies.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/type_traits.hpp>
#include <boost/static_assert.hpp>
struct plus_f{
	template<class T1, class T2>
	struct apply:public boost::mpl::plus<T1,T2>
	{
	};
};
struct mul_f{
	template<class T1, class T2>
	struct apply:public boost::mpl::multiplies<T1,T2>
	{
	};
};

template <class F, class Arg>
struct Twice{
	typedef typename F::template apply<Arg>::type T1;
	typedef typename F::template apply<T1 >::type type;
};

template <class F, class Arg>
struct Once:public F::template apply<Arg>{
};
template<class F, class Arg>
struct Twice2:public Once<F,typename Once<F,Arg>::type>{
};

struct add_pointer_f{
	template <class T>
	struct apply:public boost::add_pointer<T>
	{
	};
};

template<class F, class T>
struct ONCE:public F::template apply<T> {

};
template<class F, class T>
struct TWICE:ONCE<F, typename ONCE<F,T>::type>
{

};

int transform_main()
{
	typedef boost::add_pointer<double> B;
	B b;
//	b.type;
	typedef boost::add_pointer<double&> A;
	boost::add_pointer<double&> a;
	//typedef boost::add_pointer<double&>::type A;

	typedef boost::mpl::transform<boost::mpl::vector_c <int,1,2,3>, boost::mpl::vector_c<int,1,1,1>,plus_f>::type Type1;
	typedef boost::mpl::transform<boost::mpl::vector_c <int,1,2,3>, boost::mpl::vector_c<int,1,2,3>,mul_f>::type Type2;
	BOOST_STATIC_ASSERT((boost::mpl::equal<Type1, boost::mpl::vector_c<int,2,3,4> >::type::value));
	BOOST_STATIC_ASSERT((boost::mpl::equal<Type2, boost::mpl::vector_c<int,1,4,9> >::type::value));
	BOOST_STATIC_ASSERT((boost::is_same<int**, Twice2<add_pointer_f,int>::type>::type::value));
	BOOST_STATIC_ASSERT((boost::is_same<int****, Twice2<add_pointer_f, Twice2<add_pointer_f,int>::type>::type>::type::value));
	return 0;
	//BOOST_STATIC_ASSERT((boost::is_same<int**,Twice2<add_pointer_f,int> >::type::value));
}
