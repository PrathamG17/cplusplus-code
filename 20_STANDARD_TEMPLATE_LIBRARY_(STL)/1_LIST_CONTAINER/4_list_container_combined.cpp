#include <iostream>

using std::cin;
using std::cout;
using std::ostream;

class list;
void DisplayIterator(list&);
ostream& operator << (ostream&, const list&);

class node
{
private :
	node *pPrev;
	int iNo;
	node *pNext;
	
	node(int iParam):pPrev(NULL), iNo(iParam), pNext(NULL){}
	
	~node()
	{
		iNo = 0;
		pPrev = pNext = NULL;
	}
	
	friend class list;
	friend ostream& operator << (ostream&, const list&);
};

class list
{
private :
	node *pFirst;
	node *pLast;
public :
	list():pFirst(NULL), pLast(NULL){}
	
	~list()
	{
		pFirst = pLast = NULL;
	}
	
	bool IsEmpty()const
	{
		if(NULL == pFirst)
			return true;
		return false;
	}
	
	void InsertFirst(int iData)
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
	
	void InsertLast(int iData)
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
	
	void InsertAtPosition(int iData, int iPos)
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
	
	int DeleteFirst()
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
	
	int DeleteLast()
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
	
	int DeleteAtPosition(int iPos)
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
	
	int SearchFirstOccurence(int iKey)const
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
	
	int SearchLastOccurence(int iKey)const
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
	
	int SearchAllOccrence(int iKey)const
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
	
	int CountNodes()const
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
	
	void ConcatList(list &lObj)
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
	
	void ConcatAtPosition(list &lObj, int iPos)
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
	
	void PhysicalReverse()
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
	
	void ReverseDisplay()const
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
	
	void DeleteAll()
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
	
	class iterator
	{
		node *pNode;
		
	public :
		iterator():pNode(NULL){}
		
		~iterator()
		{
			pNode = NULL;
		}
	
		void SetNode(node *pParam)
		{
			if(NULL == pParam)
				return;
			pNode = pParam;
		}
				
		iterator operator ++()
		{
			if(NULL == pNode)
			{
				cout << "\n\t\tLIST IS EMPTY";
				return *this;
			}
			pNode = pNode->pNext;
			return *this;
		}
		
		iterator operator ++(int)
		{
			if(NULL == pNode)
			{
				cout << "\n\t\tLIST IS EMPTY";
				return *this;
			}			
			iterator itObj;
			itObj.pNode = pNode;
			pNode = pNode->pNext;
			return itObj;
		}

		iterator operator --()
		{
			if(NULL == pNode)
			{
				cout << "\n\t\tLIST IS EMPTY";
				return *this;
			}
			pNode = pNode->pPrev;
			return *this;
		}
		
		iterator operator --(int)
		{
			if(NULL == pNode)
			{
				cout << "\n\t\tLIST IS EMPTY";
				return *this;
			}
			iterator itObj;
			itObj.pNode = pNode;
			pNode = pNode->pPrev;
			return itObj;
		}
		
		bool operator ==(iterator &itParam)
		{
			if(NULL == pNode)
			{
				cout << "\n\t\tLIST IS EMPTY";
				return false;
			}
			else if(NULL == itParam.pNode)
			{
				cout << "\n\t\tNULL PARAMETER RECEIVED";
				return false;
			}

			if(pNode == itParam.pNode)
				return true;
			return false;
		}

		bool operator !=(iterator &itParam)
		{
			if(NULL == pNode)
			{
				cout << "\n\t\tLIST IS EMPTY";
				return false;
			}
			else if(NULL == itParam.pNode)
			{
				cout << "\n\t\tNULL PARAMETER RECEIVED";
				return false;
			}

			if(pNode != itParam.pNode)
				return true;
			else
				return false;
		}
		
		bool operator <(iterator &itParam)
		{
			if(NULL == pNode)
			{
				cout << "\n\t\tLIST IS EMPTY";
				return false;
			}
			else if(NULL == itParam.pNode)
			{
				cout << "\n\t\tNULL PARAMETER RECEIVED";
				return false;
			}

			if(pNode->iNo < itParam.pNode->iNo)
				return true;
			return false;
		}

		bool operator <=(iterator &itParam)
		{
			if(NULL == pNode)
			{
				cout << "\n\t\tLIST IS EMPTY";
				return false;
			}
			else if(NULL == itParam.pNode)
			{
				cout << "\n\t\tNULL PARAMETER RECEIVED";
				return false;
			}

			if(pNode->iNo <= itParam.pNode->iNo)
				return true;
			return false;
		}

