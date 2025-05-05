#include <iostream>
using std :: cout;
using std :: endl;

class demo
{
	int iNo1;
	int iNo2;
	
public :
	demo(int iNo1 = 10,int iNo2 = 20):iNo1(iNo1),iNo2(iNo2)
	{
		cout << "In Constructor." << endl;
	}
	void Display();
	demo operator +();
	demo operator -();
	demo operator ~();
	demo& operator --();
	demo& operator ++();
 	demo operator ++(int);
	demo operator --(int);
};

int main(void)
{
	demo dObj1(30,40);
	demo dObj2;
	
	/* dObj2 = +dObj1;
	dObj2.Display(); */
	
	/* dObj2 = -dObj1;
	dObj2.Display(); */
	
	dObj2 = ~dObj1;
	dObj2.Display();
	
	/* dObj2 = ++dObj1;
	dObj2.Display(); */

	/* dObj2 = dObj1++;
	dObj1.Display(); */

	/* dObj2 = --dObj1;
	dObj2.Display(); */
	
	/* dObj2 = dObj1--;
	dObj1.Display(); */

	return 0;
}

demo demo :: operator +()
{
	cout <<"In Unary Addition Operator." << endl;
	return demo(iNo1,iNo2);
}

demo demo :: operator -()
{
	cout << "In Unary Subtraction Operator." << endl;
	return demo(-iNo1,-iNo2);
}

demo  demo :: operator ~()
{
	cout <<"In Unary Negation Operator." << endl;
	return demo(~iNo1,~iNo2);
}

demo&  demo :: operator ++()
{
	cout <<"In Unary Pre-Increment Operator." << endl;
	++iNo1;
	++iNo2;
	return *this;
}

demo  demo :: operator ++(int)
{
	cout << "In Post-Increment Operator." << endl;
	demo dObj(this->iNo1,this->iNo2);
	this->iNo1++;
	this->iNo2++;
	return dObj;
}
	
demo&  demo :: operator --()
{
	cout <<"In Unary Pre-Decrement Operator." << endl;
	--(this->iNo1);
	--(this->iNo2);
	return *this;
}

demo  demo :: operator --(int)
{
	cout << "In Post-Decrement Operator." << endl;
	demo dObj(iNo1,iNo2);
	iNo1--;
	iNo2--;
	return dObj;
}

void  demo :: Display()
{
	cout << "iNo1 is = " << iNo1 << endl;
	cout << "iNo2 is = " << iNo2 << endl;
}
