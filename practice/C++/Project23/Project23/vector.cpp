#include <iostream>
#include <vector>
using namespace std;

// 標準テンプレートライブラリ
// STL(Standard Template Library)
// コンテナ、反復子、アルゴリズムが主

int main()
{
#if false
	// Vectorクラス(STLが用意するコンテナの1つ)
	// 配列のような連続でオブジェクトを保管できるクラス
	// 配列はあらかじめ要素数を設定しないといけないがVectorは幾つでも追加できる

	vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i * 2); // vectorの末尾にデータを追加
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << "v[" << i << "]" << v[i] << endl;
	}

	// 反復子
	// イテレータ(iterator)
	// コンテナ内の要素に順番にアクセスする方法を提供する
	vector<int> v;			  // コンテナ
	vector<int>::iterator pv; // 反復子
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(20 - i);
	}
	pv = v.begin();
	// 反復子が末尾(の次)を指してないならループ
	while (pv != v.end())
	{
		cout << *pv << ", "; // 反復子が指す要素を表示
		++pv;				 // 次の要素へ
	}
	cout << endl;

#endif
	vector<char> v(4); // 4つの要素を持つと指定
	vector<char>::iterator pv;
	// 4つ分の要素を反復子で設定
	pv = v.begin();
	*pv = 'x'; // 間接演算子を使って、iteratorが指す場所に要素を代入
	++pv;
	*pv = 'y';
	++pv; *pv = 'z';
	++pv; *pv = 'a';
	// 反復子を使わずに要素を表示
	for (vector<char>::size_type i = 0; i < v.size(); ++i)
	{
		cout << v[i] << ", ";
	}
	cout << endl;
	// 反復子を使った表示
	for (pv = v.begin(); pv != v.end(); ++pv)
	{
		cout << *pv << ", ";
	}
	cout << endl;
}

