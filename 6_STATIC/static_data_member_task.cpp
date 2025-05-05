#include<iostream>
using std :: cout;
using std :: endl;

class demo
{
	int iData;
	static int iBorn;
	static int iDead;
	
public:

	demo(void)
	{
		iBorn++;
		iData=10;
	}
	
	static void demo :: Display(void)
	{
		cout << "\n\tTotal Objects Are :" << iBorn << endl;
		cout << "\n\t\tTotal Living Objects Are :" << iBorn-iDead << endl;
	}
	
	~demo(void)
	{
		iData=0;
		iDead++;
	}
};
int demo :: iBorn;
int demo :: iDead;

void Fun(void);

int main(void)
{
	demo :: Display();
	
	demo dObj1;
	
	dObj1.Display();
	
	Fun();
	
	dObj1.Display();
	
	return 0;
}

void Fun(void)
{
	demo dObj2;
	
	dObj2.Display();
}
