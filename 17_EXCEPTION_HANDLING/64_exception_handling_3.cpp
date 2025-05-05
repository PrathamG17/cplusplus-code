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
void Fun(T Param)
{
	std::cout <<"\nsizeof param_type : " << sizeof T << std::endl;
	
	if(1 == sizeof T)
		throw Param;
	else if(4 == sizeof T)
		throw Param;
	else
		std::cout <<"\nException Not Found\n";
}
