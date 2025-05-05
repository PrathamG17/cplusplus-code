#include <iostream>

struct node
{
	int iNo;
	node *pNext;
	
public:
	node():iNo(0),pNext(NULL) {}
	friend class list;
};

class list
{
	node *pFirst;
	
public:
	list():pFirst(NULL) {}
	void InsertFirst(int);
	void InsertLast(int);
	int DeleteFirst(void);
	int DeleteLast(void);
	void Display(void);
	int CountNodes(void);
	int SearchFirstOccurence(int);
	int SearchLastOccurence(int);
	int SearchAllOccurence(int);
	void InsertAtPosition(int, int);
	int DeleteAtPosition(int);
};

int main(void)
{
	list lObj;
	
	lObj.InsertFirst(10);
	lObj.InsertFirst(5);
	lObj.InsertLast(15);
	lObj.InsertLast(20);
	lObj.InsertAtPosition(12, 3);
	
	lObj.Display();
	
	std::cout <<"\nTotal Nodes : " << lObj.CountNodes() << std::endl;
	std::cout <<"\n10 found first in node " << lObj.SearchFirstOccurence(10) << std::endl;
	std::cout <<"\n20 found last in node " << lObj.SearchLastOccurence(20) << std::endl;
	std::cout <<"\n15 found " << lObj.SearchAllOccurence(15) <<" times" << std::endl;

	
	std::cout <<"\nDeleted Node : " << lObj.DeleteAtPosition(3) << std::endl;
	std::cout <<"\nDeleted Node : " << lObj.DeleteFirst() << std::endl;
	std::cout <<"\nDeleted Node : " << lObj.DeleteLast() << std::endl;
	std::cout <<"\nDeleted Node : " << lObj.DeleteLast() << std::endl;
	std::cout <<"\nDeleted Node : " << lObj.DeleteFirst() << std::endl;
	
	return 0;
}
void list::InsertFirst(int iData)
{
	node *pNewNode = NULL;
	
	pNewNode = new node;
	if(NULL == pNewNode)
	{
		std::cout <<"\nMemory Allocation Failed\n";
		return;
	}
	
	pNewNode->iNo = iData;
	pNewNode->pNext = pFirst;
	pFirst = pNewNode;
}

void list::InsertLast(int iData)
{
	node *pTemp = NULL;
	node *pNewNode = NULL;
	
	pNewNode = new node;
	if(NULL == pNewNode)
	{
		std::cout <<"\nMemory Allocation Failed\n";
		return;
	}
	
	pNewNode->iNo = iData;
	pNewNode->pNext = NULL;
	
	if(NULL == pFirst)
		pFirst = pNewNode;
	else
	{
		pTemp = pFirst;
		while(pTemp->pNext != NULL)
			pTemp = pTemp->pNext;
		
		pTemp->pNext = pNewNode;
	}
}

int list::DeleteFirst(void)
{
	int iDelData;
	node *pTemp = NULL;
	
	if(NULL == pFirst)
	{
		std::cout <<"\nList is empty\n";
		return -1;
	}
	
	pTemp = pFirst;
	pFirst = pTemp->pNext;
	
	pTemp->pNext = NULL;
	
	iDelData = pTemp->iNo;
	
	delete pTemp;
	
	pTemp = NULL;
	
	return iDelData;
}

int list::DeleteLast(void)
{
	int iDelData;
	node *pTemp = NULL;
	
	if(NULL == pFirst)
	{
		std::cout <<"\nList is empty\n";
		return -1;
	}
	
	pTemp = pFirst;
	
	if(NULL == pTemp->pNext)
	{
		iDelData = pTemp->iNo;
		delete pTemp;
	}
	else
	{
		while(pTemp->pNext->pNext != NULL)
			pTemp = pTemp->pNext;
		
		iDelData = pTemp->pNext->iNo;
		
		delete pTemp->pNext;
		
		pTemp->pNext = NULL;
	}
	return iDelData;
}

