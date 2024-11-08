#include <iostream>
#include <cstdlib>	// atof
#include <cmath>	// atof
#include <string>
#include <fstream>
using namespace std;

// 例外処理(エラーが発生したときの処理)

// クラスをthrowする
class MyError
{
	double x;
public:
	void SetX(double d) { x = d; }
	void Error()
	{
		cout << x << "は10未満の数値ではない";
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
	// tryブロック(catchとセット)
	try
	{
		cout << "正の数値を入力してください\n"; 
		cin >> x;
		// try処理の中でthrowをし
		// それをcatchで受け取る
		if (x < 1)
		{
			throw 1;
		}
		//if (x > 1.0)
		//{
		//	throw 1;
		//}
		cout << "入力した数値は" << x << "です\n";
	}
	// catchブロック
	catch (int)
	{
		cout << "入力した数値は不正です\n";
	}
	//catch (double)
	//{
	//	cout << "入力した数値は不正です\n";
	//} 

	// 書き写し失敗
	//while (1)
	//{
	//	try
	//	{
	//		cout << "1以上5未満を入力(xで終了)\n";
	//		char no[16];
	//		cin.getline(no, 16);
	//		if (no[0] == 'x')break;
	//		if (no[0] == 'X')throw'X';
	//		double x = atof(no);
	//		if (x >= 5.0) { throw 5; }
	//		if (x >= 0.0 && x < 1.0) { throw 0.5; }
	//		if (x < 0.0) { throw "負の数値が入力された"; }
	//		cout << "x = " << x << endl;
	//	}
	//	catch (int)
	//	{
	//		cout << "5以上の数値が入力\n";
	//	}
	//	catch (double)
	//	{
	//		cout << "1未満の数値が入力\n";
	//	}
	//	catch (const char* str)
	//	{
	//		cout << str << endl;
	//	}
	//	// 上記以外の全てをcatchした場合
	//	catch (...)
	//	{
	//		cout << "終了するときはxを入力\n";
	//	}
	//}
	//ifstream infile;
	//string filename;
	//char ch;
	//try
	//{
	//	cout << "ファイル名 --- ";
	//	getline(cin, filename);
	//	infile.open(filename);
	//	// ファイルがオープン出来たら
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
		cout << "10未満の数値を入力 --- ";cin.getline(str, 64);
		d = atof(str); e.SetX(d);
		if (d >= 10.0) { throw (e); }
		cout << "入力した数値:" << d << endl;
	}
	catch (MyError ex)
	{
		ex.Error();
	}
}