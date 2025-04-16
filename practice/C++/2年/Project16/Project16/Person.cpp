#include <iostream>
#include "Person.h"
using namespace std;

// コンストラクタの定義
// 初期化リストを使ってメンバ変数を初期化
// 関数内での初期化より初期化リストの方が処理の効率がいい
Person::Person(const string& nm, int n, char s) :name(nm), age(n), sex(s)
{
	cout << "Personのコンストラクタ呼び出し\n";
}
int Person::Show()
{
	cout << "氏名 : " << name << endl;
	cout << "年齢 : " << age << endl;
	cout << "性別 : " << sex << endl;
	return 0;
};