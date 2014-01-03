#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <boost/range.hpp>
#include <boost/range/algorithm.hpp>
#include "complete_btree.h"
#include <loki/Singleton.h>
//返回指向二叉树的根的指针
//参数
//    preStr_begin 指向前序遍历开始的迭代器
//    preStr_end 指向前序遍历结束的迭代器
//    cenStr_begin 指向中序遍历开始的迭代器
//    cenStr_end 指向中序遍历结束的迭代器
 
template<class FwdRange1, class FwdRange2>
BNode<typename std::iterator_traits<typename boost::range_iterator<FwdRange1>::type>::value_type>  * create_binary_tree(FwdRange1 preStr, FwdRange2 cenStr)
{
	if (boost::begin(preStr) == boost::end(preStr))
	{
		return 0;
	} 
	else
	{
		typedef boost::iterator_range<typename boost::range_iterator<FwdRange1>::type > IR1;
		typedef boost::iterator_range<typename boost::range_iterator<FwdRange2>::type > IR2;
		IR2 cenStrleft(boost::find<boost::return_begin_found>(cenStr,*boost::begin(preStr)));
		IR2 cenStrright(cenStr);
		int cenStrleft_size = std::distance(boost::begin(cenStrleft), boost::end(cenStrleft));
		cenStrright.advance_begin(1+cenStrleft_size);
		IR1 preStrleft(boost::begin(preStr), boost::begin(preStr) );
		preStrleft.advance_begin(1);
		preStrleft.advance_end(1+cenStrleft_size);
		IR1 preStrright(preStr);
		preStrright.advance_begin(1+cenStrleft_size);
		typename BNode<typename std::iterator_traits<typename boost::range_iterator<FwdRange1>::type>::value_type> *parentnode 
			= new BNode<typename std::iterator_traits<typename boost::range_iterator<FwdRange1>::type>::value_type>(*boost::begin(preStr));
		parentnode->left  = create_binary_tree(preStrleft,cenStrleft);
		parentnode->right  = create_binary_tree(preStrright,cenStrright);
		return parentnode;
	}
}

template<class T>
void printbinary_tree(BNode<T>* p)
{
	std::cout<<"(";
	if (p)
	{
		std::cout<<p->data;
		if (p->left||p->right)
		{
			printbinary_tree(p->left);
		}
		if (p->right)
		{
			printbinary_tree(p->right);
		}
	}
	std::cout<<")";
}
template <class T>
void print( T t)
{
	std::cout<<t<<" ";
}
template<class T>
struct Printer{
	void operator()(T t)
	{
		print(t);
	}
};

#include <boost/assign.hpp>
int create_binary_tree_main()
{
	using namespace boost::assign;
	std::list<char> p,c;
	//p += 'b','a','c','d','e';
	//c += 'a','b','c','e','d';
	p += 'b','a';
	c += 'a','b';
	//BNode<char>* head = create_binary_tree(p,c);
	BNode<int>* head = complete_btree_main<int>();
	//Printer<char> p1;
	level_transfer_tree(head, &print<int>);
	printbinary_tree(head);
	std::cout<<std::boolalpha<<is_complete(head)<<std::endl;
	postVisitBTree(head, &deleteObj<BNode<int> >);
	return 0;
}