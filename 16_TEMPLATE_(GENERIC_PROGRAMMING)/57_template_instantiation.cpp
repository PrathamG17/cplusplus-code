#include <iostream>

class demo
{
	int iNo1;
	
public :
	template <typename T>
	T Addition(T iNo1,T iNo2);

	//Multiple Generic Parameters.
	template <typename T1,typename T2>
	T1 Subtraction(T1 iNo1,T2 iNo2);
	
	//Non-Template Parameters.
	template <typename T>
	float Division(T iParam,int iDivisor);	
};

int main(void)
{
	demo dObj;
	double iAns;
	
	iAns = dObj.Addition<int>(57.33,69.33);
	
	//Above <int> i.e. explicit template instantiation
	
	std::cout << "Addition is = " << iAns << std::endl;		//Addition is = 126

	float fAns;
	
	fAns = dObj.Subtraction(100,23.77);
	std::cout << "Subtraction is = " << fAns << std::endl;	//Subtraction is = 76

	fAns = dObj.Division(10.20f,2);
	std::cout << "Quotient is = " << fAns << std::endl;		//Quotient is = 5.1

	return 0;
}

template <typename T>
T demo:: Addition(T iNo1,T iNo2)
{
	return (iNo1 + iNo2);
}

template <typename T1,typename T2>
T1 demo:: Subtraction(T1 iNo1,T2 iNo2)
{
	return (iNo1 - iNo2);
}

template <typename T>
float demo:: Division(T iParam,int iDivisor)
{
	return (iParam / iDivisor);
}
