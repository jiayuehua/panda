#include "complete_btree.h"
#include <utility>
#include <iostream>
template <class T>
std::pair<BNode<T>*, BNode<T>*> btree_to_dlink(BNode<T>* head)
{
	BNode<T>* b =head, *e = head;
	if (head)
	{
		if (head->left)
		{
			std::pair<BNode<T>*, BNode<T>*> np = btree_to_dlink(head->left);
			b = np.first;
			np.second->right = head;
			head->left = np.second;
		}
		if (head->right)
		{
			std::pair<BNode<T>*, BNode<T>*> np = btree_to_dlink(head->right);
			e = np.second;
			head->right = np.first;
			np.first->left = head;
		}
	}
	return std::make_pair(b,e);
}

int btree_to_dlink_main()
{
	BNode<int> * head = complete_btree_main<int>();
	std::pair<BNode<int>*, BNode<int>*> np = btree_to_dlink<int>(head);
	for (BNode<int>* p = np.first;p; p = p->right)
	{
		std::cout << p->data<<std::endl;
	}
	BNode<int>* q = np.first;
	for (BNode<int>* p = np.first;p; p = q)
	{
		q = p->right;
		delete p;
	}
	return 0;
}