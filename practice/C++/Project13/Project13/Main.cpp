#include <iostream>
#include <cstring> //文字列関連の機能
using namespace std;

int main()
{
	char str1[32];
	char str2[32];
	cout << "str1を入力\n";
	cin.getline(str1, 32);
	cout << "str2を入力\n";
	cin.getline(str2, 32);
	int cmp = strcmp(str1, str2); // 文字列比較
	if (cmp < 0) 
	{
		cout << str1 << "は" << str2 << "よりも前にある";
	}
	else if (cmp > 0)
	{
		cout << str1 << "は" << str2 << "よりも後ろにある";
	}
	else
	{
		cout << str1 << "と" << str2 << "は同じ文字列";
	}
	cout << endl;
	
	rsize_t len; // 文字列の長さを求める
	len = strlen(str1);
	cout << str1 << "の長さは" << len << "です\n";

	// 文字列のコピー
	// strcpyはエラーが起きやすい問題がある
	// strcp_sを使うようになった
	// (コピーするサイズを指定する)
	strcpy_s(str1, 32, "aaa");
	cout << "strcpy後のstr1は" << str1 << "です\n";

	// 文字列の連結
	// strcat
	strcat_s(str1, 32, "様");
	cout << "strcat後のstr1は" << str1 << "です\n";

	// stringというめっちゃ便利なもの
	string s1 = "aaa", s2 = "sama";
	s1 + s2;	// 連結は+で出来る
	int size = s1.length();
	cout << size << endl;
	cout << s1[0] << endl;			// 1文字目の文字にアクセス
	rsize_t index = s2.find("m");	// 文字の場所を検索
	if (s1 == "aaa")
	{
		cout << "同じ!!";
	}
}