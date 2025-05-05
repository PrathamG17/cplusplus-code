#include <iostream>
using std :: cout;
using std :: endl;

class demo
{
	int iNo1;
	static int iNo2;
	
public:
	void Fun1()
	{
		iNo1=10;
		iNo2=20;
		this->iNo1=10;
		this->iNo2=20;
	}
	
	static void Fun2()
	{
		iNo1=10;
		iNo2=20;
		this->iNo1=10;
		this->iNo2=20;		
	}
};

int demo :: iNo2;

int main(void)
{
	demo dObj;
	
	dObj.Fun1();
	dObj.Fun2();
	
	demo :: Fun1();
	demo :: Fun2();
	
	return 0;
}
