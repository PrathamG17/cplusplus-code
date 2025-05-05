#include <iostream>

class base
{
public :
	virtual void Fun1(int);
	void Fun1(int, int);
	virtual void Fun2(int);
	void Fun2(int, int);
	virtual void Fun3(int);
	void Fun3(int, int);
};
class derived1 : public base
{
public:
	void Fun1(int);
	void Fun1(int, int, int);
	virtual void Fun2(int, int);
	void Fun2(int, int, int);
	void Fun3(int);
	virtual void Fun3(int, int);
	virtual void Fun4(int);
};

class derived2 : public derived1
{
public:
	void Fun1(int);
	void Fun1(int, int);
	void Fun2(int, int);
	void Fun2(int, int, int);
	void Fun3(int, int);
	virtual void Fun5(int);
};

int main(void)
{
 	derived1 dObj1;
/*	
	dObj1.Fun1(10);					//In derived Fun1(10)
	//dObj1.Fun1(10, 20);			//Error as hidding
	dObj1.Fun1(10, 20, 30);			//In derived Fun1(10, 20, 30)
	//dObj1.Fun2(10);				//Error as hiding
	dObj1.Fun2(10, 20);				//In derived1 Fun2(10, 20)
	dObj1.Fun2(10, 20, 30);			//In derived1 Fun2(10, 20, 30)
	dObj1.Fun3(10);					//In derived Fun3(10)
	dObj1.Fun3(10, 20);				//In derived Fun3(10, 20)
	//dObj1.Fun3(10, 20, 30);		//Error as not in base
	dObj1.Fun4(10);					//In derived Fun4(10)
	//dObj1.Fun5(10);				//Error Not in base
*/	
	derived2 dObj2;
/*	
	dObj2.Fun1(10);					//In derived2 Fun1(10)
	dObj2.Fun1(10, 20);				//In derived2 Fun1(10, 20)
	//dObj2.Fun1(10, 20, 30);		//Error as hidden:(57) : error C2661: 'derived2::Fun1' : no overloaded function takes 3 arguments
	//dObj2.Fun2(10);				//Error as hidden:(58) : error C2661: 'derived2::Fun2' : no overloaded function takes 1 arguments
	dObj2.Fun2(10, 20);				//In derived2 Fun2(10, 20)
	dObj2.Fun2(10, 20, 30);			//In derived2 Fun2(10, 20, 30)
	//dObj2.Fun3(10);				//Error as hidden:(61) : error C2660: 'derived2::Fun3' : function does not take 1 arguments
	dObj2.Fun3(10, 20);				//In derived2 Fun3(10, 20)
	//dObj2.Fun3(10, 20, 30);		//Error as not in class:(63) : error C2660: 'derived2::Fun3' : function does not take 3 arguments
	dObj2.Fun4(10);					//In derived1 Fun4(10)
	dObj2.Fun5(10);					//In derived2 Fun5(10)
*/	
/*	base &bRef1 = dObj1;
	
	bRef1.Fun1(10);					//In derived1 Fun1(10)
	bRef1.Fun1(10, 20);				//In base Fun(10, 20)
	//bRef1.Fun1(10, 20, 30);		//Error not in base:(71) : error C2661: 'base::Fun1' : no overloaded function takes 3 arguments
	bRef1.Fun2(10);					//In base Fun2(10)
	bRef1.Fun2(10, 20);				//In base Fun2(10, 20)
	//bRef1.Fun2(10, 20, 30);		//Error not in base:(74) : error C2661: 'base::Fun2' : no overloaded function takes 3 arguments
	bRef1.Fun3(10);					//In derived1 Fun3(10)
	bRef1.Fun3(10, 20);				//In base Fun3(10, 20)
	//bRef1.Fun3(10, 20, 30);		//Error not in base:(77) : error C2661: 'base::Fun3' : no overloaded function takes 3 arguments
	//bRef1.Fun4(10);				//Error not in base:(78) : error C2039: 'Fun4' : is not a member of 'base'
	//bRef1.Fun5(10);				//Error not in base:(79) : error C2039: 'Fun5' : is not a member of 'base'
*/
	base &bRef2 = dObj2;
/*	
	bRef2.Fun1(10);					//In derived2 Fun1(10)	
	bRef2.Fun1(10, 20);				//In base Fun(10, 20)
	//bRef2.Fun1(10, 20, 30);		//Error Not In base:(84) : error C2661: 'base::Fun1' : no overloaded function takes 3 arguments
	bRef2.Fun2(10);					//In base Fun2(10)
	bRef2.Fun2(10, 20);				//In base Fun2(10, 20)
	//bRef2.Fun2(10, 20, 30);		//Error Not In base:(87) : error C2661: 'base::Fun2' : no overloaded function takes 3 arguments
	bRef2.Fun3(10);					//In derived1 Fun3(10)
	bRef2.Fun3(10, 20);				//In base Fun3(10, 20)
	//bRef2.Fun3(10, 20, 30);		//Error Not In base:(90) : error C2661: 'base::Fun3' : no overloaded function takes 3 arguments
	//bRef2.Fun4(10);				//Error Not In base:(91) : error C2039: 'Fun4' : is not a member of 'base'
	//bRef2.Fun5(10);				//Error Not In base:(92) : error C2039: 'Fun5' : is not a member of 'base'
*/

	derived1 &dRef = dObj2;
	
	dRef.Fun1(10);					//In derived2 Fun1(10)
	//dRef.Fun1(10, 20);			//Error Not In Derived1:
	dRef.Fun1(10, 20, 30);			//In derived1 Fun1(10, 20, 30)
	//dRef.Fun2(10);				//Error Not In Derived1:
	dRef.Fun2(10, 20);				//In derived2 Fun2(10, 20)
	dRef.Fun2(10, 20, 30);			//In derived1 Fun2(10, 20, 30)
	dRef.Fun3(10);					//In derived1 Fun3(10)
	dRef.Fun3(10, 20);				//In derived2 Fun3(10, 20)
	//dRef.Fun3(10, 20, 30);		//Error Not In Derived1:
	dRef.Fun4(10);					//In derived1 Fun4(10)
	//dRef.Fun5(10);				//Error Not In Derived1:
	
	/*  
		ABOVE(For Whole Code) : In above code using pointer replaced with reference gives same o/p.
	*/
	return 0;
}

