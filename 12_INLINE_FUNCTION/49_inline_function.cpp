#include <iostream>

class demo
{
public:
	void Fun1(void)
	{
		int iNo1 = 10;
	}
	
	void Fun2(void)
	{
		int iNo1 = 20;
	}
	
	void Fun3(void);
	void Fun4(void);
};

void Fun5(void);
inline void Fun6(void);

int main(void)
{
	demo dObj;
	
	dObj.Fun1();
	
	dObj.Fun2();
	
	dObj.Fun3();
	
	dObj.Fun4();
	
	Fun5();
	
	Fun6();
	
	return 0;
}

void demo::Fun3(void)
{
	int iNo1 = 30;
}
inline void demo::Fun4(void)
{
	int iNo1 = 40;
}

void Fun5(void)
{
	int iNo1 = 50;
}
inline void Fun6(void)
{
	int iNo1 = 60;
}
/*  
	ABOVE: as inline is request to compiler [compiler generated assembly code of above 'main' function]

			_main	PROC
			; File d:\prathamesh\polymorphism\49_inline_function.cpp
			; Line 24
				push	ebp
				mov	ebp, esp
				push	ecx
			; Line 27
				lea	ecx, DWORD PTR _dObj$[ebp]
	----------> call	?Fun1@demo@@QAEXXZ			; demo::Fun1
			; Line 29
				lea	ecx, DWORD PTR _dObj$[ebp]
	----------> call	?Fun2@demo@@QAEXXZ			; demo::Fun2
			; Line 31
				lea	ecx, DWORD PTR _dObj$[ebp]
	----------> call	?Fun3@demo@@QAEXXZ			; demo::Fun3
			; Line 33
				lea	ecx, DWORD PTR _dObj$[ebp]
	----------> call	?Fun4@demo@@QAEXXZ			; demo::Fun4
			; Line 35
	----------> call	?Fun5@@YAXXZ				; Fun5
			; Line 37
	----------> call	?Fun6@@YAXXZ				; Fun6
			; Line 39
				xor	eax, eax
			; Line 40
				mov	esp, ebp
				pop	ebp
				ret	0
			_main	ENDP
*/
