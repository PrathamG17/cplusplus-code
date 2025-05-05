#include <iostream>

class base
{
public:
	virtual void Fun(void) = 0;
};

class derived : public base
{
public:
	void Fun(void);
};

int main(void)
{
	//base bObj;
	/*  
		ABOVE :(17) : error C2259: 'base' : cannot instantiate abstract class
					  due to following members:
					  -->'void base::Fun(void)' : is abstract
					  43_partial_definition.cpp(6) : see declaration of 'base::Fun'
	*/
	derived dObj;
	
	//base::Fun();
	/*  
		ABOVE : (26) : error C2352: 'base::Fun' : illegal call of non-static member function
					   43_partial_definition.cpp(6) : see declaration of 'base::Fun'
	*/
	
	dObj.Fun();
	
	return 0;
}
//Partial Definition
void base::Fun(void)
{
	std::cout <<"\nIn base::Fun()\n";
}
//Derived Definition
void derived::Fun(void)
{
	std::cout <<"\nIn derived::Fun()\n";
	base::Fun();
}
