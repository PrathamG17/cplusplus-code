#include <stdio.h>
#include "1_server.h"

int main(void)
{
	struct demo dObj;
	int iAns;
	
	Scan(&dObj);
	
	Print(&dObj);
	
	iAns = Add(&dObj);
	
	printf("\n\tAddition : %d", iAns);
	
	return 0;
}
