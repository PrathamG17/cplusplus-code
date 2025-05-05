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
	
	demo * This()
	{	
		cout << "In This()." << endl;
		return this;
	}
	
	friend void Display(demo &RefObj);
	friend demo operator -(demo &RefObj);
	friend demo operator ~(demo &RefObj);
	friend demo& operator +(demo &RefObj);
	friend demo& operator ++(demo &RefObj);
	friend demo& operator --(demo &RefObj);
	friend demo * operator &(demo &RefObj);
	friend demo operator --(demo &RefObj,int);
	friend demo operator ++(demo &RefObj,int);
};

void Display(demo &RefObj);
demo operator -(demo &RefObj);
demo operator ~(demo &RefObj);
demo& operator ++(demo &RefObj);
demo& operator +(demo &RefObj);
demo& operator --(demo &RefObj);
demo * operator &(demo &RefObj);
demo operator ++(demo &RefObj,int);
demo operator --(demo &RefObj,int);

int main(void)
{
	demo dObj1(100,200);
	demo dObj2;
	
	/* dObj2 = +dObj1;
	Display(dObj2); */
	
	/* dObj2 = -dObj1;
	Display(dObj2); */
	
	/* dObj2 = ~dObj1;
	cout << "In dObj1." << endl;
	Display(dObj1);
	cout << "In dObj2." << endl;
	Display(dObj2); */
	
	cout << "Address Of dObj1 = " << &dObj1 << endl;
	cout << "Address Of dObj2 = " << &dObj2 << endl;

	/* dObj2 = ++dObj1;
	cout << "In dObj1." << endl;
	Display(dObj1);
	cout << "In dObj2." << endl;
	Display(dObj2); */
	
	/* dObj2 = dObj1++;
	cout << "In dObj1." << endl;
	Display(dObj1);
	cout << "In dObj2." << endl;
	Display(dObj2); */
	
	/* dObj2 = --dObj1;
	cout << "In dObj1." << endl;
	Display(dObj1);
	cout << "In dObj2." << endl;
	Display(dObj2); */
	
	/* dObj2 = dObj1--;
	cout << "In dObj1." << endl;
	Display(dObj1);
	cout << "In dObj2." << endl;
	Display(dObj2); */
	
	return 0;
}

demo& operator +(demo &RefObj)
{
	cout <<"In Unary Addition Operator." << endl;
	return RefObj;
}

demo operator -(demo &RefObj)
{
	cout << "In Unary Subtration Operator." << endl;
	return demo(-RefObj.iNo1,-RefObj.iNo2);
}

demo operator ~(demo &RefObj)
{
	cout << "In Unary Bitwise Operator." << endl;
	return demo(~RefObj.iNo1,~RefObj.iNo2);
}

demo& operator ++(demo &RefObj)
{
	cout << "In Unary Pre-Increment Operator." << endl;
	++RefObj.iNo1;
	++RefObj.iNo2;
	return RefObj;
}

demo operator ++(demo &RefObj,int)
{
	cout << "In Post-Increment Operator." << endl;
	demo dObj(RefObj.iNo1,RefObj.iNo2);
	RefObj.iNo1++;
	RefObj.iNo2++;
	return dObj;
}

demo& operator --(demo &RefObj)
{
	cout << "In Pre-Decrement Operator." << endl;
	--RefObj.iNo1;
	--RefObj.iNo2;
	return 	RefObj;	//demo(RefObj.iNo1,RefObj.iNo2);
}

demo operator --(demo &RefObj,int)
{
	cout << "In Post-Decrement Operator." << endl;
	demo dObj(RefObj.iNo1,RefObj.iNo2);
	RefObj.iNo1--;
	RefObj.iNo2--;
	return dObj;
}

demo * operator &(demo &RefObj)
{
	cout << "In Unary Address Of Operator." << endl;
	return RefObj.This();
}

void Display(demo &RefObj)
{
	cout << "iNo1 = "<< RefObj.iNo1 << endl;
	cout << "iNo2 = "<< RefObj.iNo2 << endl;
}
