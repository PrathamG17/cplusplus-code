#include <iostream>
#include <exception>

template <typename T>
void Fun(T);

void MyTerminate(void);

int main(void)
{
	std::set_terminate(MyTerminate);
	
	try
	{
		Fun('A');
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

	return 0;
}

template <typename T>
void Fun(T Param)
{
	std::cout <<"\nsizeof T = " << sizeof T << std::endl;
	
	if(1 == sizeof T)
		throw Param;
	else if(4 == sizeof T)
		throw Param;
	
	std::cout <<"\nException Not Found\n";
}

void MyTerminate(void)
{
	std::cout <<"\nIn Myterminate\n";
	exit(-1);
}
