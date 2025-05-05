#include <iostream>
using std :: cout;
using std :: endl;

class demo
{
public:
	demo()
	{
		cout << "\t\t\t-->In Constructor." << endl;
	}
	
	~demo()
	{
		cout << "\t\t\t-->In Destructor." << endl;
	}
};

void Fun1(void);
void Fun2(void);

int main(void)
{
	cout << "\t#In main()" << endl;
	
	cout << "\t\t1)Calling Fun1()" << endl;
	Fun1();
	
	cout << "\t\t2)Calling Fun2()" << endl;
	Fun2();
	
	cout << "\t#Leaving main()" << endl;
	
	return 0;
}

void Fun1(void)
{
	cout << "\t\t\t**In Fun1()**" << endl;
	
	demo dObj;
	
	cout << "\t\t\t**Leaving Fun1()**" << endl;
}

void Fun2(void)
{
	cout << "\t\t\t**In Fun2()**" << endl;
	
	static demo dObj;
	
	cout << "\t\t\t**Leaving Fun2()**" << endl;
}
