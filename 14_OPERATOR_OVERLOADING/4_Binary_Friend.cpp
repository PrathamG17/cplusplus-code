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
	
	friend void Display(demo &RefObj);
	friend demo operator +(demo &RefObj1,demo &RefObj2);
	friend demo operator -(demo &RefObj1,demo &RefObj2);
	friend demo operator *(demo &RefObj1,demo &RefObj2);
	friend bool operator <(demo &RefObj1,demo &RefObj2);
	friend bool operator >(demo &RefObj1,demo &RefObj2);
	friend demo operator <<(demo &RefObj1,demo &RefObj2);
	friend demo operator >>(demo &RefObj1,demo &RefObj2);
	friend bool operator ==(demo &RefObj1,demo &RefObj2);
	friend demo operator / (demo &RefObj1,demo &RefObj2);
	friend demo& operator +=(demo &RefObj1,demo &RefObj2);
};

int main(void)
{
	demo dObj1(100,200);
	demo dObj2;
	demo dObj3;
	
	/* dObj3 = dObj1 + dObj2;
	cout << "In dObj1." << endl;
	Display(dObj1);
	cout << "In dObj2." << endl;
	Display(dObj2);
	cout << "In dObj3." << endl;
	Display(dObj3); */
	
	/* dObj3 = dObj1 - dObj2;
	cout << "In dObj1." << endl;
	Display(dObj1);
	cout << "In dObj2." << endl;
	Display(dObj2);
	cout << "In dObj3." << endl;
	Display(dObj3); */
	
	/* dObj3 = dObj1 * dObj2;
	cout << "In dObj1." << endl;
	Display(dObj1);
	cout << "In dObj2." << endl;
	Display(dObj2);
	cout << "In dObj3." << endl;
	Display(dObj3); */
	
	/* dObj3 = dObj1 / dObj2;
	cout << "In dObj1." << endl;
	Display(dObj1);
	cout << "In dObj2." << endl;
	Display(dObj2);
	cout << "In dObj3." << endl;
	Display(dObj3); */
	
	/* dObj1 += dObj2;
	cout << "In dObj1." << endl;
	Display(dObj1);
	cout << "In dObj2." << endl;
	Display(dObj2); */
	
	/* dObj3 = dObj1 << dObj2;
	cout << "In dObj1." << endl;
	Display(dObj1);
	cout << "In dObj2." << endl;
	Display(dObj2);
	cout << "In dObj3." << endl;
	Display(dObj3); */
	
	/* dObj3 = dObj1 >> dObj2;
	cout << "In dObj1." << endl;
	Display(dObj1);
	cout << "In dObj2." << endl;
	Display(dObj2);
	cout << "In dObj3." << endl;
	Display(dObj3); */
	
	/* if(dObj1 == dObj2)
		cout << "Wrong Result." << endl;
	else 
		cout << "True Result." << endl; */
	
	/* if(dObj1 < dObj2)
		cout << "Wrong Result." << endl;
	else 
		cout << "True Result." << endl; */
	
	/* if(dObj1 > dObj2)
		cout << "True Result." << endl;
	else 
		cout << "Wrong Result." << endl; */
	
	return 0;
}

demo operator +(demo &RefObj1,demo &RefObj2)
{
	cout << "In Binary Addition Operator." << endl;
	return demo(RefObj1.iNo1 + RefObj2.iNo1,RefObj1.iNo2 + RefObj2.iNo2);
}

demo operator -(demo &RefObj1,demo &RefObj2)
{
	cout << "In Binary Subtraction Operator." << endl;
	return demo(RefObj1.iNo1 - RefObj2.iNo1,RefObj1.iNo2 - RefObj2.iNo2);
}

demo operator *(demo &RefObj1,demo &RefObj2)
{
	cout << "In Binary Multiplication Operator." << endl;
	return demo(RefObj1.iNo1 * RefObj2.iNo1,RefObj1.iNo2 * RefObj2.iNo2);
}

demo operator / (demo &RefObj1,demo &RefObj2)
{
	cout << "In Binary Division Operator." << endl;
	return demo(RefObj1.iNo1 / RefObj2.iNo1,RefObj1.iNo2 / RefObj2.iNo2);
}

demo& operator +=(demo &RefObj1,demo &RefObj2)
{
	cout << "In Binary += Operator." << endl;
	
	RefObj1.iNo1 += RefObj2.iNo1;
	RefObj1.iNo2 += RefObj2.iNo2;
	
	/* RefObj1.iNo1 = RefObj1.iNo1 + RefObj2.iNo1;
	RefObj1.iNo2 = RefObj1.iNo2 +RefObj2.iNo2;*/
	
	return RefObj1;
}

demo operator <<(demo &RefObj1,demo &RefObj2)
{
	cout << "In Binary Left Shift Operator." << endl;
	return demo(RefObj1.iNo1 << RefObj2.iNo1,RefObj1.iNo2 << RefObj2.iNo2);
}

demo operator >>(demo &RefObj1,demo &RefObj2)
{
	cout << "In Binary Right Shift Operator." << endl;
	return demo(RefObj1.iNo1 >> RefObj2.iNo1,RefObj1.iNo2 >> RefObj2.iNo2);
}

bool operator ==(demo &RefObj1,demo &RefObj2)
{
	cout << "In Binary Equal To Operator." << endl;
	return ((RefObj1.iNo1 == RefObj2.iNo1 ) && (RefObj1.iNo2 == RefObj2.iNo2));
}

bool operator <(demo &RefObj1,demo &RefObj2)
{
	cout << "In Binary Less Than Operator." << endl;
	return ((RefObj1.iNo1 < RefObj2.iNo1) && (RefObj1.iNo2 < RefObj2.iNo2));
}

bool operator >(demo &RefObj1,demo &RefObj2)
{
	cout << "In Binary Greater Than Operator." << endl;
	return ((RefObj1.iNo1 > RefObj2.iNo1) && (RefObj1.iNo2 > RefObj2.iNo2));
}

void Display(demo &RefObj)
{
	cout << "iNo1 = " << RefObj.iNo1 << endl;
	cout << "iNo2 = " << RefObj.iNo2 << endl;
}
