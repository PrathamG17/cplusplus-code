#include <iostream>

class base
{
protected:
	int iNo1;
	float fNo2;
	char chChar3;
	
public:
	base(void);
	virtual ~base(void);
};

class derived : public base
{
	int iNo4;
	float fNo5;
	char chChar6;
	
public:
	derived(void);
	~derived(void);
	void Display(void);
};

int main(void)
{
	base bObj;
	
	derived dObj;
	
	//dObj.Display();

	base *bpPtr = new derived;
	if(NULL == bpPtr)
	{
		std::cout <<"\nMemory Allocation Failed\n";
		return -1;
	}
	
	delete bpPtr;
	
	return 0;
}
//base 
base::base(void):iNo1(0),fNo2(0.0f),chChar3('A')
{
	std::cout <<"\nIn default base Constructor\n";
}
base::~base(void)
{
	std::cout <<"\nIn base destructor\n";
}
//derived
derived::derived(void):iNo4(10),fNo5(10.10f),chChar6('B')
{
	std::cout <<"\nIn default derived constructor\n";
}
derived::~derived(void)
{
	std::cout <<"\nIn derived destructor\n";
}
void derived::Display(void)
{
	std::cout <<"dObj.iNo1 = " << iNo1 << std::endl;
	std::cout <<"dObj.fNo2 = " << fNo2 << std::endl;
	std::cout <<"dObj.chChar3 = " << chChar3 << std::endl;
	std::cout <<"dObj.iNo4 = " << iNo4 << std::endl;
	std::cout <<"dObj.fNo5 = " << fNo5 << std::endl;
	std::cout <<"dObj.chchar6 = " << chChar6 << std::endl;
	
	printf("\nflaot fNo1 = %f & fNo2 = %f\n", fNo2, fNo5);
}
/*  
	o/p:
	
		In default base Constructor

		In default base Constructor

		In default derived constructor
		dObj.iNo1 = 0
		dObj.fNo2 = 0
		dObj.chChar3 = A
		dObj.iNo4 = 10
		dObj.fNo5 = 10.1
		dObj.chchar6 = B

		flaot fNo1 = 0.000000 & fNo2 = 10.100000
		In derived destructor-----------[as function stack frame goes i.e 'sp' shifts from higher address to lower address]
										[Hence derived Object destroy first.]
		In base destructor

		In base destructor

*/
/*  
	virtual destructor o/p(1):
	In default base Constructor

	In default base Constructor

	In default derived constructor
------------------------------------------||
	In default base Constructor

	In default derived constructor

	In base destructor
------------------------------------------||
	In derived destructor

	In base destructor

	In base destructor
*/
/*  
	vistual destructor o/p(2):
	
	In default base Constructor

	In default base Constructor

	In default derived constructor
--------------------------------------------------||
	In default base Constructor

	In default derived constructor

	In derived destructor

	In base destructor
--------------------------------------------------||
	In derived destructor

	In base destructor

	In base destructor
*/