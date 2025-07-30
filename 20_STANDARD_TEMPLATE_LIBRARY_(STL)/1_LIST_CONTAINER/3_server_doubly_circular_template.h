#include <iostream>

using std::ostream;

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
