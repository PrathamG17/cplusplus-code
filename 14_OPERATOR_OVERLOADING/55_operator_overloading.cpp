#include <iostream>

class demo
{	
public:
	int iNo;

	void operator -(void);
	void operator -(demo&);
	void operator +(void);
	void operator +(demo&);
};

int main(void)
{
	demo dObj1;
	
	dObj1.iNo = 10;
	
	-dObj1;
	
	std::cout <<"\ndObj.iNo = " << dObj1.iNo << std::endl;		//dObj.iNo = -10
	
	dObj1.iNo = -10;
	
	-dObj1;
	
	std::cout <<"\ndObj.iNo = " << dObj1.iNo << std::endl;		//dObj.iNo = 10
	
	demo dObj2;
	
	dObj2.iNo = 5;

	dObj1 - dObj2;
	
	std::cout <<"\ndObj.iNo = " << dObj1.iNo << std::endl;		//dObj.iNo = 5
	
	dObj1 + dObj2;
	
	std::cout <<"\ndObj.iNo = " << dObj1.iNo << std::endl;		//dObj.iNo = 10
	
	return 0;
}

void demo::operator -(void)
{
	iNo = -iNo;
}

void demo::operator -(demo &dRef)
{
	iNo = iNo - dRef.iNo;
}

void demo::operator +(void)
{
	iNo = +iNo;
}

void demo::operator +(demo &dRef)
{
	iNo = iNo + dRef.iNo;
}
