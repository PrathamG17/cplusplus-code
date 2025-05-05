#include <iostream>

class base
{
	int bPri;
	
protected:
	int bPro;
	
public:
	int bPub;
	
	void Fun(void)
	{
		bPri=10;
		bPro=20;
		bPub=30;
	}
};
class derived1 : private base
{
	int dPri;
	
protected:
	int dPro;
	
public:
	int dPub;
	
	void Fun(void)
	{
		bPri=10;
		bPro=20;
		bPub=30;
		dPri=40;
		dPro=50;
		dPub=60;
	}
};
class derived2 : private derived1
{
public:
	void Fun(void)
	{
		bPri=10;
		bPro=20;		
		bPub=30;
		dPri=40;
		dPro=50;
		dPub=60;
	}
};

int main(void)
{
	base bObj;
	derived1 dObj1;
	derived2 dObj2;
	
	bObj.bPri=10;
	bObj.bPro=20;
	bObj.bPub=30;
	
	bObj.dPub=30;
	
	dObj1.bPri=10;
	dObj1.bPro=20;	//inaccessible
	dObj1.bPub=30;	//inaccessible
	dObj1.dPri=40;
	dObj1.dPro=50;
	dObj1.dPub=60;
	
	dObj2.bPri=10;
	dObj2.bPro=20;
	dObj2.bPub=30;
	dObj2.dPri=40;
	dObj2.dPro=50;	//inaccessible
	dObj2.dPub=60;	//inaccessible
	
	bObj.Fun();
	dObj1.Fun();
	dObj2.Fun();
	
	return 0;
}
