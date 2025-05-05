#include <iostream>
using std :: cout;
using std :: endl;

class demo
{
	int iNo;
	int &Ref;
	
public :
	demo() : Ref(iNo),iNo(10)
	{
		cout << "In default constructor.\n";
	}
	
	void Display()
	{
		cout << iNo << "\t" << Ref << endl;
		cout << &iNo << "\t" << &Ref << endl;
	}
};

void Fun(int &Ref);

int main(void)
{
 	char chChar = 'A';
	char &Ref = chChar;	
	int *pPtr=NULL;
	
	char chChar1 = 'B';
	char &Prefer=chChar1;
	
	char chArr[2] = {Ref,Prefer};
	
	char (&Ref1)[2] = chArr;
	
	char (*pPtr1) = &Ref;
	
	char * &Ref2 = pPtr1;
	
	cout << Ref << "\t"<< &Ref << "\t" << sizeof(&Ref) << "\t-->" << sizeof(int *) << endl;
	cout << Prefer << endl;

	cout << Ref1[0] << Ref1[1] << endl;
	
	cout << *pPtr1 << endl;
	
	cout << Ref2 << endl;
	
	const int &Ref3 = 10;
		
	cout << Ref3 << endl;
	
 
 //REFERENCE AS A DATA MEMBER
	demo dObj;
	
	dObj.Display();
	
	cout << sizeof(dObj) << endl;
	
 //CALL BY REFERENCE
	
	int iNo=10;
	
	Fun(iNo);
	
	cout << iNo << endl;
	
	return 0;
}
void Fun(int &Ref)
{
	Ref++;
}
