#include <iostream>

using std::endl;
using std::cout;
using std::cin;
using std::ostream;

template <typename T>
class list;
template <typename T>
class node;
template <typename T>
void PrintList(list<T>&, list<T>&);
template <typename T>
ostream& operator << (ostream&, const list<T>&);
template <typename T>
void MyMain(void);

template <typename T>
class list
{
private :
	node<T> *pDummy;

public :
	list();
	~list();
	bool IsEmpty()const;
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPosition(T, int);
	T DeleteFirst();
	T DeleteLast();
	T DeleteAtPosition(int);
	int SearchFirstOccurence(T)const;
	int SearchLastOccurence(T)const;
	int SearchAllOccrence(T)const;
	int CountNodes()const;
	void ConcatList(list<T>&);
	void ConcatAtPosition(list<T>&, int);
	void PhysicalReverse();
	void ReverseDisplay()const;
	void DeleteAll();
	
	class iterator;	
	
	void sort();
	void unique();
	iterator& begin();
	iterator& end();
	void merge(list &);
	void push_back(T Data);
	void push_front(T Data);
	void operator =(const list&);
	void splice(typename list<T>::iterator &itParam1, list<T> &lParam2, typename list<T>::iterator &itParam3 = argIter);

private :
	node<T>* Initialize();
	void SetIterator(const node<T> *);
	static node<T>* GetIterator(const typename list<T>::iterator &);

public :	
	class iterator
	{
	private:
		node<T> *pNode;
		
	public :
		iterator();
		iterator(const node<T> *);
		iterator(const typename list<T>::iterator &);
		~iterator();
		iterator& operator ++();
		iterator operator ++(int);
		iterator& operator --();
		iterator operator --(int);
		bool operator ==(const iterator &)const;
		bool operator !=(const iterator &)const;
		bool operator <(const iterator &)const;
		bool operator <=(const iterator &)const; 
		bool operator >(const iterator &)const;
		bool operator >=(const iterator &)const; 
		T operator *()const;
		
		friend 	void list<T>::SetIterator(const node<T> *);
		friend node<T>* list<T>::GetIterator(const typename list<T>::iterator&);
	};

private :
	iterator startIter;
	iterator endIter;
	static iterator argIter;
	
	template <typename T>
	friend ostream& operator << (ostream&, const list<T>&);
	template <typename T>
	friend typename list<T>::iterator find(const typename list<T>::iterator&, const typename list<T>::iterator&, const T);
};

template <typename T>
class node
{
private :
	node *pPrev;
	T No;
	node *pNext;
	
	node();
	node(T, node*, node*);
	~node();
	
	template <typename T>
	friend class list;
	template <typename T>
	friend ostream& operator << (ostream&, const list<T>&);
	template <typename T>
	friend typename list<T>::iterator find(const typename list<T>::iterator&, const typename list<T>::iterator&, const T);
};

template <typename T>
node<T>::node():pPrev(NULL), No(0), pNext(NULL){}

template <typename T>
node<T>::node(T Param, node<T> *pPtr1 = NULL, node<T> *pPtr2 = NULL):pPrev(pPtr1), No(Param), pNext(pPtr2){}

template <typename T>
node<T>::~node()
{
	No = 0;
	pPrev = pNext = NULL;
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

	pNewNode = new node<T>(Data, pDummy, pDummy->pNext);
	if(NULL == pNewNode)
	{
		cout << "\n\t\tMEMORY ALLOCATION FAILED!";
		return;
	}	

	pDummy->pNext = pNewNode->pNext->pPrev = pNewNode;
}

template <typename T>
void list<T>::InsertLast(T Data)
{
	node<T> *pNewNode = NULL;
	
	pNewNode = new node<T>(Data, pDummy->pPrev, pDummy);
	if(NULL == pNewNode)
	{
		cout << "\n\t\tMEMORY ALLOCATION FAILED!";
		return;
	}
	
	pDummy->pPrev->pNext = pNewNode;
	pDummy->pPrev = pNewNode;
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
		pNewNode = new node(Data);
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
	
	pDummy->pNext = pDummy->pNext->pNext;
	pDummy->pNext->pPrev->pNext = pDummy->pNext->pPrev->pPrev = NULL;
	delete pDummy->pNext->pPrev;
	pDummy->pNext->pPrev = pDummy;
	
	return Data;
}

