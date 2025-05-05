#include <iostream>

int main(void)
{
	int iAns;
	int iNumerator;
	int iDenominator;
	
	try
	{
		std::cout <<"\nEnter Denominator : ";
		std::cin >> iDenominator;
		
		std::cout <<"\nEnter Numerator : ";
		std::cin >> iNumerator;
		
		if(0 == iDenominator)
			throw iNumerator;
		else
			iAns = iNumerator % iDenominator;
	}
	catch(int iException)
	{
		std::cout <<"\nDivide By '0' Exception Found.\n";
		std::cout <<"\nCan't Divide " << iException << std::endl;
		exit(-1);					// or return -1;
	}
	
	std::cout <<"\nRemainder = " << iAns << std::endl;
	
	return 0;
}
