#include <iostream>
using std :: cout;
using std :: endl;

class demo
{
	int iNo1;

public:
	void Fun1(void)
	{
		iNo1=10;
	}

	void Fun2(void)
	{
		this->iNo1=20;
	}

	demo * Fun3(void)
	{
		this->iNo1=30;
		
		return this;
	}

	demo Fun4(void)
	{
		this->iNo1=40;
		
		return *this;
	}

	void Display(void)
	{
		cout <<"\n\tiNo1=" << this->iNo1 << endl;
	}
};

int main(void)
{
	demo dObj1;
	demo *pPtr=NULL;
	
	dObj1.Display();
	
	dObj1.Fun1();
	dObj1.Display();

	dObj1.Fun2();
	dObj1.Display();

	pPtr=dObj1.Fun3();
	pPtr->Display();

	demo dObj2=dObj1.Fun4();
	dObj2.Display();
	
	return 0;
}
