#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string fname;
	cout << "�t�@�C����--- "; getline(cin, fname);
	// �t�@�C�������w�肵�āAifstream�I�u�W�F�N�g���쐬
	ifstream ifs(fname.c_str());
	if (!ifs) 
	{
		cerr << "�t�@�C���I�[�v���G���[!! \n"; return -1;
	}
	char ch;
	// ifstream::get�֐�
	// 1�����ǂݎ��
	while ((ch = ifs.get() != EOF))
	{
		cout << ch;
	}
}