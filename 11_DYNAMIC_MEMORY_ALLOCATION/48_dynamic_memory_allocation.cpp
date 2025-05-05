#include <iostream>

class demo
{
	int iNo1;
	int iNo2;

public:
	demo(int);
	demo(void);
	~demo(void);
	demo(int, int);
};

int main(void)
{
	demo *dpPtr1 = NULL;
	demo *dpPtr2 = NULL;
	demo *dpPtr3 = NULL;
	demo *dpPtr4 = NULL;
	demo *dpPtr5 = NULL;
	demo *dpPtr6 = NULL;

	std::cout <<"\nMemory allocation dpPtr1\n";
	
	dpPtr1 = (demo *)malloc(sizeof(demo));
	if(NULL == dpPtr1)
	{
		std::cout <<"\nMemory Allocation Failed.\n";
		return -1;
	}

	std::cout <<"\nMemory allocation dpPtr2\n";
	
	dpPtr2 = new demo;
	if(NULL == dpPtr2)
	{
		std::cout <<"\nMemory Allocation Failed.\n";
		return -1;
	}
	
	std::cout <<"\nMemory allocation dpPtr3\n";
	
	dpPtr3 = new demo(10);
	if(NULL == dpPtr3)
	{
		std::cout <<"\nMemory Allocation Failed.\n";
		return -1;
	}
	
	std::cout <<"\nMemory allocation dpPtr4\n";

	dpPtr4 = new demo[3];
	if(NULL == dpPtr4)
	{
		std::cout <<"\nMemory Allocation Failed.\n";
		return -1;
	}

	std::cout <<"\nMemory allocation dpPtr5\n";

	dpPtr5 = new demo[3];
	if(NULL == dpPtr5)
	{
		std::cout <<"\nMemory Allocation Failed.\n";
		return -1;
	}

	std::cout <<"\nMemory allocation dpPtr6\n";					//C++ 11 standard
/* 
	dpPtr6 = new demo[3] {demo(), demo(10), demo(10,20)};
	if(NULL == dpPtr6)
	{
		std::cout <<"\nMemory Allocation Failed.\n";
		return -1;
	} */

	std::cout <<"\nMemory deallocation dpPtr1\n";
	
	free(dpPtr1);

	std::cout <<"\nMemory deallocation dpPtr2\n";
	
	delete dpPtr2;

	std::cout <<"\nMemory deallocation dpPtr3\n";
	
	delete dpPtr3;

	std::cout <<"\nMemory deallocation dpPtr4\n";
	
	delete []dpPtr4;				//Here code is crash if not mention the array bracket.

	std::cout <<"\nMemory deallocation dpPtr5\n";
	
	delete []dpPtr5;
	
/* 	std::cout <<"\nMemory deallocation dpPtr6\n";

	delete []dpPtr6;
 */	
	return 0;
}
//constructor
demo::demo(void):iNo1(0), iNo2(0)
{
	std::cout <<"\n-->In default demo constructor\n";
}
demo::demo(int iParam): iNo1(iParam), iNo2(iParam)
{
	std::cout <<"\n-->In parametrised constructor 1\n";
}
demo::demo(int iParam1, int iParam2): iNo1(iParam1), iNo2(iParam2)
{
	std::cout <<"\n-->In parametrised constructor 2\n";
}
//destructor
demo::~demo(void)
{
	std::cout <<"\n-->In destructor\n";
}
/*  
	o/p:	
		Memory allocation dpPtr1

		Memory allocation dpPtr2

		-->In default demo constructor

		Memory allocation dpPtr3

		-->In parametrised constructor 1

		Memory allocation dpPtr4

		-->In default demo constructor

		-->In default demo constructor

		-->In default demo constructor

		Memory allocation dpPtr5

		-->In default demo constructor

		-->In default demo constructor

		-->In default demo constructor

		Memory deallocation dpPtr1

		Memory deallocation dpPtr2

		-->In destructor

		Memory deallocation dpPtr3

		-->In destructor

		Memory deallocation dpPtr4

		-->In destructor

		-->In destructor

		-->In destructor

		Memory deallocation dpPtr5

		-->In destructor

		-->In destructor

		-->In destructor
*/