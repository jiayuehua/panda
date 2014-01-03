#include <boost/type_traits.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/prior.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/clear.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/pop_back.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/insert_range.hpp>
#include <boost/mpl/erase.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/advance.hpp>
#include <boost/mpl/distance.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/iterator_tags.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/vector.hpp>
#include <loki/NullType.h>

#include <iostream>

namespace mpl = boost::mpl;
template <class T1 = Loki::NullType, class T2 = Loki::NullType, class T3 = Loki::NullType>
struct tree{};

struct preorder_view_tag{};

template <class T>
struct postorder_view;

template <class T1, class T2, class T3>
struct postorder_view<tree <T1, T2, T3> >
{
	typedef preorder_view_tag tag; 
	typedef mpl::vector<T2, T3, T1> type;
};

template <class T1,  class T3, class T2_1, class T2_2, class T2_3>
struct postorder_view<tree <T1, tree<T2_1, T2_2, T2_3 > ,T3> >
{
	typedef preorder_view_tag tag;
	typedef typename postorder_view<tree<T2_1, T2_2, T2_3 > >::type v1;
	typedef typename mpl::insert<v1, typename  mpl::end<v1>::type, T3>::type v12;
	typedef typename mpl::insert<v12, typename mpl::end<v12>::type, T1>::type type;
};

template <class T1,  class T2, class T3_1, class T3_2, class T3_3>
struct postorder_view<tree <T1, T2, tree<T3_1, T3_2, T3_3 > > >
{
	typedef preorder_view_tag tag;
	typedef mpl::vector< T2> v1;
	typedef typename postorder_view<tree<T3_1, T3_2, T3_3 > >::type v2;
	typedef typename mpl::insert_range<v1, typename mpl::end<v1>::type, v2>::type v12;
	typedef typename mpl::insert<v12, typename mpl::end<v12>::type, T1>::type type;
};

template <class T1, class T2_1, class T2_2, class T2_3, class T3_1, class T3_2, class T3_3>
struct postorder_view<tree <T1,tree<T2_1, T2_2, T2_3 > , tree<T3_1, T3_2, T3_3 > > >
{
	typedef preorder_view_tag tag;
	typedef typename postorder_view<tree<T2_1, T2_2, T2_3 > >::type v1;
	typedef typename postorder_view<tree<T3_1, T3_2, T3_3 > >::type v2;
	typedef typename mpl::insert_range<v1, typename mpl::end<v1>::type, v2>::type v12;
	typedef typename mpl::insert<v12, typename mpl::end<v12>::type, T1>::type type;
};

template <class T>
struct cenorder_view;

template <class T1, class T2, class T3>
struct cenorder_view<tree <T1, T2, T3> >
{
	typedef preorder_view_tag tag; 
	typedef mpl::vector<T2, T1, T3> type;
};

template <class T1,  class T3, class T2_1, class T2_2, class T2_3>
struct cenorder_view<tree <T1, tree<T2_1, T2_2, T2_3 > ,T3> >
{
	typedef preorder_view_tag tag;
	typedef typename cenorder_view<tree<T2_1, T2_2, T2_3 > >::type v1;
	typedef mpl::vector<T1> v2;
	typedef typename mpl::insert_range<v1, typename  mpl::end<v1>::type, v2>::type v12;
	typedef typename mpl::insert<v12, typename mpl::end<v12>::type, T3>::type type;
};

template <class T1,  class T2, class T3_1, class T3_2, class T3_3>
struct cenorder_view<tree <T1, T2, tree<T3_1, T3_2, T3_3 > > >
{
	typedef preorder_view_tag tag;
	typedef mpl::vector<T2, T1> v12;
	typedef typename cenorder_view<tree<T3_1, T3_2, T3_3 > >::type v3;
	typedef typename mpl::insert_range<v12, typename mpl::end<v12>::type, v3>::type type;
};

