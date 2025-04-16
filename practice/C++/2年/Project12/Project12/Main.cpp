#include<iostream>
using namespace std;

int main() {
    //配列は配列名+[要素数]で定義
    int a[4] = { 1, 2, 3, 4 };
    //要素数を指定せずに定義もできる
    //その場合初期化が必要
    int b[] = { 5,6,7,8 };
    //int c[]; //初期化子がなくてエラー

    // sizeof(配列名) / sizeof(その配列の要素)
    int size = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < size; ++i) {
        //配列のアドレスを表示
        cout << "&a[" << i << "] = " << &a[i] << endl;
    }
    cout << endl;
    // aという配列名のアドレスを表示
    // &とかも書いてないが、アドレスが表示される
    // 配列名を使うと配列の先頭アドレスが表示される
    // aと&aは同じアドレスを表示される
    cout << "a = " << a << endl;
    // int型のポイントpにa配列の先頭アドレスを代入
    int* p = a;
    for (int i = 0; i < size; i++)
    {
        // ポインタを使ってa配列の中身を確認
        cout << "(p + " << i << ") = " << *(p + i) << endl;
        // 配列aのポインタのpは配列のようにも使える
        cout << "(p[" << i << "] = " << p[i] << endl;
    }

}