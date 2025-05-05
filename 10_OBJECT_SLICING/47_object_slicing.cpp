#include <iostream>

class base
{
public:
	int iNo1;
	int iNo2;
	
	base(void);
	void Fun1(void);
};
class derived : public base
{
public:
	int iNo1;
	int iNo2;
	
	derived(void);
	void Fun2(void);
	void Fun(base);
};

int main(void)
{
	derived dObj;
	
	dObj.iNo1 = dObj.iNo2 = 10;
	dObj.iNo1 = dObj.iNo2 = 20;
	/*  
		ABOVE: derived class data members are assigned here. again & again
	*/
	dObj.Fun(dObj);

	return 0;
}
base::base(void): iNo1(30), iNo2(30)
{
	std::cout <<"\nIn default base constructor\n";
}

derived::derived(void):iNo1(0),iNo2(0)
{
	std::cout <<"\nIn default derived constructor\n";
}
void derived::Fun(base bObj)
{
	std::cout <<"\nbObj.iNo1 = " << bObj.iNo1 << std::endl;
	std::cout <<"\nbObj.iNo2 = " << bObj.iNo2 << std::endl;
	//std::cout <<"\nbObj.iNo3 = " << bObj.iNo3 << std::endl;	//Error Not in base:(59) : error C2039: 'iNo3' : is not a member of 'base'
	
	bObj.Fun1();
	//bObj.Fun2();	//Error Not in base:(62) : error C2039: 'Fun2' : is not a member of 'base'
}
void base::Fun1(void)
{
	std::cout <<"\nIn base Fun1()\n";
}
void derived::Fun2(void)
{
	std::cout <<"\nIn derived Fun2()\n";
}
/* [When constructor was not defined] 
	case 1: o/p:
			
		bObj.iNo1 = 10

		bObj.iNo2 = 10

		In base Fun1()
		
	case 2: o/p:
		
		bObj.iNo1 = 11533648

		bObj.iNo2 = 14193026

		In base Fun1()
		
	[When constructor defined with same name of data members]
	case 1: o/p:
	
		In default base constructor

		In default derived constructor

		bObj.iNo1 = 30

		bObj.iNo2 = 30

		In base Fun1()
*/
