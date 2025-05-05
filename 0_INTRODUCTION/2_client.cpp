#include <stdio.h>
#include "2_server.h"

int main(void)
{
	int iAns;
	struct demo dObj;
	
	dObj.Scan();
	dObj.Print();
	
	iAns = dObj.Add();
	printf("\nAddition is %d\n",iAns);	//Addition is 30
	
	return 0;
}
/*  
	ABOVE : under loss of extendibility ... server ne... swathaa.. definitions dilyaa jya mule.. client just konacha kaam
			karaychay tya object ne kaay kaam karaychay tyala call kartoy...
*/
