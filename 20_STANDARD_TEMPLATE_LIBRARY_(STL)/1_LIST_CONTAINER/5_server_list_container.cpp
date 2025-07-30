#include "5_server_list_container.h"

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

	//pNewNode->pPrev = pDummy;
	//pNewNode->pNext = pDummy->pNext;

	/*if(pDummy == pDummy->pNext)
		pDummy->pNext = pDummy->pPrev = pNewNode;		
	else
	{
		pDummy->pNext->pPrev = pNewNode;
		pDummy->pNext = pNewNode;
	}*/
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
	
	//pNewNode->pNext = pDummy;
	//pNewNode->pPrev = pDummy->pPrev;
	pDummy->pPrev->pNext = pNewNode;
	pDummy->pPrev = pNewNode;
	/*if(pDummy == pDummy->pNext)
	{
		//pNewNode->pPrev = pDummy;
		//pDummy->pNext = pNewNode;
	}
	else
	{
		//pDummy->pPrev->pNext = pNewNode;
		//pNewNode->pPrev = pDummy->pPrev;
	}*/	
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
	
	/*if(pDummy->pPrev == pDummy->pNext)
	{
		pDummy->pNext->pPrev = pDummy->pNext->pNext = NULL;
		delete pDummy->pNext;
		pDummy->pNext = pDummy->pPrev = pDummy;
	}
	else
	{*/
		pDummy->pNext = pDummy->pNext->pNext;
		pDummy->pNext->pPrev->pNext = pDummy->pNext->pPrev->pPrev = NULL;
		delete pDummy->pNext->pPrev;
		pDummy->pNext->pPrev = pDummy;
	//}
	return iData;
}

int list::DeleteLast()
{
	int iData = 0;
	
	if(pDummy == pDummy->pNext)
		return -1;
	
	iData = pDummy->pPrev->iNo;
	
	/*if(pDummy->pPrev == pDummy->pNext)
	{
		pDummy->pNext->pPrev = pDummy->pNext->pNext = NULL;
		delete pDummy->pNext;
		pDummy->pNext = pDummy->pPrev = pDummy;
	}
	else
	{*/
		pDummy->pPrev = pDummy->pPrev->pPrev;
		pDummy->pPrev->pNext->pNext = pDummy->pPrev->pNext->pPrev = NULL;
		delete pDummy->pPrev->pNext;
		pDummy->pPrev->pNext = pDummy;
	//}
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
	
	/*if(pDummy == pDummy->pNext)
	{
		pDummy->pNext = lObj.pDummy->pNext;
		lObj.pDummy->pNext->pPrev = pDummy;
		pDummy->pPrev = lObj.pDummy->pPrev;
		lObj.pDummy->pPrev->pNext = pDummy;
	}
	else
	{*/
		pDummy->pPrev->pNext = lObj.pDummy->pNext;
		lObj.pDummy->pNext->pPrev = pDummy->pPrev;
		pDummy->pPrev = lObj.pDummy->pPrev;
		lObj.pDummy->pPrev->pNext = pDummy;
	//}
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
list::iterator::iterator(const node *pParam):pNode((node*)pParam){}

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
