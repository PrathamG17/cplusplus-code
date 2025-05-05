#include <iostream>
using std :: cout;
using std :: endl;

class demo
{
	int iNo1;
	const int iNo2;
	
public:
	demo(void) : iNo2(0)
	{
		iNo1=0;
	}
	
	demo(int iParam) : iNo2(iParam)
	{
		iNo1=iParam;
	}
	
	void Display(void)
	{
		cout << "iNo1=" << iNo1 << endl;
		cout << "const int iNo2=" << iNo2 << endl;
	}
};

int main(void)
{
	demo dObj1;
	demo dObj2(10);
	
	dObj1.Display();
	dObj2.Display();
	
	return 0;
}
