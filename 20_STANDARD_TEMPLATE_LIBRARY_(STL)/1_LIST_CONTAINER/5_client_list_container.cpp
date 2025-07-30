#include <iostream>
#include "5_server_list_container.h"

void DisplayIterator(list&);

using std::cin;

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
						iData = lObj1.CountNodes();
						if(iPos <= 0 || iPos > iData)
						{
							cout << "\n\t\tINAVLID POSITION : " << iPos << "\n";
							DisplayIterator(lObj1);
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
				}
				break;
			case 4 :
				iData = lObj1.CountNodes();
				cout << "\n\t\tTotal Nodes : " << iData << "\n";
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
						iData = lObj1.CountNodes();
						if(iPos <= 0 || iPos > (iData + 1))
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
									iData = lObj2.CountNodes();
									if(iPos <= 0 || iPos > (iData + 1))
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
									iData = lObj2.CountNodes();
									if(iPos1 <= 0 || iPos1 > (iData + 1))
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
	return 0;
}

void DisplayIterator(list &lParam)
{
	if(lParam.IsEmpty())
	{
		cout << "\n\t\tList Is Empty";
		return;
	}
		
	cout << "\n\t\tList Is : ";
	for(list::iterator iter = lParam.begin(); iter != lParam.end(); ++iter)
		cout << "|" << *iter << "|->";
	cout << std::endl;
}
