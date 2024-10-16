#include <iostream>
#include <fstream>
using namespace std;

#if  false
int main()
{
	ofstream of;
	of.open("test.txt", ios_base::app);
	if (!of)
	{
		cerr << "オープンエラー!!" << endl;
		return -1;
	}
	of << "テスト書き込みです" << endl;
	of.close();
}
#endif //  false
