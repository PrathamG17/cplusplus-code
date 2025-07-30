#include "5_server_list_container_template.h"

template <typename T>
node<T>::node(T Param):pPrev(NULL), No(Param), pNext(NULL){}

template <typename T>
node<T>::~node()
{
	No = 0;
	pPrev = pNext = NULL;
}

template <typename T>
node<T> * list<T>::Initialize()
{
	node<T> *pTemp = NULL;
	pTemp = new node<T>(0);
	if(NULL == pTemp)
	{
		cout << "\n\t\tMEMORY ALLOCATION FAILED!";
		return NULL;
	}	
	pTemp->pNext = pTemp->pPrev = pTemp;
	return pTemp;
}

template <typename T>
inline void list<T>::SetIterator(const node<T> *pParam)
{
	startIter.pNode = (node<T> *)pParam;
}

template <typename T>
list<T>::list():pDummy(Initialize()), startIter(pDummy->pNext), endIter(pDummy){}

template <typename T>
list<T>::~list()
{
	if(pDummy != NULL)
	{
		delete pDummy;
		pDummy = NULL;
	}
}

template <typename T>
bool list<T>::IsEmpty()const
{
	if(pDummy == pDummy->pNext)
		return true;
	return false;
}

template <typename T>
void list<T>::InsertFirst(T Data)
{
	node<T> *pNewNode = NULL;	

	pNewNode = new node<T>(Data);
	if(NULL == pNewNode)
	{
		cout << "\n\t\tMEMORY ALLOCATION FAILED!";
		return;
	}	

	pNewNode->pPrev = pDummy;
	pNewNode->pNext = pDummy->pNext;

	if(pDummy == pDummy->pNext)
		pDummy->pNext = pDummy->pPrev = pNewNode;		
	else
	{
		pDummy->pNext->pPrev = pNewNode;
		pDummy->pNext = pNewNode;
	}
}

template <typename T>
void list<T>::InsertLast(T Data)
{
	node<T> *pNewNode = NULL;
	
	pNewNode = new node<T>(Data);
	if(NULL == pNewNode)
	{
		cout << "\n\t\tMEMORY ALLOCATION FAILED!";
		return;
	}
	
	pNewNode->pNext = pDummy;
	
	if(pDummy == pDummy->pNext)
	{
		pNewNode->pPrev = pDummy;
		pDummy->pNext = pDummy->pPrev = pNewNode;
	}
	else
	{
		pDummy->pPrev->pNext = pNewNode;
		pNewNode->pPrev = pDummy->pPrev;
		pDummy->pPrev = pNewNode;
	}	
}

