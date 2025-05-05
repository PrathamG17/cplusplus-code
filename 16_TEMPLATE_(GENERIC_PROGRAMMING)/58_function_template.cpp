#include <iostream>

class demo
{
public :
	int Max(int iNo1,int iNo2);
	
	template <typename T>
	T Max(T iNo1,T iNo2);
	
	template <typename T>
	T Max(T iNo1,T iNo2,T iNo3);
	
	template <typename T1,typename T2>
	void Max(T1 iNo1,T2 iNo2);
};

int main(void)
{
	demo dObj;
	
	dObj.Max(10,20,30);				//Template 2 Max-->Normal Max-->Normal Max.
	dObj.Max('A','B');				//Template 1 Max
	dObj.Max(57.33,69.33);			//Template 1 Max
	dObj.Max(57.33f,69.33f);		//Template 1 Max
	dObj.Max<float>(57.33,69.33);	//Template 3 Max
	dObj.Max(10,20);				//Normal Max
	dObj.Max<>(10,20);				//Template 1 Max
	dObj.Max(10,'A');				//Normal Max
	dObj.Max(10,20,'A');			//(30) : error C2660: 'demo::Max' : function does not take 3 arguments
	
	return 0;
}

int demo:: Max(int iNo1,int iNo2)
{
	std::cout << "In Normal Max." << std::endl;
	
	if(iNo1 > iNo2)
		return iNo1;
	return iNo2;
}

template <typename T>
T demo:: Max(T iNo1,T iNo2)
{
	std::cout << "In Template 1 Max." << std::endl;
	
	if(iNo1 > iNo2)
		return iNo1;
	return iNo2;
}

template <typename T>
T demo:: Max(T iNo1,T iNo2,T iNo3)
{
	std::cout << "In Template 2 Max." << std::endl;
	return Max(iNo1,Max(iNo2,iNo3));
}

template <typename T1,typename T2>
void demo:: Max(T1 iNo1,T2 iNo2)
{
	std::cout << "In Template 3 Max.\n";
	std::cout << "size of (T1) is " << sizeof(T1) << std::endl;
	std::cout << "size of (T2) is " << sizeof(T2) << std::endl;
}
