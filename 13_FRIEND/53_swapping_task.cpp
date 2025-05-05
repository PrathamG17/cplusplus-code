#include <iostream>

class demo1;
class demo2;

void Swap(demo1& , demo2&);

class demo1
{
	friend void Swap(demo1& , demo2&);

	int iNo;
	
public:
	void Scan(void);
	void Display(void);
};

class demo2
{
	friend void Swap(demo1& , demo2&);

	int iNo;
	
public:
	void Scan(void);
	void Display(void);
};

int main(void)
{
	demo1 dObj1;
	
	dObj1.Scan();
	
	dObj1.Display();
	
	demo2 dObj2;
	
	dObj2.Scan();
	
	dObj2.Display();
	
	Swap(dObj1, dObj2);
	
	std::cout <<"\nAfter Swapping\n";
	
	dObj1.Display();
	
	dObj2.Display();
	
	return 0;
}
//demo1 definition
void demo1::Scan(void)
{
	std::cout <<"\nEnter Integer : ";
	std::cin >> iNo;
}
void demo1::Display(void)
{
	std::cout <<"\nIn demo1::iNo = " << iNo << std::endl;
}
//demo2 definition
void demo2::Scan(void)
{
	std::cout <<"\nEnter Integer : ";
	std::cin >> iNo;	
}
void demo2::Display(void)
{
	std::cout <<"\nIn demo2::iNo = " << iNo << std::endl;	
}
//naked definition
void Swap(demo1 &d1Ref, demo2 &d2Ref)
{
	d1Ref.iNo = d1Ref.iNo + d2Ref.iNo;
	d2Ref.iNo = d1Ref.iNo - d2Ref.iNo;
	d1Ref.iNo = d1Ref.iNo - d2Ref.iNo;
}
/*  
	o/p:
	
	Enter Integer : 1250

	In demo1::iNo = 1250

	Enter Integer : 1350

	In demo2::iNo = 1350

	After Swapping

	In demo1::iNo = 1350

	In demo2::iNo = 1250
*/
