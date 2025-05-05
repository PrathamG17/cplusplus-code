#include <iostream>

class base1
{
protected:
	int iNo;
	int iNo1;
	
public:
	base1(void);
};

class base2
{
protected:
	int iNo;
	int iNo2;

public:
	base2(void);
};

class derived : public base1, public base2
{
protected:
	int iNo;
	int iNo3;
	
public:
	derived(void);
	void Display(void);
};

int main(void)
{
	derived dObj;
	
	dObj.Display();
	/*  
		o/p:
			iNo = 30				//this->iNo

			base1::iNo = 10			//base1::iNo

			base2::iNo = 20			//base2::iNo

			iNo1 = 100				//base1::iNo1

			iNo2 = 200				//base2::iNo2

			iNo3 = 300				//this->iNo3
	*/
	
	std::cout <<"\nsizeof dObj : " << sizeof dObj << std::endl;		//sizeof dObj : 24
	
	return 0;
}

base1::base1(void)
{
	iNo = 10;
	iNo1 = 100;
}

base2::base2(void)
{
	iNo = 20;
	iNo2 = 200;
}

derived::derived(void)
{
	iNo = 30;
	iNo3 = 300;
}

void derived::Display(void)
{
	std::cout <<"\niNo = " << iNo << std::endl;
	std::cout <<"\nbase1::iNo = " << base1::iNo << std::endl;
	std::cout <<"\nbase2::iNo = " << base2::iNo << std::endl;
	std::cout <<"\niNo1 = " << iNo1 << std::endl;
	std::cout <<"\niNo2 = " << iNo2 << std::endl;
	std::cout <<"\niNo3 = " << iNo3 << std::endl;
}
