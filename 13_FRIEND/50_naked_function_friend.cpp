#include <iostream>

void Fun1(void);
void Fun2(void);

class demo
{
	friend void Fun2(void);
	
	int idPri;

protected:
	int idPro;

public:
	int idPub;
	
	void Fun(void);
};

int main(void)
{
	Fun1();

	Fun2();
	
	return 0;
}

void demo::Fun(void)
{
	std::cout <<"\nIn Fun1()\n";
}
void Fun1(void)
{
	std::cout <<"\n-->In Fun1()\n";
	
	demo dObj;
	
	//dObj.idPri = 10;	//(38) : error C2248: 'demo::idPri' : cannot access private member declared in class 'demo'
	//dObj.idPro = 20;	//(39) : error C2248: 'demo::idPro' : cannot access protected member declared in class 'demo'
	dObj.idPub = 30;
	
	//std::cout <<"\nidPri = " << dObj.idPri << std::endl;	//(42) : error C2248: 'demo::idPri' : cannot access private member declared in class 'demo'
	//std::cout <<"\nidPro = " << dObj.idPro << std::endl;	//(43) : error C2248: 'demo::idPro' : cannot access protected member declared in class 'demo'
	std::cout <<"\nidPub = " << dObj.idPub << std::endl;
	
	dObj.Fun();
}

void Fun2(void)
{
	std::cout <<"\n-->In Fun2()\n";

	demo dObj;
	
	dObj.idPri = 100;
	dObj.idPro = 200;
	dObj.idPub = 300;
	
	std::cout <<"\nidPri = " << dObj.idPri << std::endl;
	std::cout <<"\nidPro = " << dObj.idPro << std::endl;
	std::cout <<"\nidPub = " << dObj.idPub << std::endl;
	
	dObj.Fun();	
}
/*  
	o/p:
	-->In Fun1()

	idPub = 30

	In Fun1()

	-->In Fun2()

	idPri = 100

	idPro = 200

	idPub = 300

	In Fun1()
*/