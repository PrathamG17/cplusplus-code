#include <iostream>
#include <exception>
#include <cstdlib>

template <typename T>
void Fun(T);

void MyUnexpected(void);

int main(void)
{
	double dNo;
		
	std::set_unexpected(MyUnexpected);
	
	try
	{
		Fun('A');
	}
	catch(...)
	{
		std::cout <<"\nException Found\n";
	}
	
	return 0;
}

template <typename T>
void Fun(T Param) throw(int, float)
{
	try
	{
		if(1 == sizeof T)
			throw Param;
		else if(4 == sizeof T)
			throw Param;
		else
			std::cout <<"\nException Found\n";
	}
	catch(...)
	{
		throw;
	}
}

void MyUnexpected(void)
{
	std::cout <<"\nIn My Unexpected\n";
	exit(-1);
}
