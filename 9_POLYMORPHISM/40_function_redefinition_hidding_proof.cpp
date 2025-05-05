#include <iostream>

class base
{
public :
	void Fun1(int iParam)
	{
		std::cout <<"\nIn base Fun1(10)\n";
	}
	void Fun1(int iParam1, int iParam2)
	{
		std::cout <<"\nIn base Fun1(10,20)\n";
	}
	void Fun2(int iParam)
	{
		std::cout <<"\nIn base Fun2(10)\n";
	}
	void Fun2(int iParam1, int iParam2, int iParam3)
	{
		std::cout <<"\nIn base Fun2(10,20,30)\n";
	}
	void Fun3(int iParam)
	{
		std::cout <<"\nIn base Fun3(10)\n";
	}
};

class derived : public base
{
public :
	void Fun1(int iParam1)
	{
		std::cout << "\nIn Derived Fun1\n";
	}
	
	void Fun2(int iParam1, int iParam2)
	{
		std::cout << "\nIn derived Fun2(10,20)\n";
	}
};

int main(void)
{
	derived dObj;
	base * bpPtr = &dObj;
	
	bpPtr->Fun1(10);		//In base Fun1(10)
	
	bpPtr->Fun1(10, 20);	//In base Fun1(10, 20)
	
	bpPtr->Fun2(10);		//In base Fun2(10)
	
	//bpPtr->Fun2(10, 20);	//Error as not in base:(53) : error C2661: 'base::Fun2' : no overloaded function takes 2 arguments
	
	bpPtr->Fun2(10, 20, 30);	//In base Fun2(10, 20, 30)
	
	bpPtr->Fun3(10);		//In base Fun3(10)
	
	return 0;
}
