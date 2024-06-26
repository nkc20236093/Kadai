#include <iostream>
using namespace std;

// 自作ヘッダ
#include "MyClass.h"
#include "BMI.h"
#include "Person.h"
#include "Menseki.h"
#include "MyClass2.h"
#include "MyClass3.h"
#include "Meibo.h"

// クラスとは
// データ、関数などをまとめた型
// ユーザーが自由に作成できるユーザー定義型

class Human 
{
	// アクセス指定子：非公開
private:
	// データメンバ（メンバ変数）
	int age;
	string gender;
	// ここまで非公開
	// アクセス指定子：公開
	void DispPlay() 
	{
		cout << "表示します\n";
	}
	// ここまで公開
};

// コンストラクタ無し
class Test1
{
	int x;
	// コンストラクタが定義されてないクラスは
	// デフォルトコンストラクタが暗黙的に用意される
};

// デフォルトコンストラクタを定義
// デフォルトコンストラクタは引数無しのコンストラクタ
// 自前で実装することができる

// 自前で実装することもできる
class Test2
{
	int x;
	Test2() :x(100) {}
};

// 
class Test3
{
	int x;
public:
	// 引数有りのコンストラクタを作ると
	// デフォルトコンストラクタは自動生成されないので
	// 自前で実装する必要がある
	Test3() :x(100) {}
	Test3(int a) : x(a) {}
	// デフォルト引数があるコンストラクタ
	Test3(int a, int b, int c) :x(a + b + c) {}
};

int main()
{
#if false
	// クラスの実体（インスタンス）作成
	MyClass mc{};

	// bは公開部なので、アクセス可能
	mc.b = 100;
	cout << "b = " << mc.b << endl;

	// aは非公開なのでアクセスできない
	//mc.a = 100;

	// 公開のset_a()を使用し、非公開のaの値を設定
	mc.set_a();
	// 公開のshow_a()を使用し、非公開のaの値を表示
	mc.show_a();
	BMI b{};
	b.SetData();
	b.ShowBMI();
	Person p("aaaa", 100, 'M');
	
	// 人間クラスの作成
	Person yamada("山田太郎", 26, 'M');
	Person hanako("田中花子", 24, 'F');
	cout << "-----------------" << endl;
	yamada.Show();
	cout << "-----------------" << endl;
	hanako.Show();
	cout << "-----------------" << endl;
	
	Menseki circle(1.5), rect(5.2, 2.5), daikei(2.5, 4.5, 3.0);
	cout << "半径1.5の円の面積は" << circle.show() << "です\n";
	cout << "縦5.2、横2.5の長方形の面積は" << rect.show() << "です\n";
	cout << "上辺2.5、下底4.5、高さ3.0の台形の面積は" << daikei.show() << "です\n";

	Test3 a1;
	Test3(5);
	Test3(1, 2, 3);

	// MyClass2の実体作成
	MyClass2 a(10, 100);
	// コピーコンストラクタによる初期化
	// 初期化の際に自分自身のクラスを代入
	MyClass2 b = a;
	// MyClass2 b(a);　この書き方も可 

	// 代入(コピーコンストラクタは呼ばれない)
	b = a;

	a.show();
	b.show();

	MyClass2 a(10, 100);
	a.show();
	// コピーコンストラクタでコピー
	// コピーコンストラクタでポインタをコピーすると
	// バグが起きる可能性がある
	// bの*pxはbのxのアドレスではなく、aのxのアドレスをもってしまう
	MyClass2 b = a;
	b.show();

	MyClass2 a(10, 100);
	MyClass2 b = a;
	a.show();
	b.show();

	MyClass3 a;
	a.SetX(10);
	int num;
	a.ReadX(&num);
	cout << "x = " << num << endl;

	Meibo man[3];
	for (int i = 0; i < 3; ++i)
	{
		man[i].SetData();
	}

	// 静的データメンバはスコープ解決演算子で使用する
	// Meibo::bw_total
	cout << "体重の合計:" << Meibo::bw_total << endl;
	cout << "身長の合計:" << Meibo::bl_total << endl;

#endif
	string end;
	while (1)
	{
		Meibo person;
		// 静的メンバ関数呼び出し
		// クラス名::関数で呼び出す
		Meibo::GetMean();
		cout << "続けますか?(y/n)";
		cin >> end;
		if (end[0] == 'n')
		{
			break;
		}
		cout << "----------------\n";
	}

	return 0;
}
