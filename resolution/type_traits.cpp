#include <boost/type_traits.hpp>
#include <iostream>
template<bool is_refrence, class T>
struct Result;
template<class T>
struct Result<false, T>
{
	typedef typename boost::add_reference<typename boost::add_const<T>::type>::type type;
};

template<class T>
struct Result<true, T>
{
	typedef T type;
};

template<class T>
struct add_const_ref
{
	typedef typename Result< boost::is_reference<T>::value, T>::type type;
};

template <class TypeDef, class SrcType, class DesType>
struct replace_type
{
	typedef TypeDef type;
};

template<class SrcType, class DesType>
struct replace_type<SrcType, SrcType, DesType>
{
	typedef DesType type;
};
template <class TypeDef, class SrcType, class DesType>
struct replace_type<const TypeDef, SrcType, DesType>
{
	typedef const typename replace_type<TypeDef,SrcType,DesType>::type type;
};
template <class TypeDef, class SrcType, class DesType>
struct replace_type<TypeDef&, SrcType, DesType>
{
	typedef  typename replace_type<TypeDef,SrcType,DesType>::type& type;
};
template <class TypeDef, class SrcType, class DesType>
struct replace_type<TypeDef*, SrcType, DesType>
{
	typedef  typename replace_type<TypeDef,SrcType,DesType>::type* type;
};

template<class TypeDef, class SrcType,class DesType, int N>
struct replace_type<TypeDef[N], SrcType, DesType>
{
	typedef typename replace_type<TypeDef,SrcType,DesType>::type  R;
	typedef R type[N] ;
};

template<class SrcType, class DesType, class TRet>
struct replace_type<TRet(*)(...),SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef TR(*type)(...);
};

template<class SrcType,class DesType, class TRet, class TSArg1>
struct replace_type<TRet(*)(TSArg1,...),SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg1;
	typedef TR(*type)(TDArg1,...);
};
template<class SrcType,class DesType, class TRet, class TSArg1, class TSArg2>
struct replace_type<TRet(*)(TSArg1, TSArg2,...),SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg1;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg2;
	typedef TR(*type)(TDArg1, TDArg2, ...);
};
template<class SrcType,class DesType, class TRet, class TSArg1, class TSArg2, class TSArg3>
struct replace_type<TRet(*)(TSArg1, TSArg2, TSArg3, ...),SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg1;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg2;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg3;
	typedef TR(*type)(TDArg1, TDArg2, TDArg3,...);
};
template<class SrcType,class DesType, class TRet, class TSArg1, class TSArg2, class TSArg3, class TSArg4 >
struct replace_type<TRet(*)(TSArg1, TSArg2, TSArg3, TSArg4,...),SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg1;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg2;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg3;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg4;
	typedef TR(*type)(TDArg1, TDArg2, TDArg3,TDArg4,...);
};
template<class SrcType,class DesType, class TRet, class TSArg1, class TSArg2, class TSArg3, class TSArg4,
	class TSArg5>
struct replace_type<TRet(*)(TSArg1, TSArg2, TSArg3,TSArg4, TSArg5,...), SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg1;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg2;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg3;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg4;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg5;
	typedef TR(*type)(TDArg1, TDArg2, TDArg3,TDArg4, TDArg5,...);
};
template<class SrcType,class DesType, class TRet, class TSArg1, class TSArg2, class TSArg3, class TSArg4,
	class TSArg5, class TSArg6>
struct replace_type<TRet(*)(TSArg1, TSArg2, TSArg3,TSArg4, TSArg5, TSArg6,...),SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg1;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg2;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg3;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg4;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg5;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg6;
	typedef TR(*type)(TDArg1, TDArg2, TDArg3,TDArg4, TDArg5, TDArg6,...);
};
template<class SrcType,class DesType, class TRet, class TSArg1, class TSArg2, class TSArg3, class TSArg4,
	class TSArg5, class TSArg6, class TSArg7>
