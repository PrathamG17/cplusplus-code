#include <iostream>
using std :: cout;
using std :: endl;
using std :: cin;

class demo
{
	int iData;
	static demo *pPtr;
	
	demo(void)
	{
		iData=20;
	}
	
public:
	static demo * demo :: Get_Object(void)
	{
		if(NULL == pPtr)
		{
			pPtr = new demo();
			if(NULL == pPtr)
				return NULL;
				
			cout << "Object Created." << endl;
		}
		else
		{
			bool bret;
			
			cout << "You can't create another object of singleton class." << endl;
			cout << "You want to use existing object?\n";
			cin >> bret;
			
			if(false == bret)
				return NULL;
		}
		return pPtr;
	}
	
	static void Delete_Object(void)
	{
		if(pPtr != NULL)
		{
			delete pPtr;
			pPtr=NULL;
			
			cout << "Object Deleted.\n";
		}
	}
	
	void Set_Data(int iParam)
	{
		cout << "Setting Data.." << iParam << endl;
		iData = iParam;
	}
	
	void Get_Data(void)
	{
		cout << "Data is.." << iData << endl;
	}
};
demo * demo :: pPtr = NULL;

int main(void)
{
	//demo dObj;
	
	demo *pPtr1 = NULL;
	
	cout << "pPtr1:\n";
	pPtr1 = demo :: Get_Object();
	
	if(NULL == pPtr1)
		return -1;
		
	pPtr1->Set_Data(10);
	pPtr1->Get_Data();
	pPtr1->Delete_Object();
	
	demo *pPtr2 = NULL;

	cout << "pPtr2:\n";
	pPtr2 = demo :: Get_Object();
	
	if(NULL == pPtr2)
		return -1;
		
	pPtr2->Set_Data(1000);
	pPtr2->Get_Data();
	
	cout << "pPtr1:\n";
	pPtr1->Get_Data();
	
	demo :: Delete_Object();
	
	return 0;
}
