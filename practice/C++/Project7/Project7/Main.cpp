#include <iostream>
using namespace std;

// 定数
// 関数外に宣言したので、Main.cpp全部で使える
const double per = 0.1;

// 関数宣言
// 関数宣言でデフォルト引数を書く
int zei(int, double = per);	// 税込み価格を計算する関数

// 関数のオーバーロード(多重定義)
// 同じ名前の関数は、
// シグネチャ(引数の個数、引数の型)が違うと
// 宣言することができる
int zei(int x);

int main()
{
	int teika, total;
	cout << "定価(税抜き)-->";
	cin >> teika;
	// デフォルト引数がある関数は
	// 関数呼び出しの再に引数を省略できる
	// zeiは引数2つだか、1つで呼び出している
	//total = zei(teika);
	cout << "税込み価格" << total << "です\n";
}

// 税込み価格を計算する関数
// デフォルト実引数を用いた関数
// 
int zei(int x, double r)
{
	return static_cast<int>(x * (per + 1));
}

//引数1つ番のzei関数
int zei(int x)
{
	return static_cast<int>(x * (per + 1));
}