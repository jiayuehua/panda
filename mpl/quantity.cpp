#include <boost/mpl/vector.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/erase.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/insert_range.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/advance.hpp>
#include <boost/mpl/divides.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/back_inserter.hpp>
#include <boost/mpl/iterator_range.hpp>
#include <iostream>
namespace mpl = boost::mpl;
typedef mpl::vector_c<int, 1, 0, 0, 0, 0, 0, 0> mass	;
typedef mpl::vector_c<int, 0, 1, 0, 0, 0, 0, 0> length	;
typedef mpl::vector_c<int, 0, 0, 1, 0, 0, 0, 0> time1	;
typedef mpl::vector_c<int, 0, 0, 0, 1, 0, 0, 0> charge	;
typedef mpl::vector_c<int, 0, 0, 0, 0, 1, 0, 0> temperature;
typedef mpl::vector_c<int, 0, 0, 0, 0, 0, 1, 0> intensity	;
typedef mpl::vector_c<int, 0, 0, 0, 0, 0, 0, 1> amount_of_substances;
template <class TSeq>
struct DoubleFirstHalf
{
	//static const int HS = mpl::size<TSeq>::type::value/2;
	typedef typename mpl::divides<mpl::size<TSeq>, mpl::int_<2> >::type HalfSize;
	//typedef mpl::int_<HS> HalfSize;
	typedef typename mpl::begin<TSeq>::type Seq_Begin;
	typedef typename mpl::end<TSeq>::type Seq_End;
	typedef typename mpl::advance<Seq_Begin, HalfSize>::type Seq_HalfPos;
	typedef typename mpl::iterator_range<Seq_HalfPos, Seq_End>::type RightSeq;
	typedef typename mpl::iterator_range<Seq_Begin, Seq_HalfPos>::type LeftSeq;
	//typedef typename mpl::transform<RightSeq, mpl::times<mpl::_,mpl::int_<2> > >::type doubleright_half;
	typedef typename mpl::transform<LeftSeq, mpl::times<mpl::_, mpl::int_<2> >, mpl::back_inserter<mpl::vector<> > >::type DoubleTypes;
	typedef typename mpl::insert_range<DoubleTypes, typename mpl::end<DoubleTypes>::type, RightSeq>::type type;
	//typedef typename mpl::transform<TSeq,TSeq,mpl::plus<mpl::_,mpl::_> >::type DoubleTypes;
	//typedef typename mpl::begin<DoubleTypes>::type DT_Begin;
	//typedef typename mpl::advance<DT_Begin, HalfSize>::type DT_HalfPos;
	//typedef typename mpl::end<DoubleTypes>::type DT_End;
	//typedef typename mpl::erase<DoubleTypes, DT_HalfPos, DT_End >::type Leftdoubletypes;
	//typedef typename mpl::end<Leftdoubletypes>::type left_end;
	//typedef typename mpl::insert_range<Leftdoubletypes,left_end,RightSeq>::type type;
};
//template <class TSeq>
//struct double_first_half
//{
//	static const int HS = mpl::size<TSeq>::type::value/2;
//	typedef mpl::int_<HS> HalfSize;
//	typedef typename mpl::transform<TSeq,TSeq,mpl::plus<mpl::_,mpl::_> >::type DoubleTypes;
//	typedef typename mpl::begin<TSeq>::type Seq_Begin;
//	typedef typename mpl::advance<Seq_Begin, HalfSize>::type Seq_HalfPos;
//	typedef typename mpl::begin<DoubleTypes>::type DT_Begin;
//	typedef typename mpl::advance<DT_Begin, HalfSize>::type DT_HalfPos;
//	typedef typename mpl::end<DoubleTypes>::type DT_End;
//	typedef typename mpl::erase<DoubleTypes, DT_HalfPos, DT_End >::type Leftdoubletypes;
//	typedef typename mpl::end<Leftdoubletypes>::type Leftdoubletypes_endpos;
//	typedef typename mpl::erase<TSeq, Seq_Begin,Seq_HalfPos >::type RightTseq;
//	typedef typename mpl::insert_range<Leftdoubletypes,Leftdoubletypes_endpos,RightTseq>::type type;
//};

int quantity_main()
{
	//std::cout<<mpl::equal<mpl::vector_c<int,2,4,3,4 >, double_first_half<mpl::vector_c<int,1, 2, 3, 4> >::type >::type::value;
	std::cout<<mpl::equal<mpl::vector_c<int,2,4,3,4 >, DoubleFirstHalf<mpl::vector_c<int,1, 2, 3, 4> >::type >::type::value;
	return 0;
}