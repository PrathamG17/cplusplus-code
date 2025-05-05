#include <iostream>

template <typename T>
class demo
{
	T Data1;
	
public:
	demo(void);
	void SetValue(T);
	void Display(void);
};

int main(void)
{
	demo <int>dObj1;			//In default constructor
	
	dObj1.Display();			//Data1 = 7134747
	dObj1.SetValue(10);
	dObj1.Display();			//Data1 = 10
	
	demo <char>dObj2;			//In default constructor

	dObj2.Display();			//Data1 =
	dObj2.SetValue(65);
	dObj2.Display();			//Data1 = A
	
	return 0;
}

template <typename T>
demo<T>::demo(void)
{
	std::cout <<"\nIn default constructor\n";
}

template <typename T>
void demo<T>::SetValue(T Param)
{
	Data1 = Param;
}

template <typename T>
void demo<T>::Display(void)
{
	std::cout <<"\nData1 = " << Data1 << std::endl;
}
