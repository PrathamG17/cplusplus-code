#include "2_server_doubly_circular_list.h"

using std::cout;

node::node(int iParam):pPrev(NULL), iNo(iParam), pNext(NULL){}
node::~node()
{
	iNo = 0;
	pPrev = pNext = NULL;
}
list::list():pFirst(NULL), pLast(NULL){}
list::~list()
{
	pFirst = pLast = NULL;
}
bool list::IsEmpty()const
{
	if(NULL == pFirst)
		return true;
	return false;
}
void list::InsertFirst(int iData)
{
	node *pNewNode = NULL;	

	pNewNode = new node(iData);
	if(NULL == pNewNode)
	{
		cout << "\n\t\tMEMORY ALLOCATION FAILED!";
		return;
	}	

	if(NULL == pFirst)
		pFirst = pLast = pNewNode;		
	else
	{
		pNewNode->pNext = pFirst;
		pFirst->pPrev = pNewNode;
		pFirst = pNewNode;
	}	

	pFirst->pPrev = pLast;
	pLast->pNext = pFirst;
}
void list::InsertLast(int iData)
{
	node *pNewNode = NULL;
	
	pNewNode = new node(iData);
	if(NULL == pNewNode)
	{
		cout << "\n\t\tMEMORY ALLOCATION FAILED!";
		return;
	}
	
	if(NULL == pFirst)
		pFirst = pLast = pNewNode;
	else
	{
		pLast->pNext = pNewNode;
		pNewNode->pPrev = pLast;
		pLast = pNewNode;
	}	
	pFirst->pPrev = pLast;
	pLast->pNext = pFirst;
}
void list::InsertAtPosition(int iData, int iPos)
{
	node *pTemp = NULL;
	node *pNewNode = NULL;
	int iCount = CountNodes();
	
	if(iPos <= 0 || iPos > (iCount + 1))
	{
		cout << "\n\t\tINVALID POSITION : " << iPos;
		return;
	}
	else if(1 == iPos)
		InsertFirst(iData);
	else if((iCount + 1) == iPos)
		InsertLast(iData);
	else
	{
		pNewNode = new node(iData);
		if(NULL == pNewNode)
		{
			cout << "\n\t\tMEMORY ALLOCATION FAILED!";
			return;
		}
		
		iCount = 1;
		pTemp = pFirst;
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
int list::DeleteFirst()
{
	int iData = 0;
	
	if(NULL == pFirst)
		return -1;
	
	iData = pFirst->iNo;
	
	if(pFirst == pLast)
	{
		pFirst->pPrev = pLast->pNext = NULL;
		delete pFirst;
		pFirst = pLast = NULL;
	}
	else
	{
		pFirst = pFirst->pNext;
		pFirst->pPrev->pNext = pFirst->pPrev->pPrev = NULL;
		delete pFirst->pPrev;
		pLast->pNext = pFirst;
		pFirst->pPrev = pLast;
	}
	return iData;
}
int list::DeleteLast()
{
	int iData = 0;
	
	if(NULL == pFirst)
		return -1;
	
	iData = pLast->iNo;
	
	if(pFirst == pLast)
	{
		pFirst->pPrev = pFirst->pNext = NULL;
		delete pFirst;
		pFirst = pLast = NULL;
	}
	else
	{
		pLast = pLast->pPrev;
		pLast->pNext->pPrev = pLast->pNext->pPrev = NULL;
		delete pLast->pNext;
		pLast->pNext = pFirst;
		pFirst->pPrev = pLast;
	}
	return iData;
}
int list::DeleteAtPosition(int iPos)
{
	node *pTemp = NULL;
	int iCount = CountNodes();
	
	if(iPos <= 0 || iPos > iCount)
	{
		cout << "\n\t\tINVALID POSITION : " << iPos;
		return -1;
	}
	else if(1 == iPos)
		return DeleteFirst();
	else if(iCount == iPos)
		return DeleteLast();
	else
	{
		iCount = 1;
		pTemp = pFirst;
		while(iCount < iPos)
		{
			iCount++;
			pTemp = pTemp->pNext;
		}
		
		iCount = pTemp->iNo;
		pTemp->pPrev->pNext = pTemp->pNext;
		pTemp->pNext->pPrev = pTemp->pPrev;
		pTemp->pNext = pTemp->pPrev = NULL;
		delete pTemp;
		pTemp = NULL;
	}
	return iCount;
}
int list::SearchFirstOccurence(int iKey)const
{
	int iCount = 0;
	node *pTemp = NULL;
	
	if(NULL == pFirst)
		return -1;
	
	pTemp = pFirst;
	do
	{
		iCount++;
		if(iKey == pTemp->iNo)
			return iCount;
		pTemp = pTemp->pNext;
	}while(pTemp != pLast->pNext);
	return -1;
}
int list::SearchLastOccurence(int iKey)const
{
	int iCount = 0;
	int iLastPos = -1;
	node *pTemp = NULL;

	if(NULL == pFirst)
		return -1;
	
	pTemp = pFirst;
	do
	{
		iCount++;
		if(iKey == pTemp->iNo)
			iLastPos = iCount;
		pTemp = pTemp->pNext;
	}while(pTemp != pLast->pNext);
	return iLastPos;
}
int list::SearchAllOccrence(int iKey)const
{
	int iCount = 0;
	node *pTemp = NULL;
	
	if(NULL == pFirst)
		return -1;
	
	pTemp = pFirst;
	do
	{
		if(iKey == pTemp->iNo)
			iCount++;
		pTemp = pTemp->pNext;
	}while(pTemp != pLast->pNext);
	return iCount;
}
int list::CountNodes()const
{
	node *pTemp = NULL;
	int iCount = 0;
	
	if(NULL == pFirst)
		return 0;
	
	pTemp = pFirst;
	do
	{
		iCount++;
		pTemp = pTemp->pNext;
	}while(pTemp != pLast->pNext);
	return iCount;
}
void list::ConcatList(list &lObj)
{
	if(NULL == lObj.pFirst)
		return;
	
	if(NULL == pFirst)
	{
		pFirst = lObj.pFirst;
		pLast = lObj.pLast;
	}
	else
	{
		pLast->pNext = lObj.pFirst;
		lObj.pFirst->pPrev = pLast;
		pFirst->pPrev = lObj.pLast;
		lObj.pLast->pNext = pFirst;
		pLast = lObj.pLast;
	}
	lObj.pFirst = lObj.pLast = NULL;
}
void list::ConcatAtPosition(list &lObj, int iPos)
{
	node *pTemp = NULL;
	int iCount = CountNodes();
	
	if(iPos <= 0 || iPos > (iCount + 1))
	{
		cout << "\n\t\tINVALID POSITION : " << iPos;
		return;
	}
	else if(NULL == lObj.pFirst)
		return;
	else if(1 == iPos)
	{
		lObj.ConcatList(*this);
		pFirst = lObj.pFirst;
		pLast = lObj.pLast;
	}
	else if(iPos == (iCount + 1))
		ConcatList(lObj);
	else
	{
		iCount = 1;
		pTemp = pFirst;
		while(iCount < (iPos - 1))
		{
			iCount++;
			pTemp = pTemp->pNext;
		}
		
		lObj.pFirst->pPrev = pTemp;
		lObj.pLast->pNext = pTemp->pNext;
		pTemp->pNext->pPrev = lObj.pLast;
		pTemp->pNext = lObj.pFirst;
	}
	lObj.pFirst = lObj.pLast = NULL;
}
void list::PhysicalReverse()
{
	node *pNext = NULL;
	node *pCurrent = pFirst;
	
	if(NULL == pFirst)
		return;
	
	do
	{
		pNext = pCurrent->pNext;
		pCurrent->pNext = pCurrent->pPrev;
		pCurrent->pPrev = pNext;
		pCurrent = pNext;
	}while(pCurrent != pFirst);
	pFirst = pCurrent->pNext;
	pLast = pCurrent;
}
void list::ReverseDisplay()const
{
	node *pTemp = NULL;
	
	if(NULL == pFirst)
	{
		cout << "\n\t\tLIST IS EMPTY";
		return;
	}
	
	pTemp = pLast;
	cout << "\n\t\tList Is : ";
	do
	{
		cout << "|"<< pTemp->iNo << "|->";
		pTemp = pTemp->pPrev;
	}while(pTemp != pFirst->pPrev);
}
void list::DeleteAll()
{
	struct node *pTemp = NULL;
	
	if(NULL == pFirst)
		return;
	
	pLast->pNext = NULL;
	
	while(pFirst != NULL)
	{
		pTemp = pFirst->pNext;
		pFirst->pPrev = pFirst->pNext = NULL;
		delete pFirst;
		pFirst = pTemp;
	}
	pLast = NULL;
}
ostream& operator <<(ostream &cout, const list &lObj)
{
	node *pTemp = NULL;
	
	if(NULL == lObj.pFirst)
	{
		cout << "\n\t\tList Is Empty";
		return cout;
	}
	
	pTemp = lObj.pFirst;
	cout << "\n\t\tList Is : ";
	do
	{
		cout << "|" << pTemp->iNo << "|->";
		pTemp = pTemp->pNext;
	}while(pTemp != lObj.pLast->pNext);	
	
	return cout;
}
