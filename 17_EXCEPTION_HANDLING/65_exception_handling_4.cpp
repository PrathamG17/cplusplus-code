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
	catch(int iExpression)
	{
		std::cout <<"\nInteger Exception Found\n";
	}
	catch(float fException)
	{
		std::cout <<"\nFloat Exception Found\n";
	}
	catch(double *dException)
	{
		std::cout <<"\nPointer Exception Found\n";
	}
	catch(char chException)
	{
		std::cout <<"\ncharacter Exception Found\n";
	}
	
	return 0;
}

template <typename T>
void Fun(T Param)
{
	std::cout <<"\nsizeof param_type : " << sizeof T << std::endl;
	
	try
	{
		if(1 == sizeof T)
			throw Param;
		else if(4 == sizeof T)
			throw Param;
	}
	catch(...)
	{
		std::cout <<"\nRethrowing Exception\n";
		throw;
	}
	
	std::cout <<"\nException Not Found\n";
}
