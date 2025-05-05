#include<iostream>
using std :: cout;
using std :: endl;

class demo
{
	int iNo1;
	int iNo2;
	
public:
	demo(void)
	{
		cout <<"\tIn Default Constructor.\n";
		iNo1=iNo2=0;
	}

	demo(int iParam)
	{
		cout <<"\tIn Parametrized Constructor 1.\n";
		iNo1=iNo2=iParam;
	}

	demo(int iParam1,int iParam2)
	{
		cout <<"\tIn Parametrized Constructor 2.\n";
		iNo1=iParam1;
		iNo2=iParam2;
	}

	demo(demo &RefObj)
	{
		cout <<"\tIn Copy Constructor 1.\n";
		iNo1=RefObj.iNo1;
		iNo2=RefObj.iNo2;
	}

	demo(demo &RefObj,int iNo)
	{
		cout <<"\tIn Copy Constructor 2.\n";
		iNo1=RefObj.iNo1+iNo;
		iNo2=RefObj.iNo2+iNo;
	}

	/*
	demo(demo &RefObj,int iNo1)
	{
		cout <<"\tIn Copy Constructor 2.\n";
		iNo1=RefObj.iNo1+iNo1;
		iNo2=RefObj.iNo2+iNo1;
	}
	*/

	void Display(void)
	{
		cout << "\t\tiNo1:" << iNo1 << endl;
		cout << "\t\tiNo2:" << iNo2 << "\n\n";
	}

	~demo(void)
	{
		cout <<"\tIn Destructor.\n";
		iNo1=iNo2=0;
	}

	void Fun(demo dObj6)
	{
		cout << "\tiNo1="<< dObj6.iNo1 <<"\t" <<"iNo2="<< dObj6.iNo2 << "\n\n";
	}
};

int main(void)
{
	demo dObj1;				//Default Constructor Get's Called...
	dObj1.Display();
	
	demo dObj2(10);			//Parametrized Constructor 1 Get's Called...
	dObj2.Display();
	
	demo dObj3(20,30);		//Parametrized Constructor 2 Get's Called...
	dObj3.Display();
	
	demo dObj4=dObj3;  	//Copy Constructor 1 Get's Called...
	dObj4.Display();
	
	demo dObj5(dObj4,10);   //Copy Constructor 2 Get's Called....
	dObj5.Display();

	dObj5.Fun(dObj4);
	
	return 0;
}
/*
	o/p:
		In Default Constructor.
                iNo1:0
                iNo2:0

        In Parametrized Constructor 1.
                iNo1:10
                iNo2:10

        In Parametrized Constructor 2.
                iNo1:20
                iNo2:30

        In Copy Constructor 1.
                iNo1:20
                iNo2:30

        In Copy Constructor 2.
                iNo1:30
                iNo2:40

        In Copy Constructor 1.
        iNo1=20 iNo2=30

        In Destructor.
        In Destructor.
        In Destructor.
        In Destructor.
        In Destructor.
        In Destructor.
*/