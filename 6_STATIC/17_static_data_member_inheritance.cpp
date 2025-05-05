#include <iostream>
using std :: cout;
using std :: endl;

class base
{
public:
	int iNo1;
	static int iNo2;
	
	base(): iNo1(10)
	{
		cout << "In Default Constructor." << endl;
	}
};
int base :: iNo2=20;
class derived : public base
{

};

int main(void)
{
	base bObj;
	derived dObj;
	
	cout << sizeof(base) << sizeof(bObj) << endl;
	cout << sizeof(derived) << sizeof(dObj) << endl;
	
	cout << bObj.iNo1 << endl;
	//cout << base :: iNo1 << endl;
	
	cout << bObj.iNo2 << dObj.iNo2 << endl;
	cout << base :: iNo2 << derived :: iNo2 << endl;
	
	cout << "Before Increment." << endl;
	
	cout << bObj.iNo1 << dObj.iNo1 << endl;
	cout << bObj.iNo2 << dObj.iNo2 << endl;
	cout << base :: iNo2 << derived :: iNo2 << endl;
	
	bObj.iNo1++;
	bObj.iNo2++;
	
	cout << "After Increment." << endl;
	
	cout << bObj.iNo1 << dObj.iNo1 << endl;
	cout << bObj.iNo2 << dObj.iNo2 << endl;
	cout << base :: iNo2 << derived :: iNo2 << endl;
	
	return 0;
}
