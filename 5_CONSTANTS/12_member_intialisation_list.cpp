#include <iostream>
using std :: cout;
using std :: endl;

class demo
{
	int iNo1;
	int iNo2;
	int iNo3;
	
public:
	demo(int iParam) : iNo3(++iParam), iNo1(++iParam), iNo2(++iParam)
	{
	}
	
	void Display(void)
	{
		cout << "iNo1=" << iNo1 << endl;
		cout << "iNo2=" << iNo2 << endl;
		cout << "iNo3=" << iNo3 << endl;
	}
};

int main(void)
{
	demo dObj(10);
	dObj.Display();
	
	return 0;
}
