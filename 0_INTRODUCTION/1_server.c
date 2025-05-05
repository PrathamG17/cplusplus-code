#include <stdio.h>
#include "1_server.h"

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
