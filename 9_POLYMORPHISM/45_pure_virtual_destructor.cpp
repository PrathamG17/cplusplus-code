#include <iostream>

class base
{
public:
	base(void);
	virtual ~base(void) = 0;
};

class derived : public base
{
public:
	derived(void);
	~derived(void);
};

int main(void)
{
	//base bObj;
	/*  
		ABOVE:(19) : error C2259: 'base' : cannot instantiate abstract class
					 due to following members:
					 -->'base::~base(void)' : is abstract
					 45_pure_virtual_destructor.cpp(7) : see declaration of 'base::~base'

		ABOVE(19): Target is to stop creating objects of 'base' class. Without passing any dependency on child class, when we
				   see such thing in pure virtual behaviours,that until all behaviours would not define the object of class
				   would not created.
	*/
	derived dObj;
	
	return 0;
}
base::base(void)
{
	std::cout <<"\nIn default base constructor\n";
}
base::~base(void)
{
	std::cout <<"\nIn base destructor\n";
}

derived::derived(void)
{
	std::cout <<"\nIn default derived Constructor\n";
}
derived::~derived(void)
{
	std::cout <<"\nIn derived destructor\n";
}
