#include <cmath>
#include <iostream>
#include   <boost/units/cmath.hpp>
#include <boost/units/conversion.hpp>
#include <boost/units/static_constant.hpp>
template <int L, int M, int T, int I, int H, int N,  int J,
			int L1 =1 , int M1 = 1, int T1 = 1, int I1 = 1, int H1 = 1, int N1 = 1,  int J1 = 1 >
struct Dimensions
{
};

double int_power(int lhs, int rhs)
{
	return std::pow(static_cast<double>(lhs), rhs);
}

template<class DataType, class Dim>
struct Quantity;

template<class DataType, int L, int M, int T, int I, int H, int N,  int J, int L1 , int M1 , int T1 , int I1 , int H1 , int N1 ,  int J1 >
struct Quantity<DataType, Dimensions< L,  M,  T,  I,  H,  N,   J, L1 ,  M1 ,  T1 ,  I1 ,  H1 ,  N1 ,   J1 > >
{
	explicit Quantity(DataType other):value_(other) { }
	Quantity():value_(0) {}
	

	template <int L2 , int M2 , int T2 , int I2 , int H2 , int N2 ,  int J2 >
	  Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J,
			 L1 ,  M1 ,  T1 ,  I1 ,  H1 ,  N1 ,   J1 > > &
	operator=( const Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J,
					 L2 ,  M2 ,  T2 ,  I2 ,  H2 ,  N2 ,   J2 > > & other )
	{
		value_ = other.value_ 
			* int_power(L2, L)/int_power(L1,L)
			* int_power(M2, M)/int_power(M1,M)
			* int_power(T2, T)/int_power(T1,T)
			* int_power(I2, I)/int_power(I1,I)
			* int_power(H2, H)/int_power(H1,H)
			* int_power(N2, N)/int_power(N1,N)
			* int_power(J2, J)/int_power(J1,J);
		return *this;
	}

	
	template <int L2 , int M2 , int T2 , int I2 , int H2 , int N2 ,  int J2 >
	Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J, L1 ,  M1 ,  T1 ,  I1 ,  H1 ,  N1 ,   J1 > > &
	operator +=( const Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J, L2 ,  M2 ,  T2 ,  I2 ,  H2 ,  N2 ,   J2 > > & other )
	{

		value_ += other.value_ 
			* int_power(L2, L)/int_power(L1,L)
			* int_power(M2, M)/int_power(M1,M)
			* int_power(T2, T)/int_power(T1,T)
			* int_power(I2, I)/int_power(I1,I)
			* int_power(H2, H)/int_power(H1,H)
			* int_power(N2, N)/int_power(N1,N)
			* int_power(J2, J)/int_power(J1,J);
		return *this;
	}

	template <int L2 , int M2 , int T2 , int I2 , int H2 , int N2 ,  int J2 >
	Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J, L1 ,  M1 ,  T1 ,  I1 ,  H1 ,  N1 ,   J1 > > &
	operator -=( const Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J, L2 ,  M2 ,  T2 ,  I2 ,  H2 ,  N2 ,   J2 > > & other )
	{
		value_ -= other.value_ 
			* int_power(L2, L)/int_power(L1,L)
			* int_power(M2, M)/int_power(M1,M)
			* int_power(T2, T)/int_power(T1,T)
			* int_power(I2, I)/int_power(I1,I)
			* int_power(H2, H)/int_power(H1,H)
			* int_power(N2, N)/int_power(N1,N)
			* int_power(J2, J)/int_power(J1,J);
		return *this;
	}

	template <int L2 , int M2 , int T2 , int I2 , int H2 , int N2 ,  int J2 >
	Quantity(const Quantity<DataType, Dimensions< L,  M,  T,  I,  H,  N,   J, L2 ,  M2 ,  T2 ,  I2 ,  H2 ,  N2 ,   J2 > >
		&other)
	{
		value_ = other.value_ 
			* int_power(L2, L)/int_power(L1,L)
			* int_power(M2, M)/int_power(M1,M)
			* int_power(T2, T)/int_power(T1,T)
			* int_power(I2, I)/int_power(I1,I)
			* int_power(H2, H)/int_power(H1,H)
			* int_power(N2, N)/int_power(N1,N)
			* int_power(J2, J)/int_power(J1,J);
	}

