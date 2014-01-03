#define A 100

int foo()
{
	int b = A+A;
	return b;
}

#define B 333

int foo2()
{
	int c = A+B;
	return b;
}

extern int c;