struct replace_type<TRet(*)(TSArg1, TSArg2, TSArg3,TSArg4, TSArg5, TSArg6, TSArg7,...),SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg1;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg2;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg3;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg4;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg5;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg6;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg7;
	typedef TR(*type)(TDArg1, TDArg2, TDArg3,TDArg4, TDArg5, TDArg6, TDArg7,...);
};
template<class SrcType,class DesType, class TRet, class TSArg1, class TSArg2, class TSArg3, class TSArg4,
	class TSArg5, class TSArg6, class TSArg7, class TSArg8>
struct replace_type<TRet(*)(TSArg1, TSArg2, TSArg3,TSArg4, TSArg5, TSArg6, TSArg7, TSArg8,...),SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg1;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg2;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg3;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg4;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg5;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg6;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg7;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg8;
	typedef TR(*type)(TDArg1, TDArg2, TDArg3,TDArg4, TDArg5, TDArg6, TDArg7, TDArg8,...);
};
template<class SrcType,class DesType, class TRet, class TSArg1, class TSArg2, class TSArg3, class TSArg4,
	class TSArg5, class TSArg6, class TSArg7, class TSArg8, class TSArg9>
struct replace_type<TRet(*)(TSArg1, TSArg2, TSArg3,TSArg4, TSArg5, TSArg6, TSArg7, TSArg8, TSArg9,...),SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg1;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg2;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg3;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg4;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg5;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg6;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg7;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg8;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg9;
	typedef TR(*type)(TDArg1, TDArg2, TDArg3,TDArg4, TDArg5, TDArg6, TDArg7, TDArg8, TDArg9,...);
};
template<class SrcType,class DesType, class TRet, class TSArg1, class TSArg2, class TSArg3, class TSArg4,
	class TSArg5, class TSArg6, class TSArg7, class TSArg8, class TSArg9, class TSArg10>
struct replace_type<TRet(*)(TSArg1, TSArg2, TSArg3,TSArg4, TSArg5, TSArg6, TSArg7, TSArg8, TSArg9, TSArg10,...),SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg1;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg2;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg3;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg4;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg5;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg6;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg7;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg8;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg9;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg10;
	typedef TR(*type)(TDArg1, TDArg2, TDArg3,TDArg4, TDArg5, TDArg6, TDArg7, TDArg8, TDArg9, TDArg10,...);
};
template<class SrcType, class DesType, class TRet>
struct replace_type<TRet(*)(),SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef TR(*type)();
};

template<class SrcType,class DesType, class TRet, class TSArg1>
struct replace_type<TRet(*)(TSArg1),SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg1;
	typedef TR(*type)(TDArg1);
};
template<class SrcType,class DesType, class TRet, class TSArg1, class TSArg2>
struct replace_type<TRet(*)(TSArg1, TSArg2),SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg1;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg2;
	typedef TR(*type)(TDArg1, TDArg2);
};
template<class SrcType,class DesType, class TRet, class TSArg1, class TSArg2, class TSArg3>
struct replace_type<TRet(*)(TSArg1, TSArg2, TSArg3),SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg1;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg2;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg3;
	typedef TR(*type)(TDArg1, TDArg2, TDArg3);
};
template<class SrcType,class DesType, class TRet, class TSArg1, class TSArg2, class TSArg3, class TSArg4 >
struct replace_type<TRet(*)(TSArg1, TSArg2, TSArg3, TSArg4),SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg1;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg2;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg3;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg4;
	typedef TR(*type)(TDArg1, TDArg2, TDArg3,TDArg4);
};
template<class SrcType,class DesType, class TRet, class TSArg1, class TSArg2, class TSArg3, class TSArg4, class TSArg5>
struct replace_type<TRet(*)(TSArg1, TSArg2, TSArg3,TSArg4, TSArg5), SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg1;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg2;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg3;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg4;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg5;
	typedef TR(*type)(TDArg1, TDArg2, TDArg3,TDArg4, TDArg5);
};
template<class SrcType,class DesType, class TRet, class TSArg1, class TSArg2, class TSArg3, class TSArg4,
	class TSArg5, class TSArg6>
