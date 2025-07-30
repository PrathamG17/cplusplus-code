#include "3_server_doubly_circular_template.h"

using std::cout;

template <typename T>
node<T>::node(T Param):pPrev(NULL), No(Param), pNext(NULL){}
template <typename T>
node<T>::~node()
{
	pPrev = pNext = NULL;
}
template <typename T>
list<T>::list():pFirst(NULL), pLast(NULL){}
template <typename T>
list<T>::~list()
{
	pFirst = pLast = NULL;
}
template <typename T>
inline bool list<T>::IsEmpty()const
{
	if(NULL == pFirst)
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
template <typename T>
T list<T>::DeleteFirst()
{
	T Data;
	
	if(NULL == pFirst)
		return -1;
	
	Data = pFirst->No;
	
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
	return Data;
}
template <typename T>
T list<T>::DeleteLast()
{
	T Data;
	
	if(NULL == pFirst)
		return -1;
	
	Data = pLast->No;
	
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
		pTemp = pFirst;
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
	
	if(NULL == pFirst)
		return -1;
	
	pTemp = pFirst;
	do
	{
		iCount++;
		if(Key == pTemp->No)
			return iCount;
		pTemp = pTemp->pNext;
	}while(pTemp != pLast->pNext);
	return -1;
}
template <typename T>
int list<T>::SearchLastOccurence(T Key)const
{
	int iCount = 0;
	int iLastPos = -1;
	node<T> *pTemp = NULL;

	if(NULL == pFirst)
		return -1;
	
	pTemp = pFirst;
	do
	{
		iCount++;
		if(Key == pTemp->No)
			iLastPos = iCount;
		pTemp = pTemp->pNext;
	}while(pTemp != pLast->pNext);
	return iLastPos;
}
template <typename T>
int list<T>::SearchAllOccrence(T Key)const
{
	int iCount = 0;
	node<T> *pTemp = NULL;
	
	if(NULL == pFirst)
		return -1;
	
	pTemp = pFirst;
	do
	{
		if(Key == pTemp->No)
			iCount++;
		pTemp = pTemp->pNext;
	}while(pTemp != pLast->pNext);
	return iCount;
}
template <typename T>
int list<T>::CountNodes()const
{
	node<T> *pTemp = NULL;
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
template <typename T>
void list<T>::ConcatList(list<T> &lObj)
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
template <typename T>
void list<T>::PhysicalReverse()
{
	node<T> *pNext = NULL;
	node<T> *pCurrent = pFirst;
	
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
template <typename T>
void list<T>::ReverseDisplay()const
{
	node<T> *pTemp = NULL;
	
	if(NULL == pFirst)
	{
		cout << "\n\t\tLIST IS EMPTY";
		return;
	}
	
	pTemp = pLast;
	cout << "\n\t\tList Is : ";
	do
	{
		cout << "|"<< pTemp->No << "|->";
		pTemp = pTemp->pPrev;
	}while(pTemp != pFirst->pPrev);
}
template <typename T>
void list<T>::DeleteAll()
{
	node<T> *pTemp = NULL;
	
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
template <typename T>
ostream& operator <<(ostream &cout, const list<T> &lObj)
{
	node<T> *pTemp = NULL;
	
	if(NULL == lObj.pFirst)
	{
		cout << "\n\t\tList Is Empty";
		return cout;
	}
	
	pTemp = lObj.pFirst;
	cout << "\n\t\tList Is : ";
	do
	{
		cout << "|" << pTemp->No << "|->";
		pTemp = pTemp->pNext;
	}while(pTemp != lObj.pLast->pNext);	
	
	return cout;
}

template class list<char>;
template class list<int>;
template class list<float>;
template class list<double>;
template ostream& operator << <char>(ostream&, const list<char>&);
template ostream& operator << <int>(ostream&, const list<int>&);
template ostream& operator << <float>(ostream&, const list<float>&);
template ostream& operator << <double>(ostream&, const list<double>&);
