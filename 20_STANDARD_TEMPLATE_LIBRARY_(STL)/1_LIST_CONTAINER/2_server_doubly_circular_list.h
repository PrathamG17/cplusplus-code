#include <iostream>

using std::ostream;

class list;
ostream& operator << (ostream&, const list&);

class node
{
private :
	node *pPrev;
	int iNo;
	node *pNext;
	
	node(int);
	~node();
	
	friend class list;
	friend ostream& operator << (ostream&, const list&);
};

class list
{
private :
	node *pFirst;
	node *pLast;

public :
	list();
	~list();
	bool IsEmpty()const;	
	void InsertLast(int);
	void InsertFirst(int);
	void InsertAtPosition(int, int);
	int DeleteLast();
	int DeleteFirst();
	int DeleteAtPosition(int);
	int SearchFirstOccurence(int)const;
	int SearchLastOccurence(int)const;
	int SearchAllOccrence(int)const;
	int CountNodes()const;
	void ConcatList(list&);
	void ConcatAtPosition(list&, int);
	void PhysicalReverse();
	void ReverseDisplay()const;
	void DeleteAll();

	friend ostream& operator << (ostream&, const list&);
};
