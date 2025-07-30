#include "6_server_list_container.h"

list::iterator list::argIter;

node::node(int iParam, node *pPtr1 = NULL, node *pPtr2 = NULL):pPrev(pPtr1), iNo(iParam), pNext(pPtr2){}

node::~node()
{
	iNo = 0;
	pPrev = pNext = NULL;
}

node * list::Initialize()
{
	node *pTemp = NULL;
	pTemp = new node(0);
	if(NULL == pTemp)
	{
		cout << "\n\t\tMEMORY ALLOCATION FAILED!";
		return NULL;
	}	
	pTemp->pNext = pTemp->pPrev = pTemp;
	return pTemp;
}

inline void list::SetIterator(const node *pParam)
{
	startIter.pNode = (node *)pParam;
}

list::list():pDummy(Initialize()), startIter(pDummy->pNext), endIter(pDummy){}

list::~list()
{
	if(pDummy != NULL)
	{
		delete pDummy;
		pDummy = NULL;
	}
}

bool list::IsEmpty()const
{
	if(pDummy == pDummy->pNext)
		return true;
	return false;
}

void list::InsertFirst(int iData)
{
	node *pNewNode = NULL;	

	pNewNode = new node(iData, pDummy, pDummy->pNext);
	if(NULL == pNewNode)
	{
		cout << "\n\t\tMEMORY ALLOCATION FAILED!";
		return;
	}	

	pDummy->pNext = pNewNode->pNext->pPrev = pNewNode;
}

void list::InsertLast(int iData)
{
	node *pNewNode = NULL;
	
	pNewNode = new node(iData, pDummy->pPrev, pDummy);
	if(NULL == pNewNode)
	{
		cout << "\n\t\tMEMORY ALLOCATION FAILED!";
		return;
	}
	
	pDummy->pPrev->pNext = pNewNode;
	pDummy->pPrev = pNewNode;
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
		pTemp = pDummy->pNext;
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
	
	if(pDummy == pDummy->pNext)
		return -1;
	
	iData = pDummy->pNext->iNo;
	
	pDummy->pNext = pDummy->pNext->pNext;
	pDummy->pNext->pPrev->pNext = pDummy->pNext->pPrev->pPrev = NULL;
	delete pDummy->pNext->pPrev;
	pDummy->pNext->pPrev = pDummy;
	
	return iData;
}

int list::DeleteLast()
{
	int iData = 0;
	
	if(pDummy == pDummy->pNext)
		return -1;
	
	iData = pDummy->pPrev->iNo;
	
	pDummy->pPrev = pDummy->pPrev->pPrev;
	pDummy->pPrev->pNext->pNext = pDummy->pPrev->pNext->pPrev = NULL;
	delete pDummy->pPrev->pNext;
	pDummy->pPrev->pNext = pDummy;

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
		pTemp = pDummy->pNext;
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
	
	if(pDummy == pDummy->pNext)
		return -1;
	
	pTemp = pDummy->pNext;
	while(pTemp != pDummy)
	{
		iCount++;
		if(iKey == pTemp->iNo)
			return iCount;
		pTemp = pTemp->pNext;		
	}
	return -1;
}

int list::SearchLastOccurence(int iKey)const
{
	int iCount = 0;
	int iLastPos = -1;
	node *pTemp = NULL;

	if(pDummy == pDummy->pNext)
		return -1;
	
	pTemp = pDummy->pNext;
	while(pTemp != pDummy)
	{
		iCount++;
		if(iKey == pTemp->iNo)
			iLastPos = iCount;
		pTemp = pTemp->pNext;		
	}
	return iLastPos;
}

int list::SearchAllOccrence(int iKey)const
{
	int iCount = 0;
	node *pTemp = NULL;
	
	if(pDummy == pDummy->pNext)
		return -1;
	
	pTemp = pDummy->pNext;
	while(pTemp != pDummy)
	{
		if(iKey == pTemp->iNo)
			iCount++;
		pTemp = pTemp->pNext;		
	}
	return iCount;
}

int list::CountNodes()const
{
	node *pTemp = NULL;
	int iCount = 0;
	
	if(pDummy == pDummy->pNext)
		return 0;
	
	pTemp = pDummy->pNext;
	while(pTemp != pDummy)
	{
		iCount++;
		pTemp = pTemp->pNext;		
	}
	return iCount;
}

