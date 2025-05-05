#include <iostream>
using namespace std;

class demo
{
	int iNo1;
	int iNo2;

public :
	demo()
	{
		iNo1 = iNo2 = 0;
	}
	
	demo(int iParam1,int iParam2)
	{
		iNo1 = iParam1;
		iNo2 = iParam2;
	}
	
	int Addition()
	{
		return iNo1 + iNo2;
	}
};

int main(void)
{
	int iAns,iNo1,iNo2;
	demo dObj;
	
	iAns = dObj.Addition();
	cout << "dObj : Addition is " << iAns << endl;
	
	cout << "Enter Two Numbers : ";
	cin >> iNo1 >> iNo2;
	
	demo dObj1(iNo1,iNo2);
	iAns = dObj1.Addition();
	cout << "dObj : Addition is " << iAns << endl;
		
	return 0;
}