struct replace_type<TRet(*)(TSArg1, TSArg2, TSArg3,TSArg4, TSArg5, TSArg6),SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg1;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg2;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg3;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg4;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg5;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg6;
	typedef TR(*type)(TDArg1, TDArg2, TDArg3,TDArg4, TDArg5, TDArg6);
};
template<class SrcType,class DesType, class TRet, class TSArg1, class TSArg2, class TSArg3, class TSArg4,
	class TSArg5, class TSArg6, class TSArg7>
struct replace_type<TRet(*)(TSArg1, TSArg2, TSArg3,TSArg4, TSArg5, TSArg6, TSArg7),SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg1;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg2;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg3;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg4;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg5;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg6;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg7;
	typedef TR(*type)(TDArg1, TDArg2, TDArg3,TDArg4, TDArg5, TDArg6, TDArg7);
};
template<class SrcType,class DesType, class TRet, class TSArg1, class TSArg2, class TSArg3, class TSArg4,
	class TSArg5, class TSArg6, class TSArg7, class TSArg8>
struct replace_type<TRet(*)(TSArg1, TSArg2, TSArg3,TSArg4, TSArg5, TSArg6, TSArg7, TSArg8),SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg1;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg2;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg3;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg4;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg5;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg6;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg7;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg8;
	typedef TR(*type)(TDArg1, TDArg2, TDArg3,TDArg4, TDArg5, TDArg6, TDArg7, TDArg8);
};
template<class SrcType,class DesType, class TRet, class TSArg1, class TSArg2, class TSArg3, class TSArg4,
	class TSArg5, class TSArg6, class TSArg7, class TSArg8, class TSArg9>
struct replace_type<TRet(*)(TSArg1, TSArg2, TSArg3,TSArg4, TSArg5, TSArg6, TSArg7, TSArg8, TSArg9),SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg1;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg2;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg3;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg4;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg5;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg6;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg7;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg8;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg9;
	typedef TR(*type)(TDArg1, TDArg2, TDArg3,TDArg4, TDArg5, TDArg6, TDArg7, TDArg8, TDArg9);
};
template<class SrcType,class DesType, class TRet, class TSArg1, class TSArg2, class TSArg3, class TSArg4,
	class TSArg5, class TSArg6, class TSArg7, class TSArg8, class TSArg9, class TSArg10>
struct replace_type<TRet(*)(TSArg1, TSArg2, TSArg3,TSArg4, TSArg5, TSArg6, TSArg7, TSArg8, TSArg9, TSArg10),SrcType,DesType>
{
	typedef typename replace_type<typename TRet, SrcType,DesType>::type TR;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg1;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg2;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg3;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg4;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg5;
	typedef typename replace_type<typename TSArg1, SrcType,DesType>::type TDArg6;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg7;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg8;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg9;
	typedef typename replace_type<typename TSArg2, SrcType,DesType>::type TDArg10;
	typedef TR(*type)(TDArg1, TDArg2, TDArg3,TDArg4, TDArg5, TDArg6, TDArg7, TDArg8, TDArg9, TDArg10);
};
int replace_main()
{
	std::cout<<boost::is_same<int[10] , replace_type<double[10], double, int>::type>::value<<"\n";
	std::cout<<boost::is_same<int(*)(double) , replace_type<void(*)(double), void, int>::type>::value<<"\n";
	std::cout<<boost::is_same<int&, add_const_ref<int&>::type>::value;
	std::cout<<boost::is_same<const int&, add_const_ref<int>::type>::value;
	std::cout<<boost::is_same<const int &, add_const_ref<const int&>::type>::value;
	return 0;
}