void list::ConcatList(list &lObj)
{
	if(lObj.pDummy == lObj.pDummy->pNext)
		return;
	
	pDummy->pPrev->pNext = lObj.pDummy->pNext;
	lObj.pDummy->pNext->pPrev = pDummy->pPrev;
	pDummy->pPrev = lObj.pDummy->pPrev;
	lObj.pDummy->pPrev->pNext = pDummy;

	lObj.pDummy->pNext = lObj.pDummy->pPrev = lObj.pDummy;
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
	else if(lObj.pDummy == lObj.pDummy->pNext)
		return;
	else if(1 == iPos)
	{
		lObj.ConcatList(*this);
		pDummy->pNext = lObj.pDummy->pNext;
		pDummy->pPrev = lObj.pDummy->pPrev;
	}
	else if(iPos == (iCount + 1))
		ConcatList(lObj);
	else
	{
		iCount = 1;
		pTemp = pDummy->pNext;
		while(iCount < (iPos - 1))
		{
			iCount++;
			pTemp = pTemp->pNext;
		}
		
		lObj.pDummy->pNext->pPrev = pTemp;
		lObj.pDummy->pPrev->pNext = pTemp->pNext;
		pTemp->pNext->pPrev = lObj.pDummy->pPrev;
		pTemp->pNext = lObj.pDummy->pNext;
	}
	lObj.pDummy->pNext = lObj.pDummy->pPrev = lObj.pDummy;
}

void list::PhysicalReverse()
{
	node *pNext = NULL;
	node *pCurrent = pDummy->pNext;
	
	if(pDummy == pDummy->pNext)
		return;
	
	while(pCurrent != pDummy)
	{
		pNext = pCurrent->pNext;
		pCurrent->pNext = pCurrent->pPrev;
		pCurrent->pPrev = pNext;
		pCurrent = pNext;
	}
	pCurrent = pDummy->pNext;
	pDummy->pNext = pDummy->pPrev;
	pDummy->pPrev = pCurrent;
}

void list::ReverseDisplay()const
{
	node *pTemp = NULL;
	
	if(pDummy == pDummy->pNext)
	{
		cout << "\n\t\tLIST IS EMPTY";
		return;
	}
	
	pTemp = pDummy->pPrev;
	cout << "\n\t\tList Is : ";
	while(pTemp != pDummy)
	{
		cout << "|"<< pTemp->iNo << "|->";
		pTemp = pTemp->pPrev;		
	}
}

void list::DeleteAll()
{
	struct node *pTemp = NULL;
	
	if(pDummy == pDummy->pNext)
		return;
	
	while(pDummy->pNext != pDummy)
	{
		pTemp = pDummy->pNext->pNext;
		pDummy->pNext->pPrev = pDummy->pNext->pNext = NULL;
		delete pDummy->pNext;
		pDummy->pNext = pTemp;
	}
	pTemp = NULL;
}

ostream& operator <<(ostream &cout, const list &lObj)
{
	node *pTemp = NULL;
	
	if(lObj.pDummy == lObj.pDummy->pNext)
	{
		cout << "\n\t\tList Is Empty";
		return cout;
	}
	
	pTemp = lObj.pDummy->pNext;
	cout << "\n\t\tList Is : ";
	while(pTemp != lObj.pDummy)
	{
		cout << "|" << pTemp->iNo << "|->";
		pTemp = pTemp->pNext;		
	}
	return cout;
}
list::iterator::iterator():pNode(NULL){}

list::iterator::iterator(const node *pParam):pNode((node*)pParam){}

list::iterator::iterator(const list::iterator &refParam):pNode(refParam.pNode){}

list::iterator::~iterator()
{
	pNode = NULL;
}

list::iterator& list::iterator::operator ++()
{
	if(NULL == pNode)
	{
		cout << "\n\t\tLIST IS EMPTY";
		return *this;
	}
	pNode = pNode->pNext;
	return *this;
}

list::iterator list::iterator::operator ++(int)
{
	if(NULL == pNode)
	{
		cout << "\n\t\tLIST IS EMPTY";
		return *this;
	}			
	iterator itObj(pNode);
	pNode = pNode->pNext;
	return itObj;
}

list::iterator& list::iterator::operator --()
{
	if(NULL == pNode)
	{
		cout << "\n\t\tLIST IS EMPTY";
		return *this;
	}
	pNode = pNode->pPrev;
	return *this;
}

list::iterator list::iterator::operator --(int)
{
	if(NULL == pNode)
	{
		cout << "\n\t\tLIST IS EMPTY";
		return *this;
	}
	iterator itObj(pNode);
	pNode = pNode->pPrev;
	return itObj;
}