template <typename T>
T list<T>::DeleteLast()
{
	T Data = 0;
	
	if(pDummy == pDummy->pNext)
		return -1;
	
	Data = pDummy->pPrev->No;
	
	pDummy->pPrev = pDummy->pPrev->pPrev;
	pDummy->pPrev->pNext->pNext = pDummy->pPrev->pNext->pPrev = NULL;
	delete pDummy->pPrev->pNext;
	pDummy->pPrev->pNext = pDummy;

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
	
	pDummy->pPrev->pNext = lObj.pDummy->pNext;
	lObj.pDummy->pNext->pPrev = pDummy->pPrev;
	pDummy->pPrev = lObj.pDummy->pPrev;
	lObj.pDummy->pPrev->pNext = pDummy;

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
node<T> * list<T>::Initialize()
{
	node<T> *pTemp = NULL;
	pTemp = new node<T>();
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
node<T>* list<T>::GetIterator(const typename list<T>::iterator &itParam)
{
	return itParam.pNode;
}

template <typename T>
void list<T>::sort()
{
	node<T> *pMin = NULL;
	node<T> *pCounter1 = NULL;
	node<T> *pCounter2 = NULL;
	
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
			if(pCounter2->No < pMin->No)
				pMin = pCounter2;
		}
		
		if(pCounter1 != pMin)
		{
			pCounter1->No = pCounter1->No + pMin->No;
			pMin->No = pCounter1->No - pMin->No;
			pCounter1->No = pCounter1->No - pMin->No;
		}
	}
}

