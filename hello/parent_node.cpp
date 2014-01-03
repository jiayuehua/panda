#include <iostream>
#include "complete_btree.h"
template<class T>
int calculate_parent_node(BNode<T>* root, BNode<T>* n1, BNode<T>* n2, BNode<T>** parent)
{
	int l = 0, r = 0;
	if (root)
	{
		if (root->left)
		{
			l = calculate_parent_node(root->left,n1,n2,parent);
			if(l == 2)
			{
				return 2;
			}
		}
		if (root->right)
		{
			r = calculate_parent_node(root->right,n1,n2,parent);
			if(r == 2)
			{
				return 2;
			}
		}
	}
	if (parent)
	{
		*parent = root;
	}
	return l + r + (root == n1) + (root == n2);
}
//   1
// 2   3
//4 5 6
int parent_node_main()
{
	BNode<int>  * parent;
	BNode<int>* h = complete_btree_main<int>();
	int n = calculate_parent_node(h, h->left->left, h->left->left, &parent);
	std::cout<<n<<" "<<parent->data<<"\n";
	//free_BTree(h);
	postVisitBTree(h, &deleteObj<BNode<int> >);
	return 0;
}