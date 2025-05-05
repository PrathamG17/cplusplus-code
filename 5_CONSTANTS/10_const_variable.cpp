#include <iostream>
using std :: cout;
using std :: endl;

extern const int iNo=10;

void Fun(void);

int main(void)
{
	cout << "Address Of const int iNo=" << &iNo << endl;
	Fun();
	
	return 0;
}
