#if false
#include <iostream>
#include <string>
using namespace std;
class Kakeibo 
{
protected:
	int zankin;
public:
	Kakeibo();
	void Shunyu(int x);
	void Shishutu(int x);
	void Disp_zankin();
};

Kakeibo::Kakeibo() :zankin(0) {}

void Kakeibo::Shunyu(int x) 
{
	zankin += x;
}

void Kakeibo::Shishutu(int x)
{
	zankin -= x;
}

void Kakeibo::Disp_zankin()
{
	cout << "残金" << zankin << "円" << endl;
}
int Menu()
{
	string ret;
	cout << "1 : 収入 2 : 支出 3 : 残金表示 0 : 終了 ---";
	getline(cin, ret);
	// 文字列の 1,2,3だとかの文字を数値(int)に変換
	return (ret[0] - '0');
}

int main()
{
	Kakeibo MyKakeibo;
	int ans; string buf; bool loopend = false;
	cout << "猫でもわかる家計簿---" << "\n\n";
	while (true)
	{
		switch (Menu())
		{
		case 0:
			loopend = true;
			break;
		case 1:
			cout << "収入金額 = "; getline(cin, buf);
			// atoi関数
			// 文字を整数に変換する
			// string::c_str関数
			// 文字列へのポインタを返却する
			MyKakeibo.Shunyu(atoi(buf.c_str()));
			break;
		case 2:
			cout << "支出金額 = "; getline(cin, buf);
			MyKakeibo.Shishutu(atoi(buf.c_str()));
			break;
		case 3:
			MyKakeibo.Disp_zankin();
			break;
		default:cout << "入力が不正\n";
			break;
		}
		if (loopend)break;
	}
}
#endif