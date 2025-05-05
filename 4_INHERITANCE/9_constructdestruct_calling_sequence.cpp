#include <iostream>
using std :: cout;

class base
{
public:
	base(void)
	{
		cout << "In default base constructor.\n";
	}
	
	base(int iParam)
	{
		cout << "In Parametrized base constructor.\n";
	}
	
	~base(void)
	{
		cout << "In base destructor.\n";
	}
};

class derived : base
{
public:
	derived(void)
	{
		cout << "In default derived constructor.\n";
	}
	
	derived(int iParam) : base(iParam)
	{
		cout << "In Parametrized derived constructor.\n";
	}
	
	~derived(void)
	{
		cout << "In derived destructor.\n";
	}
};

int main(void)
{
	derived dObj;
	derived dObj2(10);
	
	return 0;
}
