#include <iostream>

class outer
{
public:
	class inner
	{
	public:
		void Fun2(void);
	}iObj2;

private:
	int ioPri;
	
protected:
	int ioPro;

public:
	int ioPub;
	
	void Fun1(void);
	
	//class inner;
	
	//friend class inner;

	
};

int main(void)
{
	outer::inner iObj1;
	
	iObj1.Fun2();
	/*  
		ABOVE: without class name also, inner class objects would be created.
	*/
	
	outer oObj1;
	
	oObj1.iObj2.Fun2();
	
	return 0;
}

void outer::Fun1(void)
{
	std::cout <<"\nIn outer Fun1()\n";
}

void outer::inner::Fun2(void)
{
	std::cout <<"\nIn inner Fun2()\n";
	
	outer oObj;
	
	oObj.ioPri = 5;
	oObj.ioPro = 10;
	oObj.ioPub = 20;
	
	std::cout <<"\nioPri = " << oObj.ioPri << std::endl;
	std::cout <<"\nioPro = " << oObj.ioPro << std::endl;
	std::cout <<"\nioPub = " << oObj.ioPub << std::endl;
	
	oObj.Fun1();
}
