#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string fname;
	cout << "ファイル名--- "; getline(cin, fname);
	// ファイル名を指定して、ifstreamオブジェクトを作成
	ifstream ifs(fname.c_str());
	if (!ifs) 
	{
		cerr << "ファイルオープンエラー!! \n"; return -1;
	}
	char ch;
	// ifstream::get関数
	// 1文字読み取る
	while ((ch = ifs.get() != EOF))
	{
		cout << ch;
	}
}