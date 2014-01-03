template <class T>
struct BNode
{
	BNode<T> * left;
	BNode<T> * right;
	T data;
	BNode(int d = 0):left(0),right(0),data(d)	{}
};
//void free_BTree(BNode * head);
//BNode* complete_btree_main();