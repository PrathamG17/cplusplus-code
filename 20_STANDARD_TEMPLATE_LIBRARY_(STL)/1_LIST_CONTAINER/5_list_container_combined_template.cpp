#include <iostream>

using std::cin;
using std::cout;
using std::ostream;

template <typename T>
class list;
template <typename T>
ostream& operator << (ostream&, const list<T>&);
template <typename T>
void DisplayIterator(list<T>&);
template <typename T>
void MyMain(void);

template <typename T>
class node
{
private :
	node *pPrev;
	T No;
	node *pNext;
	
	node(T);
	~node();
	
	template <typename T>
	friend class list;
	template <typename T>
	friend ostream& operator << (ostream&, const list<T>&);
};

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
	void ConcatList(list&);
	void ConcatAtPosition(list&, int);
	void PhysicalReverse();
	void ReverseDisplay()const;
	void DeleteAll();

private :
	node<T> *Initialize();
	void SetIterator(const node<T> *);

public :
	class iterator
	{
	private:
		node<T> *pNode;
		
	public :
		iterator(const node<T>*);
		~iterator();
		iterator& operator ++();
		iterator operator ++(int);
		iterator& operator --();
		iterator operator --(int);	
		bool operator ==(const iterator&)const;
		bool operator !=(const iterator&)const;
		bool operator <(const iterator&)const;
		bool operator <=(const iterator&)const;
		bool operator >(const iterator&)const;
		bool operator >=(const iterator&)const;
		T operator *()const;
		
		friend 	void list<T>::SetIterator(const node<T> *);
	};

private :
	iterator startIter;
	iterator endIter;

