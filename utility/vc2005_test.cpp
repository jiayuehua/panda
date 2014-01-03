struct B
{
	B operator ++(int)
	{
		B tmp = *this;
		++b;
		return tmp;
	}
	B& operator ++()
	{
		++b;
		return * this;
	}
	int get()const
	{
		return b;
	}
	explicit B(int t):b(t){}
private:
	int b;
};

template<class T>
T too(const T & b)
{
	return b;
}

int main()
{
	int i(100);
	//++too(i);
	//too(i)++;
	B b(100);
	++too(b);
	too(b)++;
}