#include <iostream>
#include <cstdlib>	// atof
#include <cmath>	// atof
#include <string>
#include <fstream>
using namespace std;

// ��O����(�G���[�����������Ƃ��̏���)

// �N���X��throw����
class MyError
{
	double x;
public:
	void SetX(double d) { x = d; }
	void Error()
	{
		cout << x << "��10�����̐��l�ł͂Ȃ�";
	}
};

//// try
//int MyError(bool err)
//{
//	if (!err)
//	{
//
//	}
//}

int main()
{
#if false
	double x;
	// try�u���b�N(catch�ƃZ�b�g)
	try
	{
		cout << "���̐��l����͂��Ă�������\n"; 
		cin >> x;
		// try�����̒���throw����
		// �����catch�Ŏ󂯎��
		if (x < 1)
		{
			throw 1;
		}
		//if (x > 1.0)
		//{
		//	throw 1;
		//}
		cout << "���͂������l��" << x << "�ł�\n";
	}
	// catch�u���b�N
	catch (int)
	{
		cout << "���͂������l�͕s���ł�\n";
	}
	//catch (double)
	//{
	//	cout << "���͂������l�͕s���ł�\n";
	//} 

	// �����ʂ����s
	//while (1)
	//{
	//	try
	//	{
	//		cout << "1�ȏ�5���������(x�ŏI��)\n";
	//		char no[16];
	//		cin.getline(no, 16);
	//		if (no[0] == 'x')break;
	//		if (no[0] == 'X')throw'X';
	//		double x = atof(no);
	//		if (x >= 5.0) { throw 5; }
	//		if (x >= 0.0 && x < 1.0) { throw 0.5; }
	//		if (x < 0.0) { throw "���̐��l�����͂��ꂽ"; }
	//		cout << "x = " << x << endl;
	//	}
	//	catch (int)
	//	{
	//		cout << "5�ȏ�̐��l������\n";
	//	}
	//	catch (double)
	//	{
	//		cout << "1�����̐��l������\n";
	//	}
	//	catch (const char* str)
	//	{
	//		cout << str << endl;
	//	}
	//	// ��L�ȊO�̑S�Ă�catch�����ꍇ
	//	catch (...)
	//	{
	//		cout << "�I������Ƃ���x�����\n";
	//	}
	//}
	//ifstream infile;
	//string filename;
	//char ch;
	//try
	//{
	//	cout << "�t�@�C���� --- ";
	//	getline(cin, filename);
	//	infile.open(filename);
	//	// �t�@�C�����I�[�v���o������
	//	MyError(infile.is_open());
	//	while ((ch = infile.get() != EOF))
	//	{
	//		cout << ch;
	//	}
	//	infile.close();
	//}
	//catch ()
	//{

	//}

#endif


	char str[64];
	double d;
	try
	{
		MyError e;
		cout << "10�����̐��l����� --- ";cin.getline(str, 64);
		d = atof(str); e.SetX(d);
		if (d >= 10.0) { throw (e); }
		cout << "���͂������l:" << d << endl;
	}
	catch (MyError ex)
	{
		ex.Error();
	}
}