	template <int L2 , int M2 , int T2 , int I2 , int H2 , int N2 ,  int J2 >
	Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J, L1 ,  M1 ,  T1 ,  I1 ,  H1 ,  N1 ,   J1 > > 
	friend operator +(	const Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J, L1 ,  M1 ,  T1 ,  I1 ,  H1 ,  N1 ,   J1 > > &lhs,  
						const Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J, L2 ,  M2 ,  T2 ,  I2 ,  H2 ,  N2 ,   J2 > > &rhs );

	template <int L2 , int M2 , int T2 , int I2 , int H2 , int N2 ,  int J2 >
	Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J, L1 ,  M1 ,  T1 ,  I1 ,  H1 ,  N1 ,   J1 > > 
	friend operator -(	const Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J, L1 ,  M1 ,  T1 ,  I1 ,  H1 ,  N1 ,   J1 > > &lhs,  
						const Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J, L2 ,  M2 ,  T2 ,  I2 ,  H2 ,  N2 ,   J2 > > &rhs );

	DataType get_value()const
	{
		return value_;
	}
public:
	DataType value_;
};

template<class DataType, int L, int M, int T, int I, int H, int N,  int J,
			int L1 , int M1 , int T1 , int I1 , int H1 , int N1 ,  int J1 ,
	        int L2 , int M2 , int T2 , int I2 , int H2 , int N2 ,  int J2 >
	  Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J,
			 L1 ,  M1 ,  T1 ,  I1 ,  H1 ,  N1 ,   J1 > > 
			operator -( const Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J,
								 L1 ,  M1 ,  T1 ,  I1 ,  H1 ,  N1 ,   J1 > > &lhs,  
							const Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J,
								 L2 ,  M2 ,  T2 ,  I2 ,  H2 ,  N2 ,   J2 > >& rhs )
	  {
		  Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J,
					 L1 ,  M1 ,  T1 ,  I1 ,  H1 ,  N1 ,   J1 > > tmp(lhs);
		  tmp -= rhs;
		  return tmp;
	  }
template<class DataType, int L, int M, int T, int I, int H, int N,  int J,
			int L1 , int M1 , int T1 , int I1 , int H1 , int N1 ,  int J1 ,
	        int L2 , int M2 , int T2 , int I2 , int H2 , int N2 ,  int J2 >
	  Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J,
			 L1 ,  M1 ,  T1 ,  I1 ,  H1 ,  N1 ,   J1 > > 
			operator +( const Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J,
								 L1 ,  M1 ,  T1 ,  I1 ,  H1 ,  N1 ,   J1 > > &lhs,  
						const Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J,
								 L2 ,  M2 ,  T2 ,  I2 ,  H2 ,  N2 ,   J2 > >& rhs )
	  {
		  Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J,
					 L1 ,  M1 ,  T1 ,  I1 ,  H1 ,  N1 ,   J1 > > tmp(lhs);
		  tmp += rhs;
		  return tmp;
	  }

