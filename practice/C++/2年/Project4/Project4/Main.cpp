#include <iostream>
using namespace std;

#include "Human.h" //自作ヘッダをインクルード

void main()
{
    cout << "project4\n";
    //Humanクラスの実体を作成
    //クラスの実体（変数）を作成すると、
    //コンストラクタが呼び出される
    Human h1;
    h1.DispSpace();  //表示関数呼び出し

    //引数ありコンストラクタの呼び出し
    //実体（変数）を定義する際に()を付けて
    //コンストラクタを呼び出す

    Human h2(18, "滝瑛太", "男");
    h2.DispSpace();  //表示関数呼び出し
}