void list::Display(void)
{
	node *pTemp = NULL;
	
	if(NULL == pFirst)
	{
		std::cout <<"\nList is empty.\n";
		return;
	}
	
	std::cout <<"\nList is : ";
	pTemp = pFirst;
	while(pTemp != NULL)
	{
		std::cout <<"|" << pTemp->iNo <<"|-->";
		pTemp = pTemp->pNext;
	}
	
	std::cout << std::endl;
}

int list::CountNodes(void)
{
	int iCount = 0;
	node *pTemp = NULL;
	
	if(NULL == pFirst)
		return 0;
	
	pTemp = pFirst;
	while(pTemp != NULL)
	{
		++iCount;
		pTemp = pTemp->pNext;
	}
	
	return iCount;
}

int list::SearchFirstOccurence(int iKey)
{
	int iPos = 0;
	node *pTemp = NULL;
	
	if(NULL == pFirst)
		return 0;
	
	pTemp = pFirst;
	while(pTemp != NULL)
	{
		++iPos;
		if(iKey == pTemp->iNo)
			return iPos;
		
		pTemp = pTemp->pNext;
	}
	
	return 0;
}

int list::SearchLastOccurence(int iKey)
{
	int iPos = 0;
	int iLastPos = 0;
	node *pTemp = NULL;
	
	if(NULL == pFirst)
		return 0;
	
	pTemp = pFirst;
	while(pTemp != NULL)
	{
		++iPos;
		if(iKey == pTemp->iNo)
			iLastPos = iPos;
		
		pTemp = pTemp->pNext;
	}
	
	return iLastPos;
}

int list::SearchAllOccurence(int iKey)
{
	int iCount = 0;
	node *pTemp = NULL;
	
	if(NULL == pFirst)
		return 0;
	
	pTemp = pFirst;
	while(pTemp != NULL)
	{
		if(iKey == pTemp->iNo)
			++iCount;
		
		pTemp = pTemp->pNext;
	}
	
	return iCount;
}

void list::InsertAtPosition(int iData, int iPos)
{
	node *pTemp = NULL;
	node *pNewNode = NULL;
	int iCount = CountNodes();
	
	//invalid position 
	if(iPos <= 0 || iPos > iCount + 1)
	{
		std::cout <<"\nInvalid Position\n";
		return;
	}
	
	//valid position..
	if(1 == iPos)					//first
	{
		InsertFirst(iData);
		return;
	}
	else if(iPos == iCount + 1)		//Last
	{
		InsertLast(iData);
		return;
	}
	
	//node is in between
	pNewNode = new node;
	if(NULL == pNewNode)
	{
		std::cout <<"\nMemory Allocation Failed.\n";
		return;
	}
	
	pNewNode->iNo = iData;
	
	pTemp = pFirst;
	iCount = 1;
	while(iCount < iPos - 1)	//ek position mage thaambna requirement hoti...
	{
		++iCount;
		pTemp = pTemp->pNext;
	}
	
	pNewNode->pNext = pTemp->pNext;	//pahila me pudhe point kela...
	pTemp->pNext = pNewNode;		//mag tyala mala point karayla..sangitala...
}

int list::DeleteAtPosition(int iPos)
{
	int iDelData;
	node *pTemp1 = NULL;
	node *pTemp2 = NULL;
	int iCount = CountNodes();
	
	if(NULL == pFirst)
		return -1;
	
	//invalid position
	if(iPos <= 0 || iPos > iCount)
	{
		std::cout <<"\nPosition Invalid\n";
		return -1;
	}
	
	//valid position
	if(1 == iPos)
	{
		iDelData = DeleteFirst();		
		return iDelData;
	}
	else if(iPos == iCount)
	{
		iDelData = DeleteLast();
		return iDelData;
	}
	
	//between node
	pTemp1 = pFirst;
	iCount = 1;
	while(iCount < iPos - 1)
	{
		++iCount;
		pTemp1 = pTemp1->pNext;
	}
	
	iDelData = pTemp1->pNext->iNo;
	pTemp2 = pTemp1->pNext;

	pTemp1->pNext = pTemp2->pNext;
	pTemp2->pNext = NULL;

	delete pTemp2;
	
	return iDelData;
}
