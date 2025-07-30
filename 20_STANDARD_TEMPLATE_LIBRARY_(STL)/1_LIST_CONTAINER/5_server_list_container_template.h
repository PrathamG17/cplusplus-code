#include <iostream>

using std::cout;
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
