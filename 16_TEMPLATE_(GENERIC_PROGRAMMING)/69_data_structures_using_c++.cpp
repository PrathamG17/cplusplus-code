#include <iostream>
#include <malloc.h>

template <typename T>
class list;

template <typename T>
class node
{
	T Data;
	node<T> *pNext;

public:
	node(void);
	~node(void);

	template <typename T>
	friend class list;
};

template <typename T>
class list
{
	node<T> *pFirst;
	
public:
	list(void);
	~list(void);
	void Display();
	void DeleteAll();
	void InsertLast(T);
};

int main(void)
{
	list <char>lObj;
	
	lObj.InsertLast(65);
	lObj.Display();

	lObj.InsertLast(66);
	lObj.Display();
	
	lObj.InsertLast(67);
	lObj.Display();
	
	lObj.InsertLast(68);
	lObj.Display();
	
	lObj.InsertLast(69);	
	lObj.Display();

	lObj.DeleteAll();
	lObj.Display();
	
	return 0;
}
//node 
template <typename T>
node<T>::node(void)
{
	Data = 0;
}
template <typename T>
node<T>::~node(void)
{
	Data = 0;
	pNext = NULL;
}
//list
template <typename T>
list<T>::list(void)
{
	pFirst = NULL;
}
template <typename T>
list<T>::~list(void)
{
	if(pFirst != NULL)
	{
		DeleteAll();
		pFirst = NULL;
	}
}
template <typename T>
void list<T>::InsertLast(T Data)
{
	node<T> *pTemp = NULL;
	node<T> *pNewNode = NULL;
	
	pNewNode = new node<T>;
	if(NULL == pNewNode)
	{
		std::cout <<"\nMemory Allocation Failed\n";
		return;
	}
	
	pNewNode->Data = Data;
	pNewNode->pNext = NULL;
	
	if(NULL == pFirst)
	{
		pFirst = pNewNode;
		return;
	}
	
	pTemp = pFirst;
	while(pTemp->pNext != NULL)
		pTemp = pTemp->pNext;
	
	pTemp->pNext = pNewNode;
}
template <typename T>
void list<T>::DeleteAll(void)
{
	node<T> *pTemp = NULL;
	
	if(NULL == pFirst)
	{
		std::cout <<"\nList Is Empty\n";
		return;
	}
	
	while(pFirst != NULL)
	{
		pTemp = pFirst;
		pFirst = pTemp->pNext;
		pTemp->pNext = NULL;
		delete pTemp;
	}
	
	pFirst = NULL;
	std::cout <<"\nData Deleted Successfully\n";
}
template <typename T>
void list<T>::Display(void)
{
	node<T> *pHead = pFirst;
	
	if(NULL == pHead)
	{
		std::cout <<"\nList Is Empty\n";
		return;
	}
	
	std::cout <<"\nList Is : ";
	
	while(pHead != NULL)
	{
		std::cout <<"|" << pHead->Data <<"|->";
		pHead = pHead->pNext;
	}

	std::cout << std::endl;
}
