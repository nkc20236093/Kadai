#include <iostream>
#include <string>
#include <regex>
using namespace std;

//①
//int型の変数a, bを宣言
//aを10、bを20で初期化
//変数aのアドレスを表示（aのアドレスは〇〇です）
//変数bのアドレスを表示（aのアドレスは〇〇です）
//aのアドレスを入れるポインタpaを作成
//bのアドレスを入れるポインタpbを作成
//それぞれのポインタから間接参照を用いて、
//aの値を100に、bの値を200に変更
//aの値を表示(aの値は〇〇です）
//bの値を表示(aの値は〇〇です）

void funcA(int* pa)
{
	*pa = 100;
}

void funcB(int* pa)
{
	*pa = 200;
}

//②
//値を変更する関数changeValueを作成（戻り値はvoid、引数はint型のポインタ）
//関数内では、受けとったポインタを間接参照演算子を用いて、値を500に変更する。
//
//main関数内で、changeValue関数を呼び出す。
//実引数に①の問題で作成した変数aのアドレスを入れる。
//その後、変数aの値の表示（changeValueを呼び出した後のaの値は〇〇です）

void changeValue(int* pa) 
{
	*pa = 500;
}

//③
//int型のポインタtempを作成。
//char型の変数inputを作成
//cinでinputに入力させる。
//
//inputに'a'が入っていたら、tempにはaのアドレスを入れ、
//'b'が入っていたらtempにはbのアドレスを入れる。
//（それ以外は入力エラーと表示）
//
//その後、tempの値を間接参照で表示する
//（入力された〇〇の値は〇〇です）

int main()
{
	int a = 10, b = 20;

	cout << "aのアドレスは" << &a << "です\n";
	cout << "bのアドレスは" << &b << "です\n";
	funcA(&a);
	cout << "aの値は" << a << "です\n";
	funcB(&b);
	cout << "bの値は" << b << "です\n";

	changeValue(&a);
	cout << "changeValueを呼び出した後のaの値は" << a << "です\n";
	
	int* temp;
	char input;
	cin >> input;

	if (input == 'a')
	{
		temp = &a;
		cout << "入力されたtempの値は" << *temp << "です\n";
	}
	else if (input == 'b')
	{
		temp = &b;
		cout << "入力されたtempの値は" << *temp << "です\n";
	}
	else
	{
		cout << "エラー\n";
	}
}