		bool operator >(iterator &itParam)
		{
			if(NULL == pNode)
			{
				cout << "\n\t\tLIST IS EMPTY";
				return false;
			}
			else if(NULL == itParam.pNode)
			{
				cout << "\n\t\tNULL PARAMETER RECEIVED";
				return false;
			}

			if(pNode->iNo > itParam.pNode->iNo)
				return true;
			return false;
		}

		bool operator >=(iterator &itParam)
		{
			if(NULL == pNode)
			{
				cout << "\n\t\tLIST IS EMPTY";
				return false;
			}
			else if(NULL == itParam.pNode)
			{
				cout << "\n\t\tNULL PARAMETER RECEIVED";
				return false;
			}

			if(pNode->iNo >= itParam.pNode->iNo)
				return true;
			return false;
		}
		
		int operator *()
		{
			if(NULL == pNode)
			{
				cout << "\n\t\tLIST IS EMPTY";
				return -1;
			}
			return pNode->iNo;
		}
	};

private :
	iterator startIter;
	iterator endIter;

public :
	iterator& begin()
	{
		startIter.SetNode(pFirst);
		return startIter;
	}
	
	iterator& end()
	{
		
		endIter.SetNode(pLast);
		return endIter;
	}

	friend ostream& operator << (ostream&, const list&);
};

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

