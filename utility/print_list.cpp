#include <iostream>
#include <list>
template <class ForwardIt, class Func>
void reverse_visit(ForwardIt b, ForwardIt e, Func fun)
{
	if (b != e)
	{
		ForwardIt b1 = b;
		++b;
		reverse_visit(b,e,fun);
		fun(*b1);
		//std::cout<<*b1;
	}
}
template <class T>
void foo(T t)
{
	std::cout<<t<<" ";
}

int print_list_main()
{
	const int i = 1;
	int *j  = const_cast<int*>(&i);
	*j = 2;
	std::cout<<i<<" "<<*j<< " "<<((int*)&i == j) << "\n";
	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	reverse_visit(l.begin(),l.end(), &foo<int>);
	return 0;
}