#include <stdio.h>
#include "2_server.h"

void demo::Scan()
{
	printf("Enter Two Numbers : ");
	scanf("%d%d", &iNo1, &iNo2);
}

void demo::Print()
{
	printf("iNo1 = %d iNo2 = %d", iNo1, iNo2);
}

int demo::Add()
{
	return iNo1 + iNo2;
}
