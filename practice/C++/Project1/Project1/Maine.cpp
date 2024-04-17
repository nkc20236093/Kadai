// iostreamというヘッダを読み込み
// iostream(入出力ストリーム)
// input output streamの略
#include <iostream>

//C++ではmain関数から実行される
void main()
{
	// HelloWorldと出力する処理
	// std::cout(文字を出力する処理)
	// coutは「<<」挿入子で渡された
	// 文字列を出力する
	// 「\n」は特殊文字で改行を意味する
	std::cout << "HelloWorld\n";

	// 文字の入力について
	std::cout << "文字を入力してください\n";
	int a; // 整数型変数a
	//cinは「>>」抽出子で入力された値を変数に代入する
	std::cin >> a;
	// aを表示
	std::cout << "aの値は" << a << "です\n";

	// キーの入力待ち
	system("pause");
}

// C++で書いたソースコードはコンパイルすることにより
// 機械語に変換される。それらをリンク(結合)して
// 実行ファイルを作成する。それら一連の流れをビルドという