#include <iostream>
using std :: cout;
using std :: endl;

class demo
{
	int iNo1;
	int iNo2;

public :
	demo(int iNo1 = 10,int iNo2 = 20): iNo1(iNo1),iNo2(iNo2)
	{
		cout << "In Constructor." << endl;
	}
	
	void Display();
	bool operator <(demo &RefObj2);
	bool operator >(demo &RefObj2);
	demo operator +(demo &RefObj2);
	demo operator -(demo &RefObj2);
	demo operator *(demo &RefObj2);
	demo operator <<(demo &RefObj2);
	demo operator >>(demo &RefObj2);
	bool operator ==(demo &RefObj2);
	demo operator / (demo &RefObj2);
	demo& operator +=(demo &RefObj2);
};

int main(void)
{
	demo dObj1(100,200);
	demo dObj2;
	demo dObj3;
	
	/* dObj3 = dObj1 + dObj2;
	cout << "In dObj1." << endl;
	dObj1.Display();
	cout << "In dObj2." << endl;
	dObj2.Display();
	cout << "In dObj3." << endl;
	dObj3.Display(); */
	
	/* dObj3 = dObj1 - dObj2;
	cout << "In dObj1." << endl;
	dObj1.Display();
	cout << "In dObj2." << endl;
	dObj2.Display();
	cout << "In dObj3." << endl;
	dObj3.Display(); */
	
	/* dObj3 = dObj1 * dObj2;
	cout << "In dObj1." << endl;
	dObj1.Display();
	cout << "In dObj2." << endl;
	dObj2.Display();
	cout << "In dObj3." << endl;
	dObj3.Display(); */
	
	/* dObj3 = dObj1 / dObj2;
	cout << "In dObj1." << endl;
	dObj1.Display();
	cout << "In dObj2." << endl;
	dObj2.Display();
	cout << "In dObj3." << endl;
	dObj3.Display(); */
	
	/* dObj1 += dObj2;
	cout << "In dObj1." << endl;
	dObj1.Display();
	cout << "In dObj2." << endl;
	dObj2.Display(); */
	
	/* dObj3 = dObj1 << dObj2;
	cout << "In dObj1." << endl;
	dObj1.Display();
	cout << "In dObj2." << endl;
	dObj2.Display();
	cout << "In dObj3." << endl;
	dObj3.Display(); */
	
	/* dObj3 = dObj1 >> dObj2;
	cout << "In dObj1." << endl;
	dObj1.Display();
	cout << "In dObj2." << endl;
	dObj2.Display();
	cout << "In dObj3." << endl;
	dObj3.Display(); */
	
	/* if(dObj1 == dObj2)
		cout << "Wrong Result." << endl;
	else 
		cout << "True Result." << endl; */
	
	/* if(dObj1 < dObj2)
		cout << "Wrong Result." << endl;
	else 
		cout << "True Result." << endl; */
	
	if(dObj1 > dObj2)
		cout << "True Result." << endl;
	else 
		cout << "Wrong Result." << endl;
	
	return 0;
}

demo demo :: operator +(demo &RefObj2)
{
	cout << "In Binary Addition Operator." << endl;
	return demo(this->iNo1 + RefObj2.iNo1,this->iNo2 + RefObj2.iNo2);
}

demo demo :: operator -(demo &RefObj2)
{
	cout << "In Binary Subtraction Operator." << endl;
	return demo(iNo1 - RefObj2.iNo1,iNo2 - RefObj2.iNo2);
}

demo demo :: operator *(demo &RefObj2)
{
	cout << "In Binary Multiplication Operator." << endl;
	return demo(iNo1 * RefObj2.iNo1,iNo2 * RefObj2.iNo2);
}

demo demo :: operator / (demo &RefObj2)
{
	cout << "In Binary Division Operator." << endl;
	return demo(iNo1 / RefObj2.iNo1,iNo2 / RefObj2.iNo2);
}

demo& demo :: operator +=(demo &RefObj2)
{
	cout << "In Binary += Operator." << endl;
	
	iNo1 += RefObj2.iNo1;
	iNo2 += RefObj2.iNo2;
	
	/* this->iNo1 = this->iNo1 + RefObj2.iNo1;
	this->iNo2 = this->iNo2 +RefObj2.iNo2; */
	
	return *this;
}

demo demo :: operator <<(demo &RefObj2)
{
	cout << "In Binary Left Shift Operator." << endl;
	return demo(iNo1 << RefObj2.iNo1,iNo2 << RefObj2.iNo2);
}

demo demo :: operator >>(demo &RefObj2)
{
	cout << "In Binary Right Shift Operator." << endl;
	return demo(iNo1 >> RefObj2.iNo1,iNo2 >> RefObj2.iNo2);
}

bool demo :: operator ==(demo &RefObj2)
{
	cout << "In Binary Equal To Operator." << endl;
	return ((iNo1 == RefObj2.iNo1 ) && (iNo2 == RefObj2.iNo2));
}

bool demo :: operator <(demo &RefObj2)
{
	cout << "In Binary Less Than Operator." << endl;
	return ((iNo1 < RefObj2.iNo1) && (iNo2 < RefObj2.iNo2));
}

bool demo :: operator >(demo &RefObj2)
{
	cout << "In Binary Greater Than Operator." << endl;
	return ((iNo1 > RefObj2.iNo1) && (iNo2 > RefObj2.iNo2));
}

void demo :: Display()
{
	cout << "iNo1 = " << iNo1 << endl;
	cout << "iNo2 = " << iNo2 << endl;
}
