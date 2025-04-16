#include <iostream>
using namespace std;

int main()
{
	// 変数はスタックメモリに配置される
	// スタックメモリの特徴
	// メモリのアクセスは早いが容量は小さめ
	// 変数はスコープ外で消える
	int a;

	// キープメモリ
	// 大容量でアクセスが遅め
	// 一度消えたら自分で消すまで消えない
	int num;
	cout << "確保する要素数を入力\n";
	cin >> num;
	// new演算子を用いて、ヒープ領域からメモリ確保
	// new演算子は確保したアドレスを得る
	int* ptr = new int[num];
	for (int i = 0; i < num; ++i)
	{
		cout << i << "番目のデータ:";
		cin >> ptr[i];
	}
	for (int i = 0; i < num; ++i)
	{
		cout << i << "番目のデータは:" << ptr[i] << endl;
	}
	// delte演算子で消す
	// 今回は配列なので、delete[]演算子を使う
	delete[] ptr;
}