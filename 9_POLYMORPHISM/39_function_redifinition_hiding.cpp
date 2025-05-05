#include <iostream>

class base
{
public :
	void Fun1(int iParam)
	{
		std::cout <<"\nIn Fun1(10)\n";
	}
	void Fun1(int iParam1, int iParam2)
	{
		std::cout <<"\nIn Fun1(10,20)\n";
	}
	void Fun2(int iParam)
	{
		std::cout <<"\nIn Fun2(10)\n";
	}
	void Fun2(int iParam1, int iParam2, int iParam3)
	{
		std::cout <<"\nIn Fun2(10,20,30)\n";
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
	
	dObj.Fun1(10);				//In derived Fun1(10)
	
	//dObj.Fun2(10,20,30);		//Error Function hidding :(48) : error C2660: 'derived::Fun2' : function does not take 3 arguments
	
	//dObj.Fun2(10);			//Error Function Hidding :(50) : error C2660: 'derived::Fun2' : function does not take 1 arguments
	
	dObj.Fun2(10,20);			//In derived Fun2(10,20)
	
	dObj.Fun3(10);				//In base Fun3(10)
	
	return 0;
}
