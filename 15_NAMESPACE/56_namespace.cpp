#include <iostream>
namespace one
{
	int iNo1;
	int iNo2;
}

namespace two
{
	int iNo1;
	int iNo2;
}

namespace
{
	float fNo = 11.11f;
}

using std :: cout;
using std :: endl;

//Method 1
using namespace one;

//Method 2
//using one :: iNo1;

//Method 3 in main

//Un-Named Namespace 

//int iNo1=5;					

int main(void)
{	
	/* cout << "iNo1 = " << one ::iNo1 << endl;
	cout << "iNo2 = " << one :: iNo2 << endl;
	cout << "iNo1 = " << two :: iNo1 << endl;
	cout << "iNo2 = " << two :: iNo2 << endl; */
	
	cout << iNo1 << endl;		//(36) : error C2872: 'iNo1' : ambiguous symbol
		
	cout << fNo << endl;
	return 0;
}
