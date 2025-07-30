#include <iostream>

using std::cout;
using std::ostream;

class list;
class node;
ostream& operator << (ostream&, const list&);

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
	
	class iterator;	
	
	void sort();
	void unique();
	iterator& end();
	iterator& begin();
	void merge(list&);
	void push_back(int);
	void push_front(int);
	void operator =(const list&);
	void splice(list::iterator &itParam1, list &lParam2, list::iterator &itParam3 = argIter);

private :
	node *Initialize();
	void SetIterator(const node *);	
	static node* GetIterator(const list::iterator&);

public :	
	class iterator
	{
	private:
		node *pNode;
		
	public :
		iterator();
		iterator(const node*);
		iterator(const iterator&);
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
		friend node* list::GetIterator(const list::iterator&);
	};

private :
	iterator startIter;
	iterator endIter;
	static iterator argIter;
	
	friend ostream& operator << (ostream&, const list&);
	friend list::iterator find(const list::iterator&, const list::iterator&, const int);
};

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
	friend list::iterator find(const list::iterator&, const list::iterator&, const int);
};

list::iterator find(const list::iterator&, const list::iterator&, const int);
