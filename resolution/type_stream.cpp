#include <boost/type_traits.hpp>
#include <iostream>
#include <exception>
template<class T>
struct type_descriptor
{
	template<class U>
	friend std::ostream & operator<<(std::ostream& os, const type_descriptor<U> &);
};

template<class U>
std::ostream & operator<<(std::ostream& os, const type_descriptor<U> &)
{
	if (boost::is_pointer<U>::value)
	{
		os<<type_descriptor<typename boost::remove_pointer<U>::type>()<<"*";
		return os;
	}

	else if (boost::is_reference<U>::value)
	{
		os<<type_descriptor<typename boost::remove_reference<U>::type>()<<"&";
		return os;
	}
	else if (boost::is_array<U>::value)
	{
			os<<"["<<(sizeof U/sizeof typename boost::remove_bounds<U>::type )<<"]"
			<<type_descriptor<typename boost::remove_bounds<U>::type>();
		return os;
	}
	else if (boost::is_const<U>::value)
	{
		os<<"const"<<type_descriptor<typename boost::remove_const<U>::type>();
		return os;
	}
	else if (boost::is_integral<U>::value)
	{
		os<<type_descriptor<U>();
		return os;
	}
	else
	{
		throw std::exception("error");
	}
}
//
//template<class T,int N>
//struct type_descriptor<T[N]>
//{
//	 template<class U,int  M>
//	 friend std::ostream & operator<<(std::ostream & os, const type_descriptor<U[M]> &);
//};
//template<class U, int M> 
//std::ostream & operator<<(std::ostream & os, const type_descriptor<U[M]> &)
//{
//	os <<type_descriptor<U>()<<"["<<M<<"]";
//	return os;
//};
//
//template<class T>
// struct type_descriptor<const T>
//{
//	 template<class U>
//	 friend std::ostream & operator<<(std::ostream & os, const type_descriptor<const U> &);
//};
//template<class U> 
//std::ostream & operator<<(std::ostream & os, const type_descriptor<const U> &)
//{
//	os <<"const "<<type_descriptor<U>();
//	return os;
//};
//template<class T>
//struct type_descriptor<T&>
//{
 //	 template<class U>
//	 friend std::ostream & operator<<(std::ostream & os, const type_descriptor<U&> &);
//};
//template<class U> 
//std::ostream & operator<<(std::ostream & os, const type_descriptor<U&> &)
//{
//	os <<type_descriptor<U>()<<"&";
//	return os;
//}
//template<class T>
//struct type_descriptor<T*>
//{
//	template<class U>
//	friend std::ostream & operator<<(std::ostream & os, const type_descriptor<U*> &);
//};
//template<class U> 
//std::ostream & operator<<(std::ostream & os, const type_descriptor<U*> &)
//{
//	os <<type_descriptor<U>()<<"*";
//	return os;
//}
//
template<>
struct type_descriptor<char>
{
	friend std::ostream & operator<<(std::ostream & os, const type_descriptor<char> &);

};
std::ostream & operator<<(std::ostream & os, const type_descriptor<char>& )
{
	os <<"char";
	return os;
}

template<>
struct type_descriptor<long int>
{
	friend std::ostream & operator<<(std::ostream & os, const type_descriptor<long int> &);

};
std::ostream & operator<<(std::ostream & os, const type_descriptor<long int>& )
{
	os <<"long";
	return os;
}
template<>
struct type_descriptor<int>
{
	friend std::ostream & operator<<(std::ostream & os, const type_descriptor<int> &);

};
std::ostream & operator<<(std::ostream & os, const type_descriptor<int>& )
{
	os <<"int";
	return os;
}
template<>
struct type_descriptor<bool>
{
	friend std::ostream & operator<<(std::ostream & os, const type_descriptor<bool> &);
};
std::ostream & operator<<(std::ostream & os, const type_descriptor<bool>& )
{
	os <<"bool";
	return os;
}
template<>
struct type_descriptor<short int>
{
	friend std::ostream & operator<<(std::ostream & os, const type_descriptor<short int> &);
};
std::ostream & operator<<(std::ostream & os, const type_descriptor<short int>& )
{
	os <<"short";
	return os;
}
int type_stream_main()
{
	typedef int * F;
	typedef int  F1[100][111];
	std::cout<<type_descriptor<F>()<<"\n";
	std::cout<<type_descriptor<F1>()<<"\n";
	return 0;
}