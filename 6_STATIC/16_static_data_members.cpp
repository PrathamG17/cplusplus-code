#include <iostream>
using std :: cout;
using std :: endl;

class demo
{
public:
	int iNo1;
	static int iNo2;
	
	demo():iNo1(10)
	{
		cout << "In default constructor." << endl;
	}
};
int demo :: iNo2=20;

int main(void)
{
	demo dObj1;
	demo dObj2;
	
	cout << sizeof(demo) << sizeof(dObj1) << sizeof(dObj2) << endl;
	
	cout << dObj1.iNo1 << endl;
	//cout << demo :: iNo1 << endl;
	cout << dObj1.iNo2 << endl;
	cout << demo :: iNo2 << endl;
	
	cout << "Before Increment." << endl;
	
	cout << dObj1.iNo1 << dObj2.iNo2 << endl;
	cout << dObj1.iNo2 << dObj2.iNo2 << demo :: iNo2 << endl;
	
	dObj1.iNo1++;
	demo :: iNo2++;
	
	cout << "After Increment." << endl;

	cout << dObj1.iNo1 << dObj2.iNo2 << endl;
	cout << dObj1.iNo2 << dObj2.iNo2 << demo :: iNo2 << endl;
		
	return 0;
}
