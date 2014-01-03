class B{
protected:
	B(){}
};
class D:virtual private B{
public: D()
		{
		}
};
//class D2:public D{
//public:
//	D2(){}
//};
//int main()
//{
//	D d1;
//	//D2 d;
//}