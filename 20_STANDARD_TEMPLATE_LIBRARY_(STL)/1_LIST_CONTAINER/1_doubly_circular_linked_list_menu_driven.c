#include <stdio.h>
#include <malloc.h>

struct node
{
	struct node *pPrev;
	int iNo;
	struct node *pNext;
};

void Display(struct node*, struct node*);
int CountNodes(struct node *, struct node *);
void DeleteAll(struct node**, struct node**);
int DeleteLast(struct node**, struct node**);
int DeleteFirst(struct node**, struct node**);
void ReverseDisplay(struct node*, struct node*);
void PhysicalReverse(struct node**, struct node**);
void InsertLast(struct node**, struct node**, int);
void InsertFirst(struct node**, struct node **, int);
int SearchAllOccrence(struct node*, struct node*, int);
int DeleteAtPosition(struct node**, struct node**, int);
int SearchLastOccurence(struct node*, struct node*, int);
int SearchFirstOccurence(struct node*, struct node*, int);
void InsertAtPosition(struct node**, struct node**, int, int);
void ConcatList(struct node**, struct node**, struct node**, struct node**);
void ConcatAtPosition(struct node **, struct node **, struct node **, struct node **, int);

int main(void)
{
	int iPos = 0;
	int iPos1 = 0;
	int iData = 0;
	int iChoice = 0;
	struct node *pFirst1 = NULL;
	struct node *pLast1 = NULL;
	struct node *pFirst2 = NULL;
	struct node *pLast2 = NULL;
	
	while(1)
	{
		printf("\n\n\t\t----------MENU----------");
		printf("\n\t\t1)INSERT");
		printf("\n\t\t2)DELETE");
		printf("\n\t\t3)SEARCH");
		printf("\n\t\t4)COUNT");
		printf("\n\t\t5)CONCAT");
		printf("\n\t\t6)REVERSE");
		printf("\n\t\t7)EXIT");
		printf("\n\t\t------------------------");
		printf("\n\t\tENTER YOUR CHOICE : ");
		scanf("%d", &iChoice);
		printf("\n\t\t------------------------");
		if(iChoice <= 0 || iChoice > 7)
		{
			printf("\n\t\tENTER VALID CHOICE!\n");
			Display(pFirst1, pLast1);
			continue;
		}
		else if(7 == iChoice)
		{
			if(pFirst1 != NULL)
			{
				DeleteAll(&pFirst1, &pLast1);
				pFirst1 = pLast1 = NULL;
			}
			if(pFirst2 != NULL)
			{
				DeleteAll(&pFirst2, &pLast2);
				pFirst2 = pLast2 = NULL;
			}
			break;
		}
		else if(2 == iChoice || 3 == iChoice || 6 == iChoice)
		{
			if(NULL == pFirst1)
			{
				printf("\n\t\tList Is Empty");
				continue;
			}
		}
		switch(iChoice)
		{
			case 1 :
				while(1)
				{
					printf("\n\n\t\t----------INSERT----------");
					printf("\n\t\t1)INSERT FIRST");
					printf("\n\t\t2)INSERT LAST");
					printf("\n\t\t3)INSERT AT POSITION");
					printf("\n\t\t4)BACK");
					printf("\n\t\t--------------------------");
					printf("\n\t\tENTER YOUR CHOICE : ");
					scanf("%d", &iChoice);
					printf("\n\t\t--------------------------");
					if(iChoice < 1 || iChoice > 4)
					{
							printf("\n\t\tENTER VALID CHOICE!");
							continue;
					}
					else if(4 == iChoice)
					{
						Display(pFirst1, pLast1);
						break;
					}
					else if(3 == iChoice)
					{
						printf("\n\t\tENTER POSITION : ");
						scanf("%d", &iPos);
						iData = CountNodes(pFirst1, pLast1);
						if(iPos <= 0 || iPos > (iData + 1))
						{
							printf("\n\t\tINAVLID POSITION : %d\n", iPos);
							Display(pFirst1, pLast1);
							continue;
						}
					}
					printf("\n\t\tENTER DATA : ");
					scanf("%d", &iData);
					switch(iChoice)
					{
						case 1 :
							InsertFirst(&pFirst1, &pLast1, iData);
							break;
						case 2 :
							InsertLast(&pFirst1, &pLast1, iData);
							break;
						case 3 :
							InsertAtPosition(&pFirst1, &pLast1, iData, iPos);
							break;
					}
					Display(pFirst1, pLast1);
				}
				break;
			case 2 :
				while(1)
				{
					printf("\n\n\t\t----------DELETE----------");
					printf("\n\t\t1)DELETE FIRST");
					printf("\n\t\t2)DELETE LAST");
					printf("\n\t\t3)DELETE AT POSITION");
					printf("\n\t\t4)BACK");
					printf("\n\t\t--------------------------");
					printf("\n\t\tENTER YOUR CHOICE : ");
					scanf("%d", &iChoice);
					printf("\n\t\t--------------------------");
					if(iChoice < 1 || iChoice > 4)
					{
							printf("\n\t\tENTER VALID CHOICE!\n");
							Display(pFirst1, pLast1);
							continue;
					}
					else if(4 == iChoice)
					{
						Display(pFirst1, pLast1);
						break;
					}
					else if(3 == iChoice)
					{
						printf("\n\t\tENTER POSITION : ");
						scanf("%d", &iPos);
						iData = CountNodes(pFirst1, pLast1);
						if(iPos <= 0 || iPos > iData)
						{
							printf("\n\t\tINAVLID POSITION : %d\n", iPos);
							Display(pFirst1, pLast1);
							continue;
						}
					}
					switch(iChoice)
					{
						case 1 :
							iData = DeleteFirst(&pFirst1, &pLast1);
							break;
						case 2 :
							iData = DeleteLast(&pFirst1, &pLast1);
							break;
						case 3 :
							iData = DeleteAtPosition(&pFirst1, &pLast1, iPos);
							break;
					}
					if(iData != -1)
					{
						printf("\n\t\tDeleted Data is : %d\n", iData);
						Display(pFirst1, pLast1);
						if(NULL == pFirst1)
							break;
					}
					else
						printf("\n\t\tList Is Empty");
				}
				break;
			case 3 :
				while(1)
				{
					printf("\n\n\t\t----------SEARCH----------");
					printf("\n\t\t1)SEARCH FIRST");
					printf("\n\t\t2)SEARCH LAST");
					printf("\n\t\t3)SEARCH ALL OCURRENCE");
					printf("\n\t\t4)BACK");
					printf("\n\t\t--------------------------");
					printf("\n\t\tENTER YOUR CHOICE : ");
					scanf("%d", &iChoice);
					printf("\n\t\t--------------------------");
					if(iChoice < 1 || iChoice > 4)
					{
							printf("\n\t\tENTER VALID CHOICE!\n");
							Display(pFirst1, pLast1);
							continue;
					}
					else if(4 == iChoice)
					{
						Display(pFirst1, pLast1);
						break;
					}
					printf("\n\t\tENTER DATA TO BE SEARCH : ");
					scanf("%d", &iData);
					switch(iChoice)
					{
						case 1 :
							iPos = SearchFirstOccurence(pFirst1, pLast1, iData);
							if(iPos != -1)
								printf("\n\t\tData %d Found First At Node %d\n", iData, iPos);
							else
								printf("\n\t\tData Not Found\n");
							break;
						case 2 :
							iPos = SearchLastOccurence(pFirst1, pLast1, iData);
							if(iPos != -1)
								printf("\n\t\tData %d Found Last At Node %d\n", iData, iPos);
							else
								printf("\n\t\tData Not Found\n");
							break;
						case 3 :
							iPos = SearchAllOccrence(pFirst1, pLast1, iData);
							if(iPos != -1)
								printf("\n\t\tData %d Found %d Times\n", iData, iPos);
							else
								printf("\n\t\tList Is Empty\n");
							break;
					}
					Display(pFirst1, pLast1);
				}
				break;
			case 4 :
				iData = CountNodes(pFirst1, pLast1);
				printf("\n\t\tTotal Nodes : %d\n", iData);
				Display(pFirst1, pLast1);
				break;
			case 5 :
				while(1)
				{
					printf("\n\n\t\t----------CONCAT----------");
					printf("\n\t\t1)CONCAT LIST");
					printf("\n\t\t2)CONCAT AT POSITION");
					printf("\n\t\t3)BACK");
					printf("\n\t\t--------------------------");
					printf("\n\t\tENTER YOUR CHOICE : ");
					scanf("%d", &iChoice);
					printf("\n\t\t--------------------------");
					if(iChoice < 1 || iChoice > 3)
					{
							printf("\n\t\tENTER VALID CHOICE!\n");
							Display(pFirst1, pLast1);
							continue;
					}
					else if(3 == iChoice)
					{
						Display(pFirst1, pLast1);
						break;
					}
					else if(2 == iChoice)
					{
						printf("\n\t\tENTER POSITION : ");
						scanf("%d", &iPos);
						iData = CountNodes(pFirst1, pLast1);
						if(iPos <= 0 || iPos > (iData + 1))
						{
							printf("\n\t\tINAVLID POSITION : %d\n", iPos);
							Display(pFirst1, pLast1);
							continue;
						}
					}
					switch(iChoice)
					{
						case 1 :
							while(1)
							{
								printf("\n\n\t\t----------INSERT----------");
								printf("\n\t\t1)INSERT FIRST");
								printf("\n\t\t2)INSERT LAST");
								printf("\n\t\t3)INSERT AT POSITION");
								printf("\n\t\t4)BACK");
								printf("\n\t\t--------------------------");
								printf("\n\t\tENTER YOUR CHOICE : ");
								scanf("%d", &iChoice);
								printf("\n\t\t--------------------------");
								if(iChoice < 1 || iChoice > 4)
								{
										printf("\n\t\tENTER VALID CHOICE!\n");
										printf("\n\t\tFIRST LIST =>\n");
										Display(pFirst1, pLast1);
										printf("\n\n\t\tSECOND LIST =>\n");
										Display(pFirst2, pLast2);
										continue;
								}
								else if(4 == iChoice)
								{
									ConcatList(&pFirst1, &pLast1, &pFirst2, &pLast2);
									break;
								}
								else if(3 == iChoice)
								{
									printf("\n\t\tENTER POSITION : ");
									scanf("%d", &iPos);
									iData = CountNodes(pFirst2, pLast2);
									if(iPos <= 0 || iPos > (iData + 1))
									{
										printf("\n\t\tINAVLID POSITION : %d", iPos);
										printf("\n\t\tFIRST LIST =>\n");
										Display(pFirst1, pLast1);
										printf("\n\n\t\tSECOND LIST =>\n");
										Display(pFirst2, pLast2);
										continue;
									}
								}
								printf("\n\t\tENTER DATA : ");
								scanf("%d", &iData);
								switch(iChoice)
								{
									case 1 :
										InsertFirst(&pFirst2, &pLast2, iData);
										break;
									case 2 :
										InsertLast(&pFirst2, &pLast2, iData);
										break;
									case 3 :
										InsertAtPosition(&pFirst2, &pLast2, iData, iPos);
										break;
								}
								printf("\n\t\tFIRST LIST =>\n");
								Display(pFirst1, pLast1);
								printf("\n\n\t\tSECOND LIST =>\n");
								Display(pFirst2, pLast2);
							}
							break;
						case 2 :
							while(1)
							{
								printf("\n\n\t\t----------INSERT----------");
								printf("\n\t\t1)INSERT FIRST");
								printf("\n\t\t2)INSERT LAST");
								printf("\n\t\t3)INSERT AT POSITION");
								printf("\n\t\t4)BACK");
								printf("\n\t\t--------------------------");
								printf("\n\t\tENTER YOUR CHOICE : ");
								scanf("%d", &iChoice);
								printf("\n\t\t--------------------------");
								if(iChoice < 1 || iChoice > 4)
								{
										printf("\n\t\tENTER VALID CHOICE!");
										printf("\n\t\tFIRST LIST =>\n");
										Display(pFirst1, pLast1);
										printf("\n\n\t\tSECOND LIST =>\n");
										Display(pFirst2, pLast2);
										continue;
								}
								else if(4 == iChoice)
								{
									ConcatAtPosition(&pFirst1, &pLast1, &pFirst2, &pLast2, iPos);
									break;
								}
								else if(3 == iChoice)
								{
									printf("\n\t\tENTER POSITION : ");
									scanf("%d", &iPos1);
									iData = CountNodes(pFirst2, pLast2);
									if(iPos1 <= 0 || iPos1 > (iData + 1))
									{
										printf("\n\t\tINAVLID POSITION : %d", iPos1);
										printf("\n\t\tFIRST LIST =>\n");
										Display(pFirst1, pLast1);
										printf("\n\n\t\tSECOND LIST =>\n");
										Display(pFirst2, pLast2);
										continue;
									}
								}
								printf("\n\t\tENTER DATA : ");
								scanf("%d", &iData);
								switch(iChoice)
								{
									case 1 :
										InsertFirst(&pFirst2, &pLast2, iData);
										break;
									case 2 :
										InsertLast(&pFirst2, &pLast2, iData);
										break;
									case 3 :
										InsertAtPosition(&pFirst2, &pLast2, iData, iPos1);
										break;
								}
								printf("\n\t\tFIRST LIST =>\n");
								Display(pFirst1, pLast1);
								printf("\n\n\t\tSECOND LIST =>\n");
								Display(pFirst2, pLast2);
							}
							break;
					}
					Display(pFirst1, pLast1);
				}				
				break;
			case 6 :
				while(1)
				{
					printf("\n\n\t\t----------REVERSE----------");
					printf("\n\t\t1)PHYSICAL REVERSE");
					printf("\n\t\t2)REVERSE DISPLAY");
					printf("\n\t\t3)BACK");
					printf("\n\t\t---------------------------");
					printf("\n\t\tENTER YOUR CHOICE : ");
					scanf("%d", &iChoice);
					printf("\n\t\t---------------------------");
					if(iChoice < 1 || iChoice > 3)
					{
							printf("\n\t\tENTER VALID CHOICE!\n");
							Display(pFirst1, pLast1);
							continue;
					}
					else if(3 == iChoice)
					{
						Display(pFirst1, pLast1);
						break;
					}
					switch(iChoice)
					{
						case 1 :
							printf("\n\t\tORIGINAL LIST =>\n");
							Display(pFirst1, pLast1);
							PhysicalReverse(&pFirst1, &pLast1);
							printf("\n\n\t\tPHYSICALLY REVERSE LIST =>\n");
							Display(pFirst1, pLast1);
							break;
						case 2 :
							ReverseDisplay(pFirst1, pLast1);
							break;
					}
				}
		}
	}
	return 0;
}
void InsertFirst(struct node **ppHead, struct node **ppTail, int iData)
{
	struct node *pNewNode = NULL;	

	pNewNode = (struct node*)malloc(sizeof(struct node));
	if(NULL == pNewNode)
	{
		printf("\n\t\tMEMORY ALLOCATION FAILED!");
		return;
	}	

	pNewNode->iNo = iData;
	if(NULL == *ppHead)
		*ppHead = *ppTail = pNewNode;		
	else
	{
		pNewNode->pNext = *ppHead;
		(*ppHead)->pPrev = pNewNode;
		*ppHead = pNewNode;
	}	

	(*ppHead)->pPrev = *ppTail;
	(*ppTail)->pNext = *ppHead;
}
void InsertLast(struct node **ppHead, struct node **ppTail, int iData)
{
	struct node *pNewNode = NULL;
	
	pNewNode = (struct node*)malloc(sizeof(struct node));
	if(NULL == pNewNode)
	{
		printf("\n\t\tMEMORY ALLOCATION FAILED!");
		return;
	}
	
	pNewNode->iNo = iData;
	if(NULL == *ppHead)
		*ppHead = *ppTail = pNewNode;
	else
	{
		(*ppTail)->pNext = pNewNode;
		pNewNode->pPrev = *ppTail;
		*ppTail = pNewNode;
	}	
	(*ppHead)->pPrev = *ppTail;
	(*ppTail)->pNext = *ppHead;
}
void InsertAtPosition(struct node **ppHead, struct node **ppTail, int iData, int iPos)
{
	struct node *pTemp = NULL;
	struct node *pNewNode = NULL;
	int iCount = CountNodes(*ppHead, *ppTail);
	
	if(iPos <= 0 || iPos > (iCount + 1))
	{
		printf("\n\t\tINVALID POSITION : %d", iPos);
		return;
	}
	else if(1 == iPos)
		InsertFirst(ppHead, ppTail, iData);
	else if((iCount + 1) == iPos)
		InsertLast(ppHead, ppTail, iData);
	else
	{
		pNewNode = (struct node*)malloc(sizeof(struct node));
		if(NULL == pNewNode)
		{
			printf("\n\t\tMEMORY ALLOCATION FAILED!");
			return;
		}
		
		pNewNode->iNo = iData;	
		iCount = 1;
		pTemp = *ppHead;
		while(iCount < (iPos - 1))
		{
			iCount++;
			pTemp = pTemp->pNext;
		}
		pNewNode->pNext = pTemp->pNext;
		pTemp->pNext->pPrev = pNewNode;
		pNewNode->pPrev = pTemp;
		pTemp->pNext = pNewNode;
	}
}
int DeleteFirst(struct node **ppHead, struct node **ppTail)
{
	int iData = 0;
	
	if(NULL == *ppHead)
		return -1;
	
	iData = (*ppHead)->iNo;
	
	if(*ppHead == *ppTail)
	{
		(*ppHead)->pPrev = (*ppTail)->pNext = NULL;
		free(*ppHead);
		*ppHead = *ppTail = NULL;
	}
	else
	{
		*ppHead = (*ppHead)->pNext;
		(*ppHead)->pPrev->pNext = (*ppHead)->pPrev->pPrev = NULL;
		free((*ppHead)->pPrev);
		(*ppTail)->pNext = *ppHead;
		(*ppHead)->pPrev = *ppTail;
	}
	return iData;
}
int DeleteLast(struct node **ppHead, struct node **ppTail)
{
	int iData = 0;
	
	if(NULL == *ppHead)
		return -1;
	
	iData = (*ppTail)->iNo;
	
	if(*ppHead == *ppTail)
	{
		(*ppHead)->pPrev = (*ppHead)->pNext = NULL;
		free(*ppHead);
		*ppHead = *ppTail = NULL;
	}
	else
	{
		*ppTail = (*ppTail)->pPrev;
		(*ppTail)->pNext->pPrev = (*ppTail)->pNext->pPrev = NULL;
		free((*ppTail)->pNext);
		(*ppTail)->pNext = *ppHead;
		(*ppHead)->pPrev = *ppTail;
	}
	return iData;
}
int DeleteAtPosition(struct node **ppHead, struct node **ppTail, int iPos)
{
	struct node *pTemp = NULL;
	int iCount = CountNodes(*ppHead, *ppTail);
	
	if(iPos <= 0 || iPos > iCount)
	{
		printf("\n\t\tINVALID POSITION : %d", iPos);
		return -1;
	}
	else if(1 == iPos)
		return DeleteFirst(ppHead, ppTail);
	else if(iCount == iPos)
		return DeleteLast(ppHead, ppTail);
	else
	{
		iCount = 1;
		pTemp = *ppHead;
		while(iCount < iPos)
		{
			iCount++;
			pTemp = pTemp->pNext;
		}
		
		iCount = pTemp->iNo;
		pTemp->pPrev->pNext = pTemp->pNext;
		pTemp->pNext->pPrev = pTemp->pPrev;
		pTemp->pNext = pTemp->pPrev = NULL;
		free(pTemp);
		pTemp = NULL;
	}
	return iCount;
}
void DeleteAll(struct node **ppHead, struct node **ppTail)
{
	struct node *pTemp = NULL;
	
	if(NULL == *ppHead)
		return;

	(*ppTail)->pNext = NULL;
	
	while(*ppHead != NULL)
	{
		pTemp = (*ppHead)->pNext;
		(*ppHead)->pPrev = (*ppHead)->pNext = NULL;
		free(*ppHead);
		*ppHead = pTemp;
	}
	*ppTail = NULL;
}
void Display(struct node *pHead, struct node *pTail)
{
	if(NULL == pHead)
	{
		printf("\n\t\tList Is Empty");
		return;
	}
	
	printf("\n\t\tList Is : ");
	do
	{
		printf("|%d|->", pHead->iNo);
		pHead = pHead->pNext;
	}while(pHead != pTail->pNext);
}
int CountNodes(struct node *pHead, struct node *pTail)
{
	int iCount = 0;
	
	if(NULL == pHead)
		return 0;
	
	do
	{
		iCount++;
		pHead = pHead->pNext;
	}while(pHead != pTail->pNext);
	return iCount;
}
int SearchFirstOccurence(struct node *pHead, struct node *pTail, int iKey)
{
	int iCount = 0;
	
	if(NULL == pHead)
		return -1;
	
	do
	{
		iCount++;
		if(iKey == pHead->iNo)
			return iCount;
		pHead = pHead->pNext;
	}while(pHead != pTail->pNext);
	return -1;
}
int SearchLastOccurence(struct node *pHead, struct node *pTail, int iKey)
{
	int iCount = 0;
	int iLastPos = -1;
	
	if(NULL == pHead)
		return -1;
	
	do
	{
		iCount++;
		if(iKey == pHead->iNo)
			iLastPos = iCount;
		pHead = pHead->pNext;
	}while(pHead != pTail->pNext);
	return iLastPos;
}
int SearchAllOccrence(struct node *pHead, struct node *pTail, int iKey)
{
	int iCount = 0;
	
	if(NULL == pHead)
		return -1;
	
	do
	{
		if(iKey == pHead->iNo)
			iCount++;
		pHead = pHead->pNext;
	}while(pHead != pTail->pNext);
	return iCount;
}
void ConcatList(struct node **ppHead1, struct node **ppTail1, struct node **ppHead2, struct node **ppTail2)
{
	if(NULL == *ppHead2)
		return;
	
	if(NULL == *ppHead1)
	{
		*ppHead1 = *ppHead2;
		*ppTail1 = *ppTail2;
	}
	else
	{
		(*ppTail1)->pNext = *ppHead2;
		(*ppHead2)->pPrev = *ppTail1;
		(*ppHead1)->pPrev = *ppTail2;
		(*ppTail2)->pNext = *ppHead1;
		*ppTail1 = *ppTail2;
	}
	*ppHead2 = *ppTail2 = NULL;
}
void ConcatAtPosition(struct node **ppHead1, struct node **ppTail1, struct node **ppHead2, struct node **ppTail2, int iPos)
{
	struct node *pTemp = NULL;
	int iCount = CountNodes(*ppHead1, *ppTail1);
	
	if(iPos <= 0 || iPos > (iCount + 1))
	{
		printf("\n\t\tINVALID POSITION : %d", iPos);
		return;
	}
	else if(NULL == *ppHead2)
		return;
	else if(1 == iPos)
	{
		ConcatList(ppHead2, ppTail2, ppHead1, ppTail1);
		*ppHead1 = *ppHead2;
		*ppTail1 = *ppTail2;
	}
	else if(iPos == (iCount + 1))
		ConcatList(ppHead1, ppTail1, ppHead2, ppTail2);
	else
	{
		iCount = 1;
		pTemp = *ppHead1;
		while(iCount < (iPos - 1))
		{
			iCount++;
			pTemp = pTemp->pNext;
		}
		
		(*ppHead2)->pPrev = pTemp;
		(*ppTail2)->pNext = pTemp->pNext;
		pTemp->pNext->pPrev = *ppTail2;
		pTemp->pNext = *ppHead2;
	}
	*ppHead2 = *ppTail2 = NULL;
}
void PhysicalReverse(struct node **ppHead, struct node **ppTail)
{
	struct node *pNext = NULL;
	struct node *pCurrent = *ppHead;
	
	if(NULL == *ppHead)
		return;
	
	do
	{
		pNext = pCurrent->pNext;
		pCurrent->pNext = pCurrent->pPrev;
		pCurrent->pPrev = pNext;
		pCurrent = pNext;
	}while(pCurrent != *ppHead);
	*ppHead = pCurrent->pNext;
	*ppTail = pCurrent;
}
void ReverseDisplay(struct node *pHead, struct node *pTail)
{
	if(NULL == pHead)
	{
		printf("\n\t\tLIST IS EMPTY");
		return;
	}
	
	printf("\n\t\tList Is : ");
	do
	{
		printf("|%d|->", pTail->iNo);
		pTail = pTail->pPrev;
	}while(pTail != pHead->pPrev);
}
