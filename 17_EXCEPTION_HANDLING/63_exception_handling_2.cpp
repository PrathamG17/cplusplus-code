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
	
	if(1 == sizeof T)
		throw Param;
	else if(4 == sizeof T)
		throw Param;
	else
		std::cout <<"\nException Not Found\n";
}
/*  
	o/p:
	-->case_1:
		sizeof param_type : 4

		Integer Exception Found

	-->case_2:
		sizeof param_type : 4

		Float Exception Found
		
	-->case_3:
		sizeof param_type : 8		[It's double case]

		Exception Not Found
	
	-->case_4:
		sizeof param_type : 1

		character Exception Found
	
	-->case_5:
		sizeof param_type : 4
	
		Pointer Exception Found
*/
