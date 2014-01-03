#include <vector>
#include <algorithm>
#include <iterator>
#include <boost/assign.hpp>
#include <boost/range.hpp>
#include "complete_btree.h"
template<class RanIt1, class RanIt2>
BNode<typename std::iterator_traits<RanIt1>::value_type>  * create_binary_tree(RanIt1 preStr_begin,  RanIt1 preStr_end, RanIt2 cenStr_begin, RanIt2 cenStr_end)
{
	if (preStr_begin == preStr_end)
	{
		return 0;
	}
	else
	{
		RanIt2 ci = std::find(cenStr_begin, cenStr_end, *preStr_begin);
		int l_len = ci - cenStr_begin;
		int r_len = cenStr_end - ci -1;
		BNode<typename std::iterator_traits<RanIt1>::value_type> * parentnode = new BNode<typename std::iterator_traits<RanIt1>::value_type>(*preStr_begin);
		parentnode->left = create_binary_tree(preStr_begin+1, preStr_begin+1+l_len, cenStr_begin, cenStr_begin+l_len);
		parentnode->right = create_binary_tree(preStr_begin+1+l_len, preStr_end, cenStr_begin+1+l_len, cenStr_end );
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
int main()
{
	using namespace boost::assign;
	std::vector<char> p,c;
	p += 'b','a','c','d','e';
	c += 'a','b','c','e','d';
	BNode<char>* head = create_binary_tree(p.begin(),p.end(),c.begin(),c.end());
	printbinary_tree(head);
	//free_BTree(head);
}