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
		cerr << "�I�[�v���G���[!!" << endl;
		return -1;
	}
	of << "�e�X�g�������݂ł�" << endl;
	of.close();
}
#endif //  false
