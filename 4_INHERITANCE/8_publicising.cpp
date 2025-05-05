#include <iostream>
using std :: cout;

class base
{
	void Fun1(void)
	{
		cout << "In Fun 1.\n";
	}
	
public:
	void Fun2(void)
	{
		cout << "In Fun 2.\n";
	}
	
	void Fun2(int)
	{
		cout << "In Place-Holder Fun 2.\n";
	}
	
	void Fun3(void)
	{
		cout << "In Fun 3.\n";
	}
	
protected:
	void Fun4(void)
	{
		cout << "In Fun 4.\n";
	}
	
	void Fun5(void)
	{
		cout << "In Fun 5.\n";
	}
};

class derived : private base
{
public:
	//using base :: Fun1;
	base :: Fun2;
	base :: Fun4;
};

int main(void)
{
	derived dObj;
	
	//dObj.Fun1();
	dObj.Fun2();
	dObj.Fun2(10);
	//dObj.Fun3();
	dObj.Fun4();
	//dObj.Fun5();

	return 0;
}
