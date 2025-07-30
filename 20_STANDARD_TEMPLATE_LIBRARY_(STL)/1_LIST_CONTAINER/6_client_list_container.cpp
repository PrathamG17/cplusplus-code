#include "6_server_list_container.h"

void PrintList(list&, list&);

using std::endl;

int main(void)
{
	list lObj1;
	list lObj2;
	
	for(int i = 0; i < 6; i++)
	{
		lObj1.push_back(i + 65);
		lObj2.push_front(i + 65);
	}
	
	PrintList(lObj1, lObj2);
	
	lObj2.splice(find(lObj2.begin(), lObj2.end(), 69), lObj1);
	
	PrintList(lObj1, lObj2);
	
	lObj2.splice(lObj2.end(), lObj2, lObj2.begin());
	
	PrintList(lObj1, lObj2);
	
	lObj2.sort();
	
	lObj1 = lObj2;
	
	lObj2.unique();
	
	PrintList(lObj1, lObj2);
	
	lObj1.merge(lObj2);
	
	PrintList(lObj1, lObj2);
	
	return 0;
}

void PrintList(list &lParam1, list &lParam2)
{
	cout << "List 1 is : ";
	for(list::iterator iter = lParam1.begin(); iter != lParam1.end(); ++iter)
		cout << *iter << " ";
	
	cout << endl << "List 2 is : ";
	for(list::iterator iter = lParam2.begin(); iter != lParam2.end(); ++iter)
		cout << *iter << " ";

	cout << endl << endl;
}