bool list::iterator::operator ==(const iterator &itParam)const 
{
	if(NULL == pNode)
		cout << "\n\t\tLIST IS EMPTY";
	else if(NULL == itParam.pNode)
		cout << "\n\t\tNULL PARAMETER RECEIVED";
	else if(pNode == itParam.pNode)
		return true;
	
	return false;
}

bool list::iterator::operator !=(const iterator &itParam)const 
{
	if(NULL == pNode)
		cout << "\n\t\tLIST IS EMPTY";
	else if(NULL == itParam.pNode)
		cout << "\n\t\tNULL PARAMETER RECEIVED";
	else if(pNode != itParam.pNode)
		return true;

	return false;
}

bool list::iterator::operator <(const iterator &itParam)const 
{
	if(NULL == pNode)
		cout << "\n\t\tLIST IS EMPTY";
	else if(NULL == itParam.pNode)
		cout << "\n\t\tNULL PARAMETER RECEIVED";
	else if(pNode->iNo < itParam.pNode->iNo)
		return true;
	
	return false;
}

bool list::iterator::operator <=(const iterator &itParam)const 
{
	if(NULL == pNode)
		cout << "\n\t\tLIST IS EMPTY";
	else if(NULL == itParam.pNode)
		cout << "\n\t\tNULL PARAMETER RECEIVED";
	else if(pNode->iNo <= itParam.pNode->iNo)
		return true;
	
	return false;
}

bool list::iterator::operator >(const iterator &itParam)const 
{
	if(NULL == pNode)
		cout << "\n\t\tLIST IS EMPTY";
	else if(NULL == itParam.pNode)
		cout << "\n\t\tNULL PARAMETER RECEIVED";
	else if(pNode->iNo > itParam.pNode->iNo)
		return true;
	
	return false;
}

bool list::iterator::operator >=(const iterator &itParam)const 
{
	if(NULL == pNode)
		cout << "\n\t\tLIST IS EMPTY";
	else if(NULL == itParam.pNode)
		cout << "\n\t\tNULL PARAMETER RECEIVED";
	else if(pNode->iNo >= itParam.pNode->iNo)
		return true;

	return false;
}

int list::iterator::operator *()const 
{
	if(NULL == pNode)
	{
		cout << "\n\t\tLIST IS EMPTY";
		return -1;
	}
	return pNode->iNo;
}

list::iterator& list::begin()
{
	SetIterator(pDummy->pNext);
	return startIter;
}

list::iterator& list::end()
{
	return endIter;
}

void list::push_back(int iData)
{
	InsertLast(iData);
}

void list::push_front(int iData)
{
	InsertFirst(iData);
}

list::iterator find(const list::iterator& itParam1, const list::iterator& itParam2, const int iKey)
{
	node *pFirst = list::GetIterator(itParam1);
	node *pLast = list::GetIterator(itParam2);

	while(pFirst != pLast)
	{
		if(iKey == pFirst->iNo)
		{
			list::iterator iter(pFirst);
			return iter;
		}
		pFirst = pFirst->pNext;
	}
	list::iterator iter;
	return iter;
}

node* list::GetIterator(const list::iterator &itParam)
{
	return itParam.pNode;
}

void list::splice(list::iterator &itParam1, list &lParam2, list::iterator &itParam3)
{
	node *pTemp1 = list::GetIterator(itParam1);
	node *pTemp2 = list::GetIterator(itParam3);
	
	if(NULL == pTemp1)
		return;
	
	if(lParam2.pDummy == lParam2.pDummy->pNext)
		return;
	
	if(pTemp2 == NULL)
	{
		lParam2.pDummy->pPrev->pNext = pTemp1->pPrev->pNext;
		pTemp1->pPrev->pNext = lParam2.pDummy->pNext;
		lParam2.pDummy->pNext->pPrev = pTemp1->pPrev;
		pTemp1->pPrev = lParam2.pDummy->pPrev;
		
		lParam2.pDummy->pNext = lParam2.pDummy->pPrev = lParam2.pDummy;		
		return;
	}
	
	pTemp2->pPrev->pNext = pTemp2->pNext;
	pTemp2->pNext->pPrev = pTemp2->pPrev;
	
	pTemp2->pPrev = pTemp1->pPrev;
	pTemp1->pPrev->pNext = pTemp2;
	
	pTemp2->pNext = pTemp1;
	pTemp1->pPrev = pTemp2;	
}

