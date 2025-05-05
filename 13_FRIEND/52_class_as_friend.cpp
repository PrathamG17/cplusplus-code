#include <iostream>

class demo2;

class demo1
{
	friend class demo2;
	
	int idPri;
	
protected:
	int idPro;
	
public:
	int idPub;
	
	void Fun(void);
};

class demo2
{
public:
	void Fun1(void);
	void Fun2(void);
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
	
	dObj.idPri = 10;
	dObj.idPro = 20;
	dObj.idPub = 30;
	
	std::cout <<"\nidPri = " << dObj.idPri << std::endl;
	std::cout <<"\nidPro = " << dObj.idPro << std::endl;
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

	idPri = 10

	idPro = 20

	idPub = 30

	In Fun()

	-->In Fun2()

	idPri = 100

	idPro = 200

	idPub = 300

	In Fun()
*/
