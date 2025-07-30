#include "3_server_doubly_circular_template.h"

template <typename T>
void MyMain(void);

using std::cin;
using std::cout;

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