void base::Fun1(int iParam)
{
	std::cout <<"\nIn base Fun(10)\n";
}
void base::Fun1(int iParam1, int iParam2)
{
	std::cout <<"\nIn base Fun(10, 20)\n";
}
void base::Fun2(int iParam)
{
	std::cout << "\nIn base Fun2(10)\n";
}
void base::Fun2(int iParam1, int iParam2)
{
	std::cout << "\nIn base Fun2(10, 20)\n";
}
void base::Fun3(int iParam)
{
	std::cout << "\nIn base Fun3(10)\n";
}
void base::Fun3(int iParam1, int iParam2)
{
	std::cout << "\nIn base Fun3(10, 20)\n";
}

void derived1::Fun1(int iParam)
{
	std::cout <<"\nIn derived1 Fun1(10)\n";
}
void derived1::Fun1(int iParam1, int iParam2, int iParam3)
{
	std::cout <<"\nIn derived1 Fun1(10, 20, 30)\n";
}
void derived1::Fun2(int iParam1, int iParam2)
{
	std::cout <<"\nIn derived1 Fun2(10, 20)\n";
}
void derived1::Fun2(int iParam1, int iParam2, int iParam3)
{
	std::cout <<"\nIn derived1 Fun2(10, 20, 30)\n";
}
void derived1::Fun3(int iParam1)
{
	std::cout <<"\nIn derived1 Fun3(10)\n";
}
void derived1::Fun3(int iParam1, int iParam2)
{
	std::cout <<"\nIn derived1 Fun3(10, 20)\n";
}
void derived1::Fun4(int iParam1)
{
	std::cout <<"\nIn derived1 Fun4(10)\n";
}

void derived2::Fun1(int iParam)
{
	std::cout <<"\nIn derived2 Fun1(10)\n";
}
void derived2::Fun1(int iParam1, int iParam2)
{
	std::cout <<"\nIn derived2 Fun1(10, 20)\n";
}
void derived2::Fun2(int iParam1, int iParam2)
{
	std::cout <<"\nIn derived2 Fun2(10, 20)\n";
}
void derived2::Fun2(int iParam1, int iParam2, int iParam3)
{
	std::cout <<"\nIn derived2 Fun2(10, 20, 30)\n";
}
void derived2::Fun3(int iParam1, int iParam2)
{
	std::cout <<"\nIn derived2 Fun3(10, 20)\n";
}
void derived2::Fun5(int iParam)
{
	std::cout <<"\nIn derived2 Fun5(10)\n";
}
