#include <iostream>

class demo
{
	int iNo1;
	const int iNo2;
	
public:
	demo(void) : iNo1(10), iNo2(20)
	{
	}
	
	void Fun1(void)
	{
		iNo1=30;
		iNo2=40;
	}
	
	void Fun2(void)const
	{
		iNo1=50;
		iNo2=60;
	}
	
	void Fun3(demo *const pPtr)const
	{
		iNo1=70;
		iNo2=80;
		this->iNo1=90;
		this->iNo2=100;
		pPtr->iNo1=110;
		pPtr->iNo2=120;
	}
};

int main(void)
{
	demo dObj;
	
	dObj.Fun1();
	dObj.Fun2();
	dObj.Fun3(&dObj);
	
	return 0;
}
