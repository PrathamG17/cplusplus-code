#include <stdio.h>
#include "0_server.h"

void Scan(struct demo *);
int Add(const struct demo *);
void Print(const struct demo *);

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


void Scan(struct demo *pObj)
{
	printf("\n\tEnter Two Numbers : ");
	scanf("%d%d", &pObj->iNo1, &pObj->iNo2);
}

void Print(const struct demo *pObj)
{
	printf("\n\tTwo Numbers Are : %d %d", pObj->iNo1, pObj->iNo2);
}

int Add(const struct demo *pObj)
{
	return pObj->iNo1 + pObj->iNo2;
}
