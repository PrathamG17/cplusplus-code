#include <iostream>

using std::cin;
using std::cout;
using std::ostream;

template <typename T>
void MyMain(void);

template <typename T>
class list;
template <typename T>
ostream& operator << (ostream&, const list<T>&);

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
	node<T> *pFirst;
	node<T> *pLast;

public :
	list();
	~list();
	bool IsEmpty()const;	
	void InsertLast(T);
	void InsertFirst(T);
	void InsertAtPosition(T, int);
	T DeleteLast();
	T DeleteFirst();
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

	template <typename T>
	friend ostream& operator << (ostream&, const list<T>&);
};

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
		cout << "\n\t\t7)BACK";
		cout << "\n\t\t------------------------";
		cout << "\n\t\tENTER YOUR CHOICE : ";
		cin >> iChoice;
		cout << "\n\t\t------------------------";
		if(iChoice <= 0 || iChoice > 7)
		{
			cout << "\n\t\tENTER VALID CHOICE!\n";
			cout << lObj1;
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
						cout << lObj1; 
						break;
					}
					else if(3 == iChoice)
					{
						cout << "\n\t\tENTER POSITION : ";
						cin >> iPos;
						iCount = lObj1.CountNodes();
						if(iPos <= 0 || iPos > (iCount + 1))
						{
							cout << "\n\t\tINAVLID POSITION : " << iPos << "\n";
							cout << lObj1; 
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
					cout << lObj1; 
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
							cout << lObj1; 
							continue;
					}
					else if(4 == iChoice)
					{
						cout << lObj1; 
						break;
					}
					else if(3 == iChoice)
					{
						cout << "\n\t\tENTER POSITION : ";
						cin >> iPos;
						iCount = lObj1.CountNodes();
						if(iPos <= 0 || iPos > iCount)
						{
							cout << "\n\t\tINAVLID POSITION : " << iPos << "\n";
							cout << lObj1; 
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
						cout << lObj1; 
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
							cout << lObj1; 
							continue;
					}
					else if(4 == iChoice)
					{
						cout << lObj1; 
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
					cout << lObj1; 
				}
				break;
			case 4 :
				iCount = lObj1.CountNodes();
				cout << "\n\t\tTotal Nodes : " << iCount << "\n";
				cout << lObj1; 
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
							cout << lObj1; 
							continue;
					}
					else if(3 == iChoice)
					{
						cout << lObj1; 
						break;
					}
					else if(2 == iChoice)
					{
						cout << "\n\t\tENTER POSITION : ";
						cin >> iPos;
						iCount = lObj1.CountNodes();
						if(iPos <= 0 || iPos > (iCount + 1))
						{
							cout << "\n\t\tINAVLID POSITION : " << iPos << "\n";
							cout << lObj1; 
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
										cout << lObj1; 
										cout << "\n\n\t\tSECOND LIST =>\n";
										cout << lObj2; 
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
									iCount = lObj2.CountNodes();
									if(iPos <= 0 || iPos > (iCount + 1))
									{
										cout << "\n\t\tINAVLID POSITION : " << iPos;
										cout << "\n\t\tFIRST LIST =>\n";
										cout << lObj1; 
										cout << "\n\n\t\tSECOND LIST =>\n";
										cout << lObj2; 
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
								cout << lObj1; 
								cout << "\n\n\t\tSECOND LIST =>\n";
								cout << lObj2; 
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
										cout << lObj1; 
										cout << "\n\n\t\tSECOND LIST =>\n";
										cout << lObj2; 
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
									iCount = lObj2.CountNodes();
									if(iPos1 <= 0 || iPos1 > (iCount + 1))
									{
										cout << "\n\t\tINAVLID POSITION : " << iPos1;
										cout << "\n\t\tFIRST LIST =>\n";
										cout << lObj1; 
										cout << "\n\n\t\tSECOND LIST =>\n";
										cout << lObj2; 
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
								cout << lObj1; 
								cout << "\n\n\t\tSECOND LIST =>\n";
								cout << lObj2; 
							}
							break;
					}
					cout << lObj1; 
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
							cout << lObj1; 
							continue;
					}
					else if(3 == iChoice)
					{
						cout << lObj1; 
						break;
					}
					switch(iChoice)
					{
						case 1 :
							cout << "\n\t\tORIGINAL LIST =>\n";
							cout << lObj1; 
							lObj1.PhysicalReverse();
							cout << "\n\n\t\tPHYSICALLY REVERSE LIST =>\n";
							cout << lObj1; 
							break;
						case 2 :
							lObj1.ReverseDisplay();
							break;
					}
				}
		}
	}
}
