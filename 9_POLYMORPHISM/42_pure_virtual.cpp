#include <iostream>

class base
{
public :
	void Fun1(int);
	virtual void Fun2(int);
	virtual void Fun3(int) = 0;
	virtual void Fun4(int) = 0;
};

class derived1 : public base
{
public:
	void Fun3(int);
	virtual void Fun5(int);
};

class derived2 : public derived1
{
public:
	void Fun2(int);
	void Fun4(int);
};

int main(void)
{
	//base bObj;
	/*  
		ABOVE : (28) : error C2259: 'base' : cannot instantiate abstract class
				due to following members:
				-->'void base::Fun3(int)' : is abstract
				42_pure_virtual.cpp(8) : see declaration of 'base::Fun3'
				-->'void base::Fun4(int)' : is abstract
				42_pure_virtual.cpp(9) : see declaration of 'base::Fun4'
	*/
	//derived1 dObj1;
	/*  
		ABOVE : (37) : error C2259: 'derived1' : cannot instantiate abstract class
				due to following members:
				-->'void base::Fun4(int)' : is abstract
				42_pure_virtual.cpp(9) : see declaration of 'base::Fun4'
	*/
	
	derived2 dObj2;
	
	dObj2.Fun1(10);		//In base Fun1(10)
	dObj2.Fun2(10);		//In Fun2(10) Redefinition of derived2
	dObj2.Fun3(10);		//In derived1 Fun3(10)
	dObj2.Fun4(10);		//In derived2 Fun4(10)
	dObj2.Fun5(10);		//In derived1 Fun5(10)

	base *bpPtr = &dObj2;
	
	bpPtr->Fun1(10);	//In base Fun1(10)
	bpPtr->Fun2(10);	//In Fun2(10) Redefinition of derived2
	bpPtr->Fun3(10);	//In derived1 Fun3(10)
	bpPtr->Fun4(10);	//In derived2 Fun4(10)
	//bpPtr->Fun5(10);	//Error Not In base:(59) : error C2039: 'Fun5' : is not a member of 'base'
	
	derived1 *dpPtr = &dObj2;
	
	dpPtr->Fun1(10);	//In base Fun1(10)
	dpPtr->Fun2(10);	//In Fun2(10) Redefinition of derived2
	dpPtr->Fun3(10);	//In derived1 Fun3(10)
	dpPtr->Fun4(10);	//In derived2 Fun4(10)
	dpPtr->Fun5(10);	//In derived1 Fun5(10)
	
	/*  
		ABOVE(61-67) : ABOVE ALL o/p ARE ALLOWED BECAUSE THERE IS NO ANY KIND OF HIDDING, BECAUSE NO SAME NAME DEFINITION 
					   IN 'derived1'
	*/
	return 0;
}

//base definition
void base::Fun1(int iParam)
{
	std::cout <<"\nIn base Fun1(10)\n";
}
void base::Fun2(int iParam)
{
	std::cout <<"\nIn base Fun2(10)\n";
}
//derived1 definition
void derived1::Fun3(int iParam)
{
	std::cout <<"\nIn derived1 Fun3(10)\n";
}
void derived1::Fun5(int iParam)
{
	std::cout <<"\nIn derived1 Fun5(10)\n";
}
//derived2 definition
void derived2::Fun2(int iParam)
{
	std::cout <<"\nIn Fun2(10) Redefinition of derived2\n";
}
void derived2::Fun4(int iParam)
{
	std::cout <<"\nIn derived2 Fun4(10)\n";
}
