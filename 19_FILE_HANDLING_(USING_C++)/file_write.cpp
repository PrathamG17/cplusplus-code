#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ios;
using std::wofstream;

int main(void)
{
	char *pName = "Prathamesh Bapu Gaikwad";

	wofstream fout("demo.txt", ios::app);

    std::time_t now = std::time(0);
	std::string str(std::ctime(&now));
    std::wstring date(str.begin(), str.end());
	
	fout <<"Date & Time Stamp : \t"<< date << endl << "------------------------------------------" << endl;
	
	fout.close();
	
	return 0;
}