template <class T1, class T2_1, class T2_2, class T2_3, class T3_1, class T3_2, class T3_3>
struct cenorder_view<tree <T1,tree<T2_1, T2_2, T2_3 > , tree<T3_1, T3_2, T3_3 > > >
{
	typedef preorder_view_tag tag;
	typedef typename cenorder_view<tree<T2_1, T2_2, T2_3 > >::type v1;
	typedef mpl::vector<T1> v2;
	typedef typename cenorder_view<tree<T3_1, T3_2, T3_3 > >::type v3;
	typedef typename mpl::insert_range<v1, typename mpl::end<v1>::type, v2>::type v12;
	typedef typename mpl::insert_range<v12, typename mpl::end<v12>::type, v3>::type type;
};

template <class T>
struct preorder_view;

template <class T1, class T2, class T3>
struct preorder_view<tree <T1, T2, T3> >
{
	typedef preorder_view_tag tag; 
	typedef mpl::vector<T1, T2, T3> type;
};

template <class T1,  class T3, class T2_1, class T2_2, class T2_3>
struct preorder_view<tree <T1, tree<T2_1, T2_2, T2_3 > ,T3> >
{
	typedef preorder_view_tag tag;
	typedef mpl::vector<T1> v1;
	typedef typename preorder_view<tree<T2_1, T2_2, T2_3 > >::type v2;
	typedef typename mpl::insert_range<v1, typename  mpl::end<v1>::type, v2>::type v12;
	typedef typename mpl::insert<v12, typename mpl::end<v12>::type, T3>::type type;
};

template <class T1,  class T2, class T3_1, class T3_2, class T3_3>
struct preorder_view<tree <T1, T2, tree<T3_1, T3_2, T3_3 > > >
{
	typedef preorder_view_tag tag;
	typedef mpl::vector<T1, T2> v12;
	typedef typename preorder_view<tree<T3_1, T3_2, T3_3 > >::type v3;
	typedef typename mpl::insert_range<v12, typename mpl::end<v12>::type, v3>::type type;
};

template <class T1, class T2_1, class T2_2, class T2_3, class T3_1, class T3_2, class T3_3>
struct preorder_view<tree <T1,tree<T2_1, T2_2, T2_3 > , tree<T3_1, T3_2, T3_3 > > >
{
	typedef preorder_view_tag tag;
	typedef mpl::vector<T1> v1;
	typedef typename preorder_view<tree<T2_1, T2_2, T2_3 > >::type v2;
	typedef typename preorder_view<tree<T3_1, T3_2, T3_3 > >::type v3;
	typedef typename mpl::insert_range<v1, typename mpl::end<v1>::type, v2>::type v12;
	typedef typename mpl::insert_range<v12, typename mpl::end<v12>::type, v3>::type type;
};

namespace boost{
	namespace mpl{

		template<>
		struct end_impl<preorder_view_tag>
		{
			template <class Sequence>
			struct apply
			{
				typedef typename end<typename Sequence::type >::type type;
			};
		};

		template<>
		struct at_impl<preorder_view_tag >
		{
			template <class Sequence, class N>
			struct apply
			{
				typedef typename at<typename Sequence::type,N>::type   type;
			};
		};

		template<>
		struct size_impl<preorder_view_tag>
		{
			template <class Sequence>
			struct apply
			{
				typedef typename size<typename Sequence::type>::type   type;
			};
		};

		template<>
		struct begin_impl<preorder_view_tag>
		{
			template <class Sequence>
			struct apply
			{
				typedef typename begin<typename Sequence::type>::type type;
			};
		};
	}
}
int ch05_tree_main()
{
	typedef tree<double, tree<void*, int, long>, char> tree_seq;

	BOOST_STATIC_ASSERT((
	mpl::equal<
			preorder_view<tree_seq>::type,
			mpl::vector<double, void*, int, long, char>
		>::value
		));

	BOOST_STATIC_ASSERT((
	mpl::equal<
			cenorder_view<tree_seq>::type,
			mpl::vector<int, void*, long, double, char>
		>::value
		));

	BOOST_STATIC_ASSERT((
	mpl::equal<
			postorder_view<tree_seq>::type,
			mpl::vector<int,  long,void*,  char,double>
		>::value
		));
	return 0;
}