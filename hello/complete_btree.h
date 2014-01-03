#ifndef COMPLETE_BTREE_H
#define COMPLETE_BTREE_H
#include <list>
template <class T>
struct BNode
{
	BNode<T> * left;
	BNode<T> * right;
	T data;
	BNode(int d = 0):left(0),right(0),data(d)	{}
};
template<class T>
BNode<T>* complete_btree_main()
{
	//   1
	// 2   3
	//4 5 6
	BNode<T>* head = new BNode<T>(1);
	head ->left = new BNode<T>(2);
	head ->right = new BNode<T>(3);
	head ->left->left = new BNode<T>(4);
	head ->left->right = new BNode<T>(5);
	head ->right->left = new BNode<T>(6);
//	head ->right->right = new BNode;
//	std::cout<<is_complete_tree(head)<<std::endl;
	//free_BTree(head);
	return head;
}

template<class T>
void deleteObj(T *p)
{
	delete p;
}
template<class T, class F>
void postVisitBTree(BNode<T> * head, F f)
{
	if (head -> left)
	{
		postVisitBTree(head->left,f);
		head->left = 0; //去掉这条也可。
	} 
	if(head ->right)
	{
		postVisitBTree(head->right,f);
		head->right = 0;//去掉也可
	}
	f(head);
}

template<class T>
bool is_complete(BNode<T> *  head)
{
	std::list<BNode<T> *> d1;
	if (!head)
	{
		return false;
	}
	d1.push_back(head);
	bool lack(false);
	for (std::list<BNode<T>*>::iterator i = d1.begin(); i != d1.end(); ++i)
	{
		if ((*i)->left)
		{
			if(!lack)
			{
				d1.push_back((*i)->left);
			}
			else
			{
				return false;
			}
		}
		else
		{
			lack = true;
		}
		if ((*i)->right)
		{
			if(!lack)
			{
				d1.push_back((*i)->right);
			}
			else
			{
				return false;
			}
		}
		else
		{
			lack = true;
		}
	}
	return true;
}
template<class T,   class F>
void level_transfer_tree(BNode<T> *  head, F f )
{
	std::list<BNode<T> *> d1;
	if (!head)
	{
		return ;
	}
	f(head->data);
	d1.push_back(head);
	for (std::list<BNode<T>*>::iterator i = d1.begin(); i != d1.end(); ++i)
	{
		if ((*i)->left)
		{
			f( (*i)->left->data);
			d1.push_back((*i)->left);
		}
		if ((*i)->right)
		{
			f( (*i)->right->data);
			d1.push_back((*i)->right);
		}
	}
}
#endif