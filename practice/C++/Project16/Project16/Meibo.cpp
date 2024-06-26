#include "Meibo.h"
using namespace std;

// statick変数の初期化
// statick変数はクラスの外部で初期化する
double Meibo::bw_total = 0.0;
double Meibo::bl_total = 0.0;
int Meibo::No_of_obj = 0;

// 静的メンバ関数
// 静的メンバ関数はthisポインタ関数を持たない
// クラスのstaticではない変数、関数にアクセスできない
void Meibo::GetMean()
{
	if (No_of_obj != 0)
	{
		cout << "現在のデータ数は" << No_of_obj << "件\n";
		cout << "現在の体重の合計は" << bw_total << endl;
		cout << "現在の身長の合計は" << bl_total << endl;
		cout << "現在の平均体重は" << bw_total / No_of_obj << endl;
		cout << "現在の平均身長は" << bl_total / No_of_obj << endl;
	}
	else
	{
		cout << "Error!!\n";
	}
}

void Meibo::SetData()
{
	cout << "氏名 --- "; cin >> name;
	cout << "体重 --- "; cin >> bw;
	cout << "身長 --- "; cin >> bl;
	bw_total += bw;	// 体重の合計値を加算
	bl_total += bl;	// 身長の合計値を加算
}

// コンストラクタ
Meibo::Meibo()
{
	SetData();
	// 生成したら数を加算
	No_of_obj++;
}
