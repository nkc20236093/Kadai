#include <iostream>
#include <map>
#include <string>
using namespace std;

// マップクラス
// キーと値のペアでデータを格納するコンテナ
// ("ラーメン",800) みたいなイメージ

//int main()
//{
//	map <string, int> m;
//	map <string, int>::iterator pm;
//	// mapコンテナにはinsert関数を使って格納
//	m.insert(pair<string, int>("ラーメン", 500));
//	m.insert(pair<string, int>("カレー", 550));
//	m.insert(pair<string, int>("オムライス", 600));
//	m.insert(pair<string, int>("チャーハン", 500));
//	// キーを使って値を取得
//	cout << "カレーは" << m["カレー"] << "円です\n\n";
//	// イテレータを使って全表示
//	pm = m.begin();
//	while (pm != m.end())
//	{
//		cout << pm->first << " -------- " << pm->second << "円\n";
//		// 次へ
//		++pm;
//	}
//
//}
