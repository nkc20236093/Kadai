#include<iostream>
using namespace std;
int main()
{
    char c;
    int i;
    double d, e;
    //変数はメモリ上のどこかに配置される
    //配置された場所をアドレスといい、
    //そのアドレスを表示するのが
    //「&」のアドレス演算子
    //&a のように変数の前に付ける
    //文字や文字列のアドレス表示は
    //void*型にキャスト　例: (void*)&c
    cout << "変数cのアドレス" << (void*)&c << "です\n";
    cout << "変数iのアドレス" << &i << "です\n";
    cout << "変数dのアドレス" << &d << "です\n";
    cout << "変数eのアドレス" << &e << "です\n";

    //変数のサイズ（バイト数）を表示
    //sizeofを使うと、変数のサイズがわかる
    cout << "char型:" << sizeof(c) << endl;
    cout << "int型:" << sizeof(i) << endl;
    cout << "float型:" << sizeof(float) << endl;
    cout << "double型:" << sizeof(d) << endl;

    //ポインタとは
    //アドレスを入れるための変数のこと
    //「*」というポインタ演算子を使う
    //例 int型のaのアドレスを入れるポインタを作る
    //int a;
    //int *pa =&a;
    //int型のaのアドレスを入れるポインタを作る場合
    //int型のポインタだとわかるよう、型を指定する必要がある

    int a;           //int型の変数a
    int* pa = &a;    //int型のポインタ(intの変数アドレス)
    cin >> a;
    cout << "変数aの値" << a << endl;
    cout << "変数aのアドレス" << &a << endl;
    //間接参照「*」間接参照子を使う
    //アドレスから、アドレスに何が入ってるか確認
    //今回のaはアドレス(&a)が入ってるので
    //そのアドレス値を取得することができる
    cout << "*paの値は" << *pa << endl;
    //間接参照を用いて、アドレスの中身を変更
    //aの値を変更してないが、
    //ポインタからaの値を変更出来てしまう
    *pa = 0;
    cout << "aの値は" << a << endl;

}