template<class DataType, int L, int M, int T, int I, int H, int N,  int J, int L1 , int M1 , int T1 , int I1 , int H1 , int N1 ,  int J1 ,
	int L0 , int M0 , int T0 , int I0 , int H0 , int N0 ,  int J0 , int L2 , int M2 , int T2 , int I2 , int H2 , int N2 ,  int J2 >
	Quantity<DataType,Dimensions< L+L0,  M+M0,  T+T0,  I+I0,  H+H0,  N+N0,  J+J0,  L1 ,  M1 ,  T1 ,  I1 , H1, N1, J1 > > 
	operator *(	const Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J, L1 ,  M1 ,  T1 ,  I1 ,  H1 ,  N1 ,   J1 > >		   &lhs,  
				const Quantity<DataType,Dimensions< L0,  M0,  T0,  I0,  H0,  N0,  J0,  L2 ,  M2 ,  T2 ,  I2 ,  H2 ,  N2 ,   J2 > > &rhs )
	{

		DataType val (lhs.get_value()); 
		 val  *= (rhs.get_value() 
			* int_power(L2, L0)/int_power(L1,L)
			* int_power(M2, M0)/int_power(M1,M)
			* int_power(T2, T0)/int_power(T1,T)
			* int_power(I2, I0)/int_power(I1,I)
			* int_power(H2, H0)/int_power(H1,H)
			* int_power(N2, N0)/int_power(N1,N)
			* int_power(J2, J0)/int_power(J1,J) );
		return Quantity<DataType,Dimensions< L+L0,  M+M0,  T+T0,  I+I0,  H+H0,  N+N0,  J+J0,  L1 ,  M1 ,  T1 ,  I1 , H1, N1, J1 > > (val);
	}
template<class DataType, int L, int M, int T, int I, int H, int N,  int J, int L1 , int M1 , int T1 , int I1 , int H1 , int N1 ,  int J1 ,
	int L0 , int M0 , int T0 , int I0 , int H0 , int N0 ,  int J0 , int L2 , int M2 , int T2 , int I2 , int H2 , int N2 ,  int J2 >
	Quantity<DataType,Dimensions< L-L0,  M-M0,  T-T0,  I-I0,  H-H0,  N-N0,  J-J0,  L1 ,  M1 ,  T1 ,  I1 , H1, N1, J1 > > 
	operator /(	const Quantity<DataType,Dimensions< L,  M,  T,  I,  H,  N,   J, L1 ,  M1 ,  T1 ,  I1 ,  H1 ,  N1 ,   J1 > >		   &lhs,  
				const Quantity<DataType,Dimensions< L0,  M0,  T0,  I0,  H0,  N0,  J0,  L2 ,  M2 ,  T2 ,  I2 ,  H2 ,  N2 ,   J2 > > &rhs )
	{

		DataType val (lhs.get_value()); 
		 val  /= (rhs.get_value() 
			* int_power(L2, L0)/int_power(L1,L)
			* int_power(M2, M0)/int_power(M1,M)
			* int_power(T2, T0)/int_power(T1,T)
			* int_power(I2, I0)/int_power(I1,I)
			* int_power(H2, H0)/int_power(H1,H)
			* int_power(N2, N0)/int_power(N1,N)
			* int_power(J2, J0)/int_power(J1,J) );
		return Quantity<DataType,Dimensions< L-L0,  M-M0,  T-T0,  I-I0,  H-H0,  N-N0,  J-J0,  L1 ,  M1 ,  T1 ,  I1 , H1, N1, J1 > > (val);
	}
int main()
{
	typedef Dimensions<0,0,1,0,0,0,0> Second;
	typedef Dimensions<0,0,1,0,0,0,0, 1,1,60> Minute;
	typedef Dimensions<1,0,-1,0,0,0,0, 1,1,60> M_PER_Minute;
	typedef Dimensions<0,0,1,0,0,0,0, 1,1,3600> HOUR;
	typedef Dimensions<1,0,-1,0,0,0,0, 1000,1,3600> KM_PER_HOUR;
	typedef Dimensions<1,0,0,0,0,0,0, 1000> KM;
	typedef Dimensions<2,0,0,0,0,0,0, 1000> KM2;
	typedef Dimensions<1,0,0,0,0,0,0 > M;
	typedef Dimensions<2,0,0,0,0,0,0 > M2;
	typedef Dimensions<1,0,-1,0,0,0,0> M_PER_SECOND;
	Quantity<int, Second> a(60);
	Quantity<int, Minute> b(1);
	Quantity<int, M> c(60);
	Quantity<int, M_PER_Minute> d1(c/a);
	Quantity<int, M_PER_Minute> d2(c/b);
	std::cout<<(d1).get_value()<<std::endl;
	std::cout<<(d2).get_value()<<std::endl;
}