#include <iostream>

class base
{
public:
	base(void);
	~base(void);
	void Fun1(void);
};
class derived: public base
{
public :
	derived(void);
	~derived(void);
	void Fun2(void);
};

int main(void)
{
	derived dObj;
	
	return 0;
}
//base
base::base(void)
{
	std::cout <<"\nIn default base constructor\n";
	Fun1();
}
base::~base(void)
{
	std::cout <<"\nIn base destructor\n";
	Fun1();
}
void base::Fun1(void)
{
	std::cout <<"\nIn base::Fun1()\n";
}
//derived
derived::derived(void)
{
	std::cout <<"\nIn default derived Constructor\n";
	Fun1();
	Fun2();
}
derived::~derived(void)
{
	std::cout <<"\nIn derived destructor\n";
	Fun1();
	Fun2(); 
}
void derived::Fun2(void)
{
	std::cout <<"\nIn derived::Fun2()\n";
}
/*  
	o/p:
	In default base constructor

	In base::Fun1()

	In default derived Constructor

	In base::Fun1()

	In derived::Fun2()		[Object Creation]
	------------------------------
	In derived destructor	[Object Destruction]

	In base::Fun1()

	In derived::Fun2()

	In base destructor

	In base::Fun1()
	
	[All o/p are depending upon access specifier that which identifier that i can identify or i can point it by its name.]
*/
