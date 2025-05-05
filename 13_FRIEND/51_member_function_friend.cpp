#include <iostream>

class demo2
{
public:
	void Fun1(void);
	void Fun2(void);
};

class demo1
{
	friend void demo2::Fun2(void);
	
	int idPri;
	
protected:
	int idPro;
	
public:
	int idPub;
	
	void Fun(void);
};

int main(void)
{
	demo2 dObj2;
	
	dObj2.Fun1();
	
	dObj2.Fun2();
	
	return 0;
}
void demo1::Fun(void)
{
	std::cout <<"\nIn Fun()\n";
}
void demo2::Fun1(void)
{
	std::cout <<"\n-->In Fun1()\n";
	
	demo1 dObj;
	
	//dObj.idPri = 10;	//(43) : error C2248: 'demo1::idPri' : cannot access private member declared in class 'demo1'
	//dObj.idPro = 20;	//(44) : error C2248: 'demo1::idPro' : cannot access protected member declared in class 'demo1'
	dObj.idPub = 30;
	
	//std::cout <<"\nidPri = " << dObj.idPri << std::endl;	//(47) : error C2248: 'demo1::idPri' : cannot access private member declared in class 'demo1'
	//std::cout <<"\nidPro = " << dObj.idPro << std::endl;	//(48) : error C2248: 'demo1::idPro' : cannot access protected member declared in class 'demo1'
	std::cout <<"\nidPub = " << dObj.idPub << std::endl;
	
	dObj.Fun();	
}
void demo2::Fun2(void)
{
	std::cout <<"\n-->In Fun2()\n";
	
	demo1 dObj;
	
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

	In Fun()

	-->In Fun2()

	idPri = 100

	idPro = 200

	idPub = 300

	In Fun()
*/