template <typename T>
void list<T>::unique()
{
	node<T> *pTemp1 = NULL;
	node<T> *pTemp2 = NULL;
	node<T> *pTemp3 = NULL;
	
	if(pDummy == pDummy->pNext)
	{
		cout << "\n\t\tLIST IS EMPTY";
		return;
	}
	
	for(pTemp1 = pDummy->pNext; pTemp1 != pDummy->pPrev; pTemp1 = pTemp1->pNext)
	{
		for(pTemp2 = pTemp1->pNext; pTemp2 != pDummy; pTemp2 = pTemp2->pNext)
		{
			if(pTemp1->No == pTemp2->No)
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

template <typename T>
void list<T>::merge(list<T> &lParam)
{
	if(lParam.pDummy == lParam.pDummy->pNext)
		return;
	
	ConcatList(lParam);
	sort();
}


template <typename T>
void list<T>::push_back(T Data)
{
	InsertLast(Data);
}

template <typename T>
void list<T>::push_front(T Data)
{
	InsertFirst(Data);
}

template <typename T>
void list<T>::operator =(const list<T> &lParam1)
{
	node<T> *pTemp1 = NULL;
	node<T> *pTemp2 = NULL;
	node<T> *pNewNode = NULL;
	
	if(lParam1.pDummy == lParam1.pDummy->pNext)
	{
		cout << "\n\t\tNULL LIST RECEIVED";
		return;
	}
	
	if(pDummy == pDummy->pNext)
	{
		for(pTemp1 = lParam1.pDummy->pNext; pTemp1 != lParam1.pDummy; pTemp1 = pTemp1->pNext)
		{
			pNewNode = new node<T>(pTemp1->No, pDummy->pPrev, pDummy);
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
			pTemp2->No = pTemp1->No;
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
					pNewNode = new node<T>(pTemp1->No, pDummy->pPrev, pDummy);
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

template <typename T>
void list<T>::splice(typename list<T>::iterator &itParam1, list<T> &lParam2, typename list<T>::iterator &itParam3)
{
	node<T> *pTemp1 = list<T>::GetIterator(itParam1);
	node<T> *pTemp2 = list<T>::GetIterator(itParam3);
	
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

template <typename T>
list<T>::iterator::iterator():pNode(NULL){}

template <typename T>
list<T>::iterator::iterator(const node<T> *pParam):pNode((node<T>*)pParam){}

template <typename T>
list<T>::iterator::iterator(const typename list<T>::iterator &refParam):pNode(refParam.pNode){}

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
bool list<T>::iterator::operator ==(const iterator &itParam)const 
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
bool list<T>::iterator::operator !=(const iterator &itParam)const 
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
bool list<T>::iterator::operator <(const iterator &itParam)const 
{
	if(NULL == pNode)
		cout << "\n\t\tLIST IS EMPTY";
	else if(NULL == itParam.pNode)
		cout << "\n\t\tNULL PARAMETER RECEIVED";
	else if(pNode->iNo < itParam.pNode->iNo)
		return true;
	
	return false;
}

template <typename T>
bool list<T>::iterator::operator <=(const iterator &itParam)const 
{
	if(NULL == pNode)
		cout << "\n\t\tLIST IS EMPTY";
	else if(NULL == itParam.pNode)
		cout << "\n\t\tNULL PARAMETER RECEIVED";
	else if(pNode->iNo <= itParam.pNode->iNo)
		return true;
	
	return false;
}

template <typename T>
bool list<T>::iterator::operator >(const iterator &itParam)const 
{
	if(NULL == pNode)
		cout << "\n\t\tLIST IS EMPTY";
	else if(NULL == itParam.pNode)
		cout << "\n\t\tNULL PARAMETER RECEIVED";
	else if(pNode->iNo > itParam.pNode->iNo)
		return true;
	
	return false;
}

template <typename T>
bool list<T>::iterator::operator >=(const iterator &itParam)const 
{
	if(NULL == pNode)
		cout << "\n\t\tLIST IS EMPTY";
	else if(NULL == itParam.pNode)
		cout << "\n\t\tNULL PARAMETER RECEIVED";
	else if(pNode->iNo >= itParam.pNode->iNo)
		return true;

	return false;
}

template <typename T>
T list<T>::iterator::operator *()const 
{
	if(NULL == pNode)
	{
		cout << "\n\t\tLIST IS EMPTY";
		return -1;
	}
	return pNode->No;
}

template <typename T>
typename list<T>::iterator typename list<T>::argIter;

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
typename list<T>::iterator find(const typename list<T>::iterator& itParam1, const typename list<T>::iterator& itParam2, const T Key)
{
	node<T> *pFirst = list<T>::GetIterator(itParam1);
	node<T> *pLast = list<T>::GetIterator(itParam2);

	while(pFirst != pLast)
	{
		if(Key == pFirst->No)
		{
			list<T>::iterator iter(pFirst);
			return iter;
		}
		pFirst = pFirst->pNext;
	}
	list<T>::iterator iter;
	return iter;
}

int main(void)
{
	int iChoice = 0;
	
	while(1)
	{
		cout << "\n\t\t----------LIST TYPES----------";
		cout << "\n\t\t1)CHARACTER";
		cout << "\n\t\t2)INTEGER";
		cout << "\n\t\t3)FLOAT";
		cout << "\n\t\t4)DOUBLE";
		cout << "\n\t\t5)EXIT";
		cout << "\n\t\t------------------------------";
		cout << "\n\t\tWHICH LIST YOU WANT TO USE? : ";
		cin >> iChoice;
		cout << "\n\t\t------------------------------";
		if(iChoice <= 0 || iChoice > 5)
		{
			cout << "\n\t\tENTER VALID CHOICE!\n";
			continue;
		}
		else if(5 == iChoice)
			break;
		switch(iChoice)
		{
			case 1 :
				MyMain<char>();		
				break;
			case 2 :
				MyMain<int>();
				break;
			case 3 :
				MyMain<float>();
				break;
			case 4 :
				MyMain<double>();
		}
	}

	return 0;
}

template <typename T>
void MyMain(void)
{
	list<T> lObj1;
	list<T> lObj2;
	
	for(int i = 0; i < 6; i++)
	{
		lObj1.push_back(i + 65);
		lObj2.push_front(i + 65);
	}
	
	PrintList(lObj1, lObj2);
	
	lObj2.splice(find(lObj2.begin(), lObj2.end(), (T)'E'), lObj1);
	
	PrintList(lObj1, lObj2);
	
	lObj2.splice(lObj2.end(), lObj2, lObj2.begin());
	
	PrintList(lObj1, lObj2);
	
	lObj2.sort();
	
	lObj1 = lObj2;
	
	lObj2.unique();
	
	PrintList(lObj1, lObj2);
	
	lObj1.merge(lObj2);
	
	PrintList(lObj1, lObj2);
}

template <typename T>
void PrintList(list<T> &lParam1, list<T> &lParam2)
{
	cout << "\n\t\tList 1 is : ";
	for(list<T>::iterator iter = lParam1.begin(); iter != lParam1.end(); ++iter)
		cout << *iter << " ";
	
	cout << endl << "\n\t\tList 2 is : ";
	for(list<T>::iterator iter = lParam2.begin(); iter != lParam2.end(); ++iter)
		cout << *iter << " ";

	cout << endl << endl;
}