void list::sort()
{
	node *pMin = NULL;
	node *pCounter1 = NULL;
	node *pCounter2 = NULL;
	
	if(pDummy == pDummy->pNext)
	{
		cout << "\n\t\tLIST IS EMPTY!";
		return;
	}
	
	for(pCounter1 = pDummy->pNext; pCounter1 != pDummy->pPrev; pCounter1 = pCounter1->pNext)
	{
		pMin = pCounter1;
		for(pCounter2 = pCounter1->pNext; pCounter2 != pDummy; pCounter2 = pCounter2->pNext)
		{
			if(pCounter2->iNo < pMin->iNo)
				pMin = pCounter2;
		}
		
		if(pCounter1 != pMin)
		{
			pCounter1->iNo = pCounter1->iNo + pMin->iNo;
			pMin->iNo = pCounter1->iNo - pMin->iNo;
			pCounter1->iNo = pCounter1->iNo - pMin->iNo;
		}
	}
}

void list::operator =(const list &lParam1)
{
	node *pTemp1 = NULL;
	node *pTemp2 = NULL;
	node *pNewNode = NULL;
	
	if(lParam1.pDummy == lParam1.pDummy->pNext)
	{
		cout << "\n\t\tNULL LIST RECEIVED";
		return;
	}
	
	if(pDummy == pDummy->pNext)
	{
		for(pTemp1 = lParam1.pDummy->pNext; pTemp1 != lParam1.pDummy; pTemp1 = pTemp1->pNext)
		{
			pNewNode = new node(pTemp1->iNo, pDummy->pPrev, pDummy);
			if(NULL == pNewNode)
			{
				cout << "\n\t\tMEMORY ALLOCATION FAILED!";
				return;
			}
			
			pDummy->pPrev->pNext = pNewNode;
			pDummy->pPrev = pNewNode;			
		}
	}
	else
	{
		for(pTemp1 = lParam1.pDummy->pNext, pTemp2 = pDummy->pNext; 
		    (pTemp1 != lParam1.pDummy) && (pTemp2 != pDummy); 
		    pTemp1 = pTemp1->pNext, pTemp2 = pTemp2->pNext)
		{
			pTemp2->iNo = pTemp1->iNo;
		}
		
		if(pTemp1 == lParam1.pDummy)
		{
			if(pTemp2 != pDummy)
			{
				pTemp1 = pTemp2->pPrev;
				while(pTemp1->pNext != pDummy)
				{
					pTemp2 = pTemp1->pNext;
					pTemp1->pNext = pTemp2->pNext;
					pTemp2->pPrev = pTemp2->pNext = NULL;
					delete pTemp2;
				}
				pDummy->pPrev = pTemp1;
			}
		}
		else if(pTemp2 == pDummy)
		{
			if(pTemp1 != lParam1.pDummy)
			{
				while(pTemp1 != lParam1.pDummy)
				{
					pNewNode = new node(pTemp1->iNo, pDummy->pPrev, pDummy);
					if(NULL == pNewNode)
					{
						cout << "\n\t\tMEMORY ALLOCATION FAILED!";
						return;
					}
					pDummy->pPrev->pNext = pNewNode;
					pDummy->pPrev = pNewNode;
					
					pTemp1 = pTemp1->pNext;					
				}			
			}
		}
	}
}

void list::unique()
{
	node *pTemp1 = NULL;
	node *pTemp2 = NULL;
	node *pTemp3 = NULL;
	
	if(pDummy == pDummy->pNext)
	{
		cout << "\n\t\tLIST IS EMPTY";
		return;
	}
	
	for(pTemp1 = pDummy->pNext; pTemp1 != pDummy->pPrev; pTemp1 = pTemp1->pNext)
	{
		for(pTemp2 = pTemp1->pNext; pTemp2 != pDummy; pTemp2 = pTemp2->pNext)
		{
			if(pTemp1->iNo == pTemp2->iNo)
			{
				pTemp2->pPrev->pNext = pTemp2->pNext;
				pTemp2->pNext->pPrev = pTemp2->pPrev;

				pTemp3 = pTemp2;
				pTemp2 = pTemp2->pPrev;
				pTemp3->pNext = pTemp3->pPrev = NULL;
				delete pTemp3;
			}
		}
	}
}

void list::merge(list &lParam)
{
	if(lParam.pDummy == lParam.pDummy->pNext)
		return;
	
	ConcatList(lParam);
	sort();
}
