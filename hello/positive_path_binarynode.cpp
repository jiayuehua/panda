//寻找根节点到该节点路径上元素值递增或相等的节点，返回个数
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>

struct tree {
	int x;
	tree * l;
	tree * r;
};
int pre_visit(tree* t, int  n)
{
	if(!t)
	{
		return 0;
	}
	int f_res = 0;
	if (t->x >= n)
	{
		n = t->x;
		++f_res;
	}
	return f_res + pre_visit(t->l,n) + pre_visit(t->r,n);
}

int solution(tree * T)
{
	return pre_visit(T, T->x);
}
