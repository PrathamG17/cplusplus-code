#include <iostream>

template <typename T>
void Fun(T);

int main(void)
{
	double dNo;
	
	try
	{
		Fun(&dNo);
	}
	catch(...)
	{
		std::cout <<"\nException Found\n";
	}
	
	return 0;
}

template <typename T>
void Fun(T Param) throw(int, float, char)
{
	std::cout <<"\nsizeof T = " << sizeof T << std::endl;
	
	if(1 == sizeof T)
		throw Param;
	else if(4 == sizeof T)
		throw Param;
	
	std::cout <<"\nException Found\n";
}
