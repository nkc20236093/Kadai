#include <iostream>
using namespace std;

int mani()
{
	//キャスト演算子(p86)

	// 10/4の結果は2.5だが整数の型の計算なので
	// 小数部は消え、2になる
	float a = 10;
	int b = 4;
	cout << "a / b = " << (a / b) << "\n";
	// 型を無理やり変換する
	// 変換したい型で()を使ってくくると
	// その型は変換される
	// float型のaとint型のbの計算では
	// 計算結果がfloatに暗黙的に変換される
	cout << "a / b = " << (float)(a / b) << "\n";

	// 高度な方変換
	double d;
	d = static_cast<double>(a) / b;
	cout << "d = " << d << "\n";

	// const_cast<型>(変数)
	const int ca = 10; //constは定数
	// ca = 10;
	// このcaをconst?castで無理やり変更できるがほぼ使わないので名前だけ覚えておく

	// reinterprest_cast<型>(変数)
	// ポインタを別の型に変換するのに使う。
	// 使用するには危険を伴う
	// void* ptr;
	// Player* pl;
	// pl = reinterpret_cast<Player>(ptr);

	// ビット演算(p71)

	// unsigned…正の値のみ
	// signed…正の値・負の値の両方扱う
	// 普段使ってるintは実はsigned int
	// shortも整数型(intよりも扱える値が小さい)
	// intは32bit(環境によって変化)
	// shortは16bit(環境によって変化)
	// 0000 0000 0000 0000
	unsigned short sa, sb;
	sa = 1;	// 0001
	sb = 3; // 0011

	// ビット席
	cout << "sa & sb = " << (sa & sb) << endl;
	// ビット和
	cout << "sa | sb = " << (sa | sb) << endl;
	// ビット差
	cout << "sa ^ sb = " << (sa ^ sb) << endl;
	// 否定(0と1の反転)
	cout << "~sa = " << (unsigned short)(~sa);

	// シフト演算
	short sx = 12;

	// 0000 0110
	// 0000 1100 //左シフト1すると↓、右シフト1すると↑
	// 0001 1000
	// 0011 0000 // 左シフト2
	cout << sx << "を左に0シフト = " << (sx << 0) << endl;
	cout << sx << "を左に1シフト = " << (sx << 1) << endl;
	cout << sx << "を左に2シフト = " << (sx << 2) << endl;
	
	//武器取得フラグ
	enum  WepaonGet
	{
		Sword	 = (1 << 0), // 0000 0001
		Gun		 = (1 << 1), // 0000 0010
		Hanmmer  = (1 << 2), // 0000 0100
		Lance	 = (1 << 3), // 0000 1000
		Arrow	 = (1 << 4), // 0001 0000
		Axe		 = (1 << 5), // 0010 0000
		Knife	 = (1 << 6), // 0100 0000
		Clab	 = (1 << 7), // 1000 0000
	};
	unsigned short wFlag = 0;
	wFlag |= WepaonGet::Sword; //Swordを取得した
	wFlag |= WepaonGet::Gun;   //Gunを取得した

	if (wFlag & WepaonGet::Sword)
	{
		cout << "Swordを取得している\n";
	}
	if (wFlag & WepaonGet::Gun)
	{
		cout << "Gunを取得している\n";
	}
	if (wFlag & WepaonGet::Axe)
	{
		cout << "Axeを取得している\n";
	}
	return b;
}