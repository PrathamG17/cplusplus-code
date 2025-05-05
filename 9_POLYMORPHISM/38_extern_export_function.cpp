#include <iostream>

class demo
{
      int iNo;
      
public :
       
       extern "C" void Fun(void)
       {
              std::cout <<"In Fun \n";
       }      
       void Fun1(int)
       {
              std::cout <<"In Fun     10  \n";
       }    
};

int main(void)
{
    demo dObj;
    
    dObj.Fun();
    
    dObj.Fun1(10);
    
    return 0;    
}
