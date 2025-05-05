#include <iostream>

class demo
{
  int iNo;

public :
   //case 1 : no. of parameters must be different.       
   void Fun(void)
   {
        std::cout <<"In Fun 0\n";
   }
   void Fun(int iParam)
   {
        std::cout <<"In Fun 1\n";
   }
   void Fun(int iParam1, int iParam2)
   {
        std::cout <<"In Fun 2\n";
   }
   //case 2: type of parameters must be different.
   void Fun(int iParam1, float fParam2)
   {
        std::cout <<"In Fun 2 type change\n";
   }
   void Fun(float fParam1, int iParam2)
   {
        std::cout <<"In Fun 2 sequence change\n";
   }
};

int main(void)
{
    demo dObj;
    
    //case 1:
    dObj.Fun();
    dObj.Fun(10);
    dObj.Fun(10,20);

    //case 2:
    dObj.Fun(10, 11.11f);
    
    //case 3:
    dObj.Fun(11.11f, 10);

    return 0;    
}
