#include <iostream>

using std::cout;
using std::ostream;

class list;
ostream& operator << (ostream&, const list&);

class node
{
private :
	node *pPrev;
	int iNo;
	node *pNext;
	
	node(int, node*, node*);
	~node();
	
	friend class list;
	friend ostream& operator << (ostream&, const list&);
};

class list
{
private :
	node *pDummy;

public :
	list();
	~list();
	bool IsEmpty()const;
	void InsertFirst(int);
	void InsertLast(int);
	void InsertAtPosition(int, int);
	int DeleteFirst();
	int DeleteLast();
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

private :
	node *Initialize();
	void SetIterator(const node *);

public :	
	class iterator
	{
	private:
		node *pNode;
		
	public :
		iterator(const node*);
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
		int operator *()const;
		
		friend 	void list::SetIterator(const node *);
	};

private :
	iterator startIter;
	iterator endIter;

public :
	iterator& begin();
	iterator& end();

	friend ostream& operator << (ostream&, const list&);
};