template <typename T>
void list<T>::InsertAtPosition(T Data, int iPos)
{
	node<T> *pTemp = NULL;
	node<T> *pNewNode = NULL;
	int iCount = CountNodes();
	
	if(iPos <= 0 || iPos > (iCount + 1))
	{
		cout << "\n\t\tINVALID POSITION : " << iPos;
		return;
	}
	else if(1 == iPos)
		InsertFirst(Data);
	else if((iCount + 1) == iPos)
		InsertLast(Data);
	else
	{
		pNewNode = new node<T>(Data);
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

template <typename T>
T list<T>::DeleteFirst()
{
	T Data = 0;
	
	if(pDummy == pDummy->pNext)
		return -1;
	
	Data = pDummy->pNext->No;
	
	if(pDummy->pPrev == pDummy->pNext)
	{
		pDummy->pNext->pPrev = pDummy->pNext->pNext = NULL;
		delete pDummy->pNext;
		pDummy->pNext = pDummy->pPrev = pDummy;
	}
	else
	{
		pDummy->pNext = pDummy->pNext->pNext;
		pDummy->pNext->pPrev->pNext = pDummy->pNext->pPrev->pPrev = NULL;
		delete pDummy->pNext->pPrev;
		pDummy->pNext->pPrev = pDummy;
	}
	return Data;
}

template <typename T>
T list<T>::DeleteLast()
{
	T Data = 0;
	
	if(pDummy == pDummy->pNext)
		return -1;
	
	Data = pDummy->pPrev->No;
	
	if(pDummy->pPrev == pDummy->pNext)
	{
		pDummy->pNext->pPrev = pDummy->pNext->pNext = NULL;
		delete pDummy->pNext;
		pDummy->pNext = pDummy->pPrev = pDummy;
	}
	else
	{
		pDummy->pPrev = pDummy->pPrev->pPrev;
		pDummy->pPrev->pNext->pNext = pDummy->pPrev->pNext->pPrev = NULL;
		delete pDummy->pPrev->pNext;
		pDummy->pPrev->pNext = pDummy;
	}
	return Data;
}

template <typename T>
T list<T>::DeleteAtPosition(int iPos)
{
	T Data;
	node<T> *pTemp = NULL;
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
		
		Data = pTemp->No;
		pTemp->pPrev->pNext = pTemp->pNext;
		pTemp->pNext->pPrev = pTemp->pPrev;
		pTemp->pNext = pTemp->pPrev = NULL;
		delete pTemp;
		pTemp = NULL;
	}
	return Data;
}

template <typename T>
int list<T>::SearchFirstOccurence(T Key)const
{
	int iCount = 0;
	node<T> *pTemp = NULL;
	
	if(pDummy == pDummy->pNext)
		return -1;
	
	pTemp = pDummy->pNext;
	while(pTemp != pDummy)
	{
		iCount++;
		if(Key == pTemp->No)
			return iCount;
		pTemp = pTemp->pNext;		
	}
	return -1;
}

template <typename T>
int list<T>::SearchLastOccurence(T Key)const
{
	int iCount = 0;
	int iLastPos = -1;
	node<T> *pTemp = NULL;

	if(pDummy == pDummy->pNext)
		return -1;
	
	pTemp = pDummy->pNext;
	while(pTemp != pDummy)
	{
		iCount++;
		if(Key == pTemp->No)
			iLastPos = iCount;
		pTemp = pTemp->pNext;		
	}
	return iLastPos;
}

template <typename T>
int list<T>::SearchAllOccrence(T Key)const
{
	int iCount = 0;
	node<T> *pTemp = NULL;
	
	if(pDummy == pDummy->pNext)
		return -1;
	
	pTemp = pDummy->pNext;
	while(pTemp != pDummy)
	{
		if(Key == pTemp->No)
			iCount++;
		pTemp = pTemp->pNext;		
	}
	return iCount;
}

template <typename T>
int list<T>::CountNodes()const
{
	node<T> *pTemp = NULL;
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

template <typename T>
void list<T>::ConcatList(list<T> &lObj)
{
	if(lObj.pDummy == lObj.pDummy->pNext)
		return;
	
	if(pDummy == pDummy->pNext)
	{
		pDummy->pNext = lObj.pDummy->pNext;
		lObj.pDummy->pNext->pPrev = pDummy;
		pDummy->pPrev = lObj.pDummy->pPrev;
		lObj.pDummy->pPrev->pNext = pDummy;
	}
	else
	{
		pDummy->pPrev->pNext = lObj.pDummy->pNext;
		lObj.pDummy->pNext->pPrev = pDummy->pPrev;
		pDummy->pPrev = lObj.pDummy->pPrev;
		lObj.pDummy->pPrev->pNext = pDummy;
	}
	lObj.pDummy->pNext = lObj.pDummy->pPrev = lObj.pDummy;
}

template <typename T>
void list<T>::ConcatAtPosition(list<T> &lObj, int iPos)
{
	node<T> *pTemp = NULL;
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

template <typename T>
void list<T>::PhysicalReverse()
{
	node<T> *pNext = NULL;
	node<T> *pCurrent = pDummy->pNext;
	
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

template <typename T>
void list<T>::ReverseDisplay()const
{
	node<T> *pTemp = NULL;
	
	if(pDummy == pDummy->pNext)
	{
		cout << "\n\t\tLIST IS EMPTY";
		return;
	}
	
	pTemp = pDummy->pPrev;
	cout << "\n\t\tList Is : ";
	while(pTemp != pDummy)
	{
		cout << "|"<< pTemp->No << "|->";
		pTemp = pTemp->pPrev;		
	}
}

template <typename T>
void list<T>::DeleteAll()
{
	node<T> *pTemp = NULL;
	
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

template <typename T>
ostream& operator <<(ostream &cout, const list<T> &lObj)
{
	node<T> *pTemp = NULL;
	
	if(lObj.pDummy == lObj.pDummy->pNext)
	{
		cout << "\n\t\tList Is Empty";
		return cout;
	}
	
	pTemp = lObj.pDummy->pNext;
	cout << "\n\t\tList Is : ";
	while(pTemp != lObj.pDummy)
	{
		cout << "|" << pTemp->No << "|->";
		pTemp = pTemp->pNext;		
	}
	return cout;
}

template <typename T>
list<T>::iterator::iterator(const node<T> *pParam):pNode((node<T>*)pParam){}

template <typename T>
list<T>::iterator::~iterator()
{
	pNode = NULL;
}

template <typename T>
typename list<T>::iterator& list<T>::iterator::operator ++()
{
	if(NULL == pNode)
	{
		cout << "\n\t\tLIST IS EMPTY";
		return *this;
	}
	pNode = pNode->pNext;
	return *this;
}

template <typename T>
typename list<T>::iterator list<T>::iterator::operator ++(int)
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

template <typename T>
typename list<T>::iterator& list<T>::iterator::operator --()
{
	if(NULL == pNode)
	{
		cout << "\n\t\tLIST IS EMPTY";
		return *this;
	}
	pNode = pNode->pPrev;
	return *this;
}

template <typename T>
typename list<T>::iterator list<T>::iterator::operator --(int)
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

template <typename T>
bool list<T>::iterator::operator ==(const typename list<T>::iterator &itParam)const 
{
	if(NULL == pNode)
		cout << "\n\t\tLIST IS EMPTY";
	else if(NULL == itParam.pNode)
		cout << "\n\t\tNULL PARAMETER RECEIVED";
	else if(pNode == itParam.pNode)
		return true;
	
	return false;
}

template <typename T>
bool list<T>::iterator::operator !=(const typename list<T>::iterator &itParam)const 
{
	if(NULL == pNode)
		cout << "\n\t\tLIST IS EMPTY";
	else if(NULL == itParam.pNode)
		cout << "\n\t\tNULL PARAMETER RECEIVED";
	else if(pNode != itParam.pNode)
		return true;

	return false;
}

template <typename T>
bool list<T>::iterator::operator <(const typename list<T>::iterator &itParam)const 
{
	if(NULL == pNode)
		cout << "\n\t\tLIST IS EMPTY";
	else if(NULL == itParam.pNode)
		cout << "\n\t\tNULL PARAMETER RECEIVED";
	else if(pNode->No < itParam.pNode->No)
		return true;
	
	return false;
}

template <typename T>
bool list<T>::iterator::operator <=(const typename list<T>::iterator &itParam)const 
{
	if(NULL == pNode)
		cout << "\n\t\tLIST IS EMPTY";
	else if(NULL == itParam.pNode)
		cout << "\n\t\tNULL PARAMETER RECEIVED";
	else if(pNode->No <= itParam.pNode->No)
		return true;
	
	return false;
}

template <typename T>
bool list<T>::iterator::operator >(const typename list<T>::iterator &itParam)const 
{
	if(NULL == pNode)
		cout << "\n\t\tLIST IS EMPTY";
	else if(NULL == itParam.pNode)
		cout << "\n\t\tNULL PARAMETER RECEIVED";
	else if(pNode->No > itParam.pNode->No)
		return true;
	
	return false;
}

template <typename T>
bool list<T>::iterator::operator >=(const typename list<T>::iterator &itParam)const 
{
	if(NULL == pNode)
		cout << "\n\t\tLIST IS EMPTY";
	else if(NULL == itParam.pNode)
		cout << "\n\t\tNULL PARAMETER RECEIVED";
	else if(pNode->No >= itParam.pNode->No)
		return true;

	return false;
}

template <typename T>
T list<T>::iterator::operator *()const 
{
	if(NULL == pNode)
	{
		cout << "\n\t\tLIST IS EMPTY";
		return 0;
	}
	return pNode->No;
}

template <typename T>
typename list<T>::iterator& list<T>::begin()
{
	SetIterator(pDummy->pNext);
	return startIter;
}

template <typename T>
typename list<T>::iterator& list<T>::end()
{
	return endIter;
}

template class list<char>;
template class list<int>;
template class list<float>;
template class list<double>;
template ostream& operator << <char>(ostream&, const list<char>&);
template ostream& operator << <int>(ostream&, const list<int>&);
template ostream& operator << <float>(ostream&, const list<float>&);
template ostream& operator << <double>(ostream&, const list<double>&);