int main(void)
{
	list lObj1;
	list lObj2;
	int iPos = 0;
	int iPos1 = 0;
	int iData = 0;
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
						//cout << lObj1; 
						break;
					}
					else if(3 == iChoice)
					{
						cout << "\n\t\tENTER POSITION : ";
						cin >> iPos;
						iData = lObj1.CountNodes();
						if(iPos <= 0 || iPos > (iData + 1))
						{
							cout << "\n\t\tINAVLID POSITION : " << iPos << "\n";
							DisplayIterator(lObj1);
							//cout << lObj1; 
							continue;
						}
					}
					cout << "\n\t\tENTER DATA : ";
					cin >> iData;
					switch(iChoice)
					{
						case 1 :
							lObj1.InsertFirst(iData);
							break;
						case 2 :
							lObj1.InsertLast(iData);
							break;
						case 3 :
							lObj1.InsertAtPosition(iData, iPos);
							break;
					}
					DisplayIterator(lObj1);
					//cout << lObj1; 
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
							//cout << lObj1; 
							continue;
					}
					else if(4 == iChoice)
					{
						DisplayIterator(lObj1);
						//cout << lObj1; 
						break;
					}
					else if(3 == iChoice)
					{
						cout << "\n\t\tENTER POSITION : ";
						cin >> iPos;
						iData = lObj1.CountNodes();
						if(iPos <= 0 || iPos > iData)
						{
							cout << "\n\t\tINAVLID POSITION : " << iPos << "\n";
							DisplayIterator(lObj1);
							//cout << lObj1; 
							continue;
						}
					}
					switch(iChoice)
					{
						case 1 :
							iData = lObj1.DeleteFirst();
							break;
						case 2 :
							iData = lObj1.DeleteLast();
							break;
						case 3 :
							iData = lObj1.DeleteAtPosition(iPos);
							break;
					}
					if(iData != -1)
					{
						cout << "\n\t\tDeleted Data is : " << iData << "\n";
						DisplayIterator(lObj1);
						//cout << lObj1; 
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
							//cout << lObj1; 
							continue;
					}
					else if(4 == iChoice)
					{
						DisplayIterator(lObj1);
						//cout << lObj1; 
						break;
					}
					cout << "\n\t\tENTER DATA TO BE SEARCH : ";
					cin >> iData;
					switch(iChoice)
					{
						case 1 :
							iPos = lObj1.SearchFirstOccurence(iData);
							if(iPos != -1)
								cout << "\n\t\tData " << iData << " Found First At Node " << iPos << "\n";
							else
								cout << "\n\t\tData Not Found\n";
							break;
						case 2 :
							iPos = lObj1.SearchLastOccurence(iData);
							if(iPos != -1)
								cout << "\n\t\tData " << iData << " Found Last At Node " << iPos << "\n";
							else
								cout << "\n\t\tData Not Found\n";
							break;
						case 3 :
							iPos = lObj1.SearchAllOccrence(iData);
							if(iPos != -1)
								cout << "\n\t\tData " << iData << " Found " << iPos << " Times\n";
							else
								cout << "\n\t\tList Is Empty\n";
							break;
					}
					DisplayIterator(lObj1);
					//cout << lObj1; 
				}
				break;
			case 4 :
				iData = lObj1.CountNodes();
				cout << "\n\t\tTotal Nodes : " << iData << "\n";
				DisplayIterator(lObj1);
				//cout << lObj1; 
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
							//cout << lObj1; 
							continue;
					}
					else if(3 == iChoice)
					{
						DisplayIterator(lObj1);
						//cout << lObj1; 
						break;
					}
					else if(2 == iChoice)
					{
						cout << "\n\t\tENTER POSITION : ";
						cin >> iPos;
						iData = lObj1.CountNodes();
						if(iPos <= 0 || iPos > (iData + 1))
						{
							cout << "\n\t\tINAVLID POSITION : " << iPos << "\n";
							DisplayIterator(lObj1);
							//cout << lObj1; 
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
										//cout << lObj1; 
										cout << "\n\n\t\tSECOND LIST =>\n";
										DisplayIterator(lObj2);
										//cout << lObj2; 
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
									iData = lObj2.CountNodes();
									if(iPos <= 0 || iPos > (iData + 1))
									{
										cout << "\n\t\tINAVLID POSITION : " << iPos;
										cout << "\n\t\tFIRST LIST =>\n";
										DisplayIterator(lObj1);
										//cout << lObj1; 
										cout << "\n\n\t\tSECOND LIST =>\n";
										DisplayIterator(lObj2);
										//cout << lObj2; 
										continue;
									}
								}
								cout << "\n\t\tENTER DATA : ";
								cin >> iData;
								switch(iChoice)
								{
									case 1 :
										lObj2.InsertFirst(iData);
										break;
									case 2 :
										lObj2.InsertLast(iData);
										break;
									case 3 :
										lObj2.InsertAtPosition(iData, iPos);
										break;
								}
								cout << "\n\t\tFIRST LIST =>\n";
								DisplayIterator(lObj1);
								//cout << lObj1; 
								cout << "\n\n\t\tSECOND LIST =>\n";
								DisplayIterator(lObj2);
								//cout << lObj2; 
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
										//cout << lObj1; 
										cout << "\n\n\t\tSECOND LIST =>\n";
										DisplayIterator(lObj2);
										//cout << lObj2; 
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
									iData = lObj2.CountNodes();
									if(iPos1 <= 0 || iPos1 > (iData + 1))
									{
										cout << "\n\t\tINAVLID POSITION : " << iPos1;
										cout << "\n\t\tFIRST LIST =>\n";
										DisplayIterator(lObj1);
										//cout << lObj1; 
										cout << "\n\n\t\tSECOND LIST =>\n";
										DisplayIterator(lObj2);
										//cout << lObj2; 
										continue;
									}
								}
								cout << "\n\t\tENTER DATA : ";
								cin >> iData;
								switch(iChoice)
								{
									case 1 :
										lObj2.InsertFirst(iData);
										break;
									case 2 :
										lObj2.InsertLast(iData);
										break;
									case 3 :
										lObj2.InsertAtPosition(iData, iPos1);
										break;
								}
								cout << "\n\t\tFIRST LIST =>\n";
								DisplayIterator(lObj1);
								//cout << lObj1; 
								cout << "\n\n\t\tSECOND LIST =>\n";
								DisplayIterator(lObj1);
								//cout << lObj2; 
							}
							break;
					}
					DisplayIterator(lObj1);
					//cout << lObj1; 
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
							//cout << lObj1; 
							continue;
					}
					else if(3 == iChoice)
					{
						DisplayIterator(lObj1);
						//cout << lObj1; 
						break;
					}
					switch(iChoice)
					{
						case 1 :
							cout << "\n\t\tORIGINAL LIST =>\n";
							DisplayIterator(lObj1);
							//cout << lObj1; 
							lObj1.PhysicalReverse();
							cout << "\n\n\t\tPHYSICALLY REVERSE LIST =>\n";
							DisplayIterator(lObj1);
							//cout << lObj1; 
							break;
						case 2 :
							lObj1.ReverseDisplay();
							break;
					}
				}
		}
	}
	return 0;
}

void DisplayIterator(list &lParam)
{
	for(list::iterator iter = lParam.begin(); iter != lParam.end(); ++iter)
		cout << "|" << *iter << "|->";
	cout << std::endl;
}
