#include<iostream>//入出力関連ヘッダ読み込み
//自作ヘッダは「""」でくくってインクルード
#include "Test.h"


//std名前空間をしよう「std:」を省略できる
using namespace std;

//プロトタイプ宣言(関数宣言)
void Update();

void main() //メイン関数
{
    Update();

    TestUpdate();
}

//Update関数(中身を実装)
void Upddate()
{
    std::cout << "入出力関連\n"; //文字出力
    //   using 書いてたらcout << "入出力関連\n";  //文字出力
    int x;		// 整数
    float f;	// 少数
    char c;		// 文字型(1文字)
    string s;	// 文字列型
    cout << "xを入力\n"; cin >> x;
    cout << "xの値は" << x << "です\n";
    cout << "fを入力\n"; cin >> f;
    cout << "fの値は" << f << "です\n";
    cout << "cを入力\n"; cin >> c;
    cout << "cの値は" << c << "です\n";
    cout << "sを入力\n"; cin >> s;
    cout << "sの値は" << s << "です\n";
}
