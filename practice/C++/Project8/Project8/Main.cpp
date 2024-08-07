#include <iostream>
using namespace std;

// project8
// 関数のオーバーロードの練習
// 関数名：Area
// 戻り値：実数型
// 引数名：自由（引数の型は実数型）
// 機能：円の面積、長方形の面積、台形の面積
// を求める
// オーバーロードを用いて、Area関数を3つ作成
// し、機能を実装すること
// 関数宣言、デフォルト引数などを使うとなお良い

// 実行例
// 円の半径を入力>〇〇
// 半径〇〇の円の面積は〇〇です
//
// 長方形の幅、高さを入力>〇〇、〇〇
// 幅〇〇、高さ〇〇の長方形の面積は〇〇です
//
// 台形の底辺、高さを入力>〇〇
// 底辺〇〇、高さ○○の台形の面積は〇〇です

const double PI = 3.14;
float Area(float h, float w);
float Area(float r, float p = PI);
float Area(float t, float b, float h);

int main()
{
	float h1, w, r, t, b, h2, chou, en, dai;
	cout << "円の半径を入力-->";
	cin >> r;
	en = Area(r);
	cout << "円の面積は" << en << "です\n";

	cout << "長方形の幅、高さを入力を入力-->";
	cin >> h1, cin >> w;
	chou = Area(h1, w);
	cout << "長方形の面積は" << chou << "です\n";

	cout << "台形の上辺、下辺、高さを入力を入力-->";
	cin >> t, cin >> b, cin >> h2;
	dai = Area(t, b, h2);
	cout << "長方形の面積は" << dai << "です\n";
}

// 長方形
float Area(float h, float w)
{
	return static_cast<float>(h * w);
}
// 円
float Area(float r, double p) 
{
	return static_cast<float>(r * r * p);
}
// 台形
float Area(float t, float b, float h)
{
	return static_cast<float>((t + b) * h / 2);
}
