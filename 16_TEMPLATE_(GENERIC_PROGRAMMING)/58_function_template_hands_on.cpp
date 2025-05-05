#include <iostream>

class demo
{
public:
	int Max(int, int);
	
	template <typename T>
	T Max(T,T);
	
	template <typename T>
	T Max(T,T,T);
};

int main(void)
{
	demo dObj;
	
	std::cout <<"\nIn 'main()' call\n";
	
	dObj.Max(10,20,30);				//Template 2 Max-->Normal Max-->Normal Max.
	
	std::cout <<"\nIn 'main()' call\n";

	dObj.Max('A','B');				//Template 1 Max
	
	std::cout <<"\nIn 'main()' call\n";

	dObj.Max(57.33,69.33);			//Template 1 Max		//template instantiation with double.
	
	std::cout <<"\nIn 'main()' call\n";
	
	dObj.Max(57.33f,69.33f);		//Template 1 Max

	std::cout <<"\nIn 'main()' call\n";

	dObj.Max<float>(57.33,69.33);	//Template 3 Max		//Explicit template instantiation.
	
	std::cout <<"\nIn 'main()' call\n";
	
	dObj.Max(10,20);				//Normal Max
	
	std::cout <<"\nIn 'main()' call\n";

	dObj.Max<>(10,20);				//Template 1 Max

	std::cout <<"\nIn 'main()' call\n";

	dObj.Max(10,'A');				//Normal Max
	
	//dObj.Max(10,20,'A');			//(30) : error C2660: 'demo::Max' : function does not take 3 arguments

	return 0;
}

int demo::Max(int iParam1, int iParam2)
{
	std::cout <<"\n\t-->In Normal\n";
	
	if(iParam1 > iParam2)
		return iParam1;
	
	return iParam2;
}

template <typename T>
T demo::Max(T iParam1, T iParam2)
{
	std::cout <<"\n\t-->In Template 1\n";
	
	if(iParam1 > iParam2)
		return iParam1;
	
	return iParam2;
}

template <typename T>
T demo::Max(T iParam1, T iParam2, T iParam3)
{
	std::cout <<"\n\t-->In Template 2\n";
	
	return Max(iParam1, Max(iParam2, iParam3));
}
