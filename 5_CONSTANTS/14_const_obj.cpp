#include <iostream>
using std :: cout;

class demo
{
public:
	demo(void)
	{
		
	}
	
	void Fun1(void)
	{
		cout << "In Non-Constant member function.\n";
	}
	
	void Fun2(void)const
	{
		cout << "In Constant member function.\n";
	}
};

int main(void)
{
	demo dObj1;
	const demo dObj2;
	
	dObj1.Fun1();
	dObj1.Fun2();
	
	dObj2.Fun1();	//discards qualifiers..
	dObj2.Fun2();
	
	return 0;
}
