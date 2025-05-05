#include <iostream>

class base
{
protected:
	int iNo;
	int iNo1;
	
public:
	base(void);
};

class derived1: virtual public base
{
protected:
	int iNo;
	int iNo2;
	
public:
	derived1(void);
};

class derived2: virtual public base
{
protected:
	int iNo;
	int iNo3;
	
public:
	derived2(void);
};

class derived: public derived2, public derived1
{
public:
	derived(void);
	void Display(void);
};

int main(void)
{
	std::cout <<"\nbObj creating now..\n";
	
	base bObj;
	
	std::cout <<"\ndObj1 creating now..\n";
	
	derived1 dObj1;
	
	std::cout <<"\ndObj2 creating now..\n";
	derived2 dObj2;
	
	std::cout <<"\ndObj creating now..\n";
	derived dObj;

	dObj.Display();
	
	return 0;
}

base::base(void)
{
	std::cout <<"\n\t-->In base constructor\n";
	
	iNo = 10;
	iNo1 = 100;
}

derived1::derived1(void)
{
	std::cout <<"\n\t-->In derived1 constructor\n";
	iNo = 20;
	iNo2 = 200;
}

derived2::derived2(void)
{
	std::cout <<"\n\t-->In derived2 constructor\n";
	iNo = 30;
	iNo3 = 300;
}

derived::derived(void)
{
	std::cout <<"\n\t-->In derived constructor\n";
}

void derived::Display(void)
{
	std::cout <<"\nbase::iNo = " << base::iNo << std::endl;
	std::cout <<"\nderived1::iNo = " << derived1::iNo << std::endl;
	std::cout <<"\nderived2::iNo = " << derived2::iNo << std::endl;
	std::cout <<"\niNo1 = " << iNo1 << std::endl;
	std::cout <<"\niNo2 = " << iNo2 << std::endl;
	std::cout <<"\niNo3 = " << iNo3 << std::endl;
}
/*  
	o/p:
	
		bObj creating now..

				-->In base constructor

		dObj1 creating now..

				-->In base constructor

				-->In derived1 constructor

		dObj2 creating now..

				-->In base constructor

				-->In derived2 constructor

		dObj creating now..

				-->In base constructor

				-->In derived2 constructor

				-->In derived1 constructor

				-->In derived constructor

		base::iNo = 10

		derived1::iNo = 20

		derived2::iNo = 30

		iNo1 = 100

		iNo2 = 200

		iNo3 = 300

*/