public :
	iterator& begin();
	iterator& end();

	template <typename T>
	friend ostream& operator << (ostream&, const list<T>&);
};

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
	T Data;
	int iPos = 0;
	int iPos1 = 0;
	int iCount = 0;
	int iChoice = 0;

	while(1)
	{
		cout << "\n\n\t\t----------MENU----------";
		cout << "\n\t\t1)INSERT";
		cout << "\n\t\t2)DELETE";
		cout << "\n\t\t3)SEARCH";
		cout << "\n\t\t4)COUNT";
		cout << "\n\t\t5)CONCAT";
		cout << "\n\t\t6)REVERSE";
		cout << "\n\t\t7)EXIT";
		cout << "\n\t\t------------------------";
		cout << "\n\t\tENTER YOUR CHOICE : ";
		cin >> iChoice;
		cout << "\n\t\t------------------------";
		if(iChoice <= 0 || iChoice > 7)
		{
			cout << "\n\t\tENTER VALID CHOICE!\n";
			DisplayIterator(lObj1);
			continue;
		}
		else if(7 == iChoice)
		{
			lObj1.DeleteAll();
			lObj2.DeleteAll();
			break;
		}
		else if(2 == iChoice || 3 == iChoice || 6 == iChoice)
		{
			if(lObj1.IsEmpty())
			{
				cout << "\n\t\tList Is Empty";
				continue;
			}
		}
		switch(iChoice)
		{
			case 1 :
				while(1)
				{
					cout << "\n\n\t\t----------INSERT----------";
					cout << "\n\t\t1)INSERT FIRST";
					cout << "\n\t\t2)INSERT LAST";
					cout << "\n\t\t3)INSERT AT POSITION";
					cout << "\n\t\t4)BACK";
					cout << "\n\t\t--------------------------";
					cout << "\n\t\tENTER YOUR CHOICE : ";
					cin >> iChoice;
					cout << "\n\t\t--------------------------";
					if(iChoice < 1 || iChoice > 4)
					{
							cout << "\n\t\tENTER VALID CHOICE!";
							continue;
					}
					else if(4 == iChoice)
					{
						DisplayIterator(lObj1);
						break;
					}
					else if(3 == iChoice)
					{
						cout << "\n\t\tENTER POSITION : ";
						cin >> iPos;
						Data = lObj1.CountNodes();
						if(iPos <= 0 || iPos > (Data + 1))
						{
							cout << "\n\t\tINAVLID POSITION : " << iPos << "\n";
							DisplayIterator(lObj1);
							continue;
						}
					}
					cout << "\n\t\tENTER DATA : ";
					cin >> Data;
					switch(iChoice)
					{
						case 1 :
							lObj1.InsertFirst(Data);
							break;
						case 2 :
							lObj1.InsertLast(Data);
							break;
						case 3 :
							lObj1.InsertAtPosition(Data, iPos);
							break;
					}
					DisplayIterator(lObj1);
				}
				break;
			case 2 :
				while(1)
				{
					cout << "\n\n\t\t----------DELETE----------";
					cout << "\n\t\t1)DELETE FIRST";
					cout << "\n\t\t2)DELETE LAST";
					cout << "\n\t\t3)DELETE AT POSITION";
					cout << "\n\t\t4)BACK";
					cout << "\n\t\t--------------------------";
					cout << "\n\t\tENTER YOUR CHOICE : ";
					cin >> iChoice;
					cout << "\n\t\t--------------------------";
					if(iChoice < 1 || iChoice > 4)
					{
							cout << "\n\t\tENTER VALID CHOICE!\n";
							DisplayIterator(lObj1);
							continue;
					}
					else if(4 == iChoice)
					{
						DisplayIterator(lObj1);
						break;
					}
					else if(3 == iChoice)
					{
						cout << "\n\t\tENTER POSITION : ";
						cin >> iPos;
						Data = lObj1.CountNodes();
						if(iPos <= 0 || iPos > Data)
						{
							cout << "\n\t\tINAVLID POSITION : " << iPos << "\n";
							DisplayIterator(lObj1);
							continue;
						}
					}
					switch(iChoice)
					{
						case 1 :
							Data = lObj1.DeleteFirst();
							break;
						case 2 :
							Data = lObj1.DeleteLast();
							break;
						case 3 :
							Data = lObj1.DeleteAtPosition(iPos);
							break;
					}
					if(Data != -1)
					{
						cout << "\n\t\tDeleted Data is : " << Data << "\n";
						DisplayIterator(lObj1);
						if(lObj1.IsEmpty()) 
							break;
					}
					else
						cout << "\n\t\tList Is Empty";
				}
				break;
			case 3 :
				while(1)
				{
					cout << "\n\n\t\t----------SEARCH----------";
					cout << "\n\t\t1)SEARCH FIRST";
					cout << "\n\t\t2)SEARCH LAST";
					cout << "\n\t\t3)SEARCH ALL OCURRENCE";
					cout << "\n\t\t4)BACK";
					cout << "\n\t\t--------------------------";
					cout << "\n\t\tENTER YOUR CHOICE : ";
					cin >> iChoice;
					cout << "\n\t\t--------------------------";
					if(iChoice < 1 || iChoice > 4)
					{
							cout << "\n\t\tENTER VALID CHOICE!\n";
							DisplayIterator(lObj1);
							continue;
					}
					else if(4 == iChoice)
					{
						DisplayIterator(lObj1);
						break;
					}
					cout << "\n\t\tENTER DATA TO BE SEARCH : ";
					cin >> Data;
					switch(iChoice)
					{
						case 1 :
							iPos = lObj1.SearchFirstOccurence(Data);
							if(iPos != -1)
								cout << "\n\t\tData " << Data << " Found First At Node " << iPos << "\n";
							else
								cout << "\n\t\tData Not Found\n";
							break;
						case 2 :
							iPos = lObj1.SearchLastOccurence(Data);
							if(iPos != -1)
								cout << "\n\t\tData " << Data << " Found Last At Node " << iPos << "\n";
							else
								cout << "\n\t\tData Not Found\n";
							break;
						case 3 :
							iPos = lObj1.SearchAllOccrence(Data);
							if(iPos != -1)
								cout << "\n\t\tData " << Data << " Found " << iPos << " Times\n";
							else
								cout << "\n\t\tList Is Empty\n";
							break;
					}
					DisplayIterator(lObj1);
				}
				break;
			case 4 :
				iCount = lObj1.CountNodes();
				cout << "\n\t\tTotal Nodes : " << iCount << "\n";
				DisplayIterator(lObj1);
				break;
			case 5 :
				while(1)
				{
					cout << "\n\n\t\t----------CONCAT----------";
					cout << "\n\t\t1)CONCAT LIST";
					cout << "\n\t\t2)CONCAT AT POSITION";
					cout << "\n\t\t3)BACK";
					cout << "\n\t\t--------------------------";
					cout << "\n\t\tENTER YOUR CHOICE : ";
					cin >> iChoice;
					cout << "\n\t\t--------------------------";
					if(iChoice < 1 || iChoice > 3)
					{
							cout << "\n\t\tENTER VALID CHOICE!\n";
							DisplayIterator(lObj1);
							continue;
					}
					else if(3 == iChoice)
					{
						DisplayIterator(lObj1);
						break;
					}
					else if(2 == iChoice)
					{
						cout << "\n\t\tENTER POSITION : ";
						cin >> iPos;
						Data = lObj1.CountNodes();
						if(iPos <= 0 || iPos > (Data + 1))
						{
							cout << "\n\t\tINAVLID POSITION : " << iPos << "\n";
							DisplayIterator(lObj1);
							continue;
						}
					}
					switch(iChoice)
					{
						case 1 :
							while(1)
							{
								cout << "\n\n\t\t----------INSERT----------";
								cout << "\n\t\t1)INSERT FIRST";
								cout << "\n\t\t2)INSERT LAST";
								cout << "\n\t\t3)INSERT AT POSITION";
								cout << "\n\t\t4)BACK";
								cout << "\n\t\t--------------------------";
								cout << "\n\t\tENTER YOUR CHOICE : ";
								cin >> iChoice;
								cout << "\n\t\t--------------------------";
								if(iChoice < 1 || iChoice > 4)
								{
										cout << "\n\t\tENTER VALID CHOICE!\n";
										cout << "\n\t\tFIRST LIST =>\n";
										DisplayIterator(lObj1);
										cout << "\n\n\t\tSECOND LIST =>\n";
										DisplayIterator(lObj2);
										continue;
								}
								else if(4 == iChoice)
								{
									lObj1.ConcatList(lObj2);
									break;
								}
								else if(3 == iChoice)
								{
									cout << "\n\t\tENTER POSITION : ";
									cin >> iPos;
									Data = lObj2.CountNodes();
									if(iPos <= 0 || iPos > (Data + 1))
									{
										cout << "\n\t\tINAVLID POSITION : " << iPos;
										cout << "\n\t\tFIRST LIST =>\n";
										DisplayIterator(lObj1);
										cout << "\n\n\t\tSECOND LIST =>\n";
										DisplayIterator(lObj2);
										continue;
									}
								}
								cout << "\n\t\tENTER DATA : ";
								cin >> Data;
								switch(iChoice)
								{
									case 1 :
										lObj2.InsertFirst(Data);
										break;
									case 2 :
										lObj2.InsertLast(Data);
										break;
									case 3 :
										lObj2.InsertAtPosition(Data, iPos);
										break;
								}
								cout << "\n\t\tFIRST LIST =>\n";
								DisplayIterator(lObj1);
								cout << "\n\n\t\tSECOND LIST =>\n";
								DisplayIterator(lObj2);
							}
							break;
						case 2 :
							while(1)
							{
								cout << "\n\n\t\t----------INSERT----------";
								cout << "\n\t\t1)INSERT FIRST";
								cout << "\n\t\t2)INSERT LAST";
								cout << "\n\t\t3)INSERT AT POSITION";
								cout << "\n\t\t4)BACK";
								cout << "\n\t\t--------------------------";
								cout << "\n\t\tENTER YOUR CHOICE : ";
								cin >> iChoice;
								cout << "\n\t\t--------------------------";
								if(iChoice < 1 || iChoice > 4)
								{
										cout << "\n\t\tENTER VALID CHOICE!";
										cout << "\n\t\tFIRST LIST =>\n";
										DisplayIterator(lObj1);
										cout << "\n\n\t\tSECOND LIST =>\n";
										DisplayIterator(lObj2);
										continue;
								}
								else if(4 == iChoice)
								{
									lObj1.ConcatAtPosition(lObj2, iPos);
									break;
								}
								else if(3 == iChoice)
								{
									cout << "\n\t\tENTER POSITION : ";
									cin >> iPos1;
									Data = lObj2.CountNodes();
									if(iPos1 <= 0 || iPos1 > (Data + 1))
									{
										cout << "\n\t\tINAVLID POSITION : " << iPos1;
										cout << "\n\t\tFIRST LIST =>\n";
										DisplayIterator(lObj1);
										cout << "\n\n\t\tSECOND LIST =>\n";
										DisplayIterator(lObj2);
										continue;
									}
								}
								cout << "\n\t\tENTER DATA : ";
								cin >> Data;
								switch(iChoice)
								{
									case 1 :
										lObj2.InsertFirst(Data);
										break;
									case 2 :
										lObj2.InsertLast(Data);
										break;
									case 3 :
										lObj2.InsertAtPosition(Data, iPos1);
										break;
								}
								cout << "\n\t\tFIRST LIST =>\n";
								DisplayIterator(lObj1);
								cout << "\n\n\t\tSECOND LIST =>\n";
								DisplayIterator(lObj2);
							}
							break;
					}
					DisplayIterator(lObj1);
				}				
				break;
			case 6 :
				while(1)
				{
					cout << "\n\n\t\t----------REVERSE----------";
					cout << "\n\t\t1)PHYSICAL REVERSE";
					cout << "\n\t\t2)REVERSE DISPLAY";
					cout << "\n\t\t3)BACK";
					cout << "\n\t\t---------------------------";
					cout << "\n\t\tENTER YOUR CHOICE : ";
					cin >> iChoice;
					cout << "\n\t\t---------------------------";
					if(iChoice < 1 || iChoice > 3)
					{
							cout << "\n\t\tENTER VALID CHOICE!\n";
							DisplayIterator(lObj1);
							continue;
					}
					else if(3 == iChoice)
					{
						DisplayIterator(lObj1);
						break;
					}
					switch(iChoice)
					{
						case 1 :
							cout << "\n\t\tORIGINAL LIST =>\n";
							DisplayIterator(lObj1);
							lObj1.PhysicalReverse();
							cout << "\n\n\t\tPHYSICALLY REVERSE LIST =>\n";
							DisplayIterator(lObj1);
							break;
						case 2 :
							lObj1.ReverseDisplay();
							break;
					}
				}
		}
	}	
}

template <typename T>
void DisplayIterator(list<T> &lParam)
{
	if(lParam.IsEmpty())
	{
		cout << "\n\t\tList Is Empty";
		return;
	}
		
	cout << "\n\t\tList Is : ";
	for(list<T>::iterator iter = lParam.begin(); iter != lParam.end(); ++iter)
		cout << "|" << *iter << "|->";
	cout << std::endl;
}
