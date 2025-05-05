#include <iostream>
using std :: cout;
using std :: endl;

class demo
{
	int iNo1;
	int iNo2;
	mutable int iNo3;
	
public:
	void Fun(const int iNo)const
	{
		cout << "iNo=" << iNo << endl;
		
		/* iNo1=10;
		iNo2=20;
		this->iNo1=30;
		this->iNo2=40; */
		((demo *)this)->iNo1=50;
		const_cast<demo *>(this)->iNo2=60;
		iNo3=70;
		this->iNo3=75;
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
	demo dObj;
	
	dObj.Fun(10);
	dObj.Display();
	
	return 0;
}
