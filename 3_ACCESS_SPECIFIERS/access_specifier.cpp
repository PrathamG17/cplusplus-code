#include <iostream>
using std :: cout;
using std :: endl;

class base
{
	int bPri;
	
protected:
	int bPro;
	
public:
	int bPub;
	
	void Fun(void);	
	void Display(void);
};
class derived : base
{
public:
	void Fun(void);
};
int main(void)
{
	base bObj;
	
	//bObj.bPri=100;
	//bObj.bPro=200;
	bObj.bPub=300;
	bObj.Fun();
	bObj.Display();
	
	derived dObj;
	dObj.Fun();
	
	return 0;
}
void base :: Fun(void)
{
	bPri=10;
	bPro=20;
	bPub=30;
}

void base :: Display(void)
{
	cout << "bPri=" << bPri << endl;
	cout << "bPro=" << bPro << endl;
	cout << "bPub=" << bPub << endl; 
}
void derived :: Fun(void)
{
	//bPri=10;
	bPro=20;
	bPub=30;
}	
