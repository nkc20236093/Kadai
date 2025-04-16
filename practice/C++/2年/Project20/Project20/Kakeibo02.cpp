#include <iostream>
#include <string>
#include <iomanip> // マニュピレータ
#include <fstream> // ファイル入出力
using namespace std;
class Kakeibo 
{
protected:
	int zankin;
public:
	Kakeibo() { zankin = GetZankin(); }
	~Kakeibo() { SetZankin(); }
	void Shunyu(int x) { zankin += x; }
	void Shishutu(int x) { zankin -= x; }
	void Disp_zankin()
	{
		cout << "残金 : " << zankin << "円\n";
	}
	int GetZankin();
	void SetZankin();
};

int Kakeibo::GetZankin()
{
	string zan;
	ifstream kakei_file("kakei.tex"); //ファイルを開く
	if (!kakei_file)
	{
		return 0; //エラー終了
	}
	kakei_file >> zan; //残金設定
	return (atoi(zan.c_str())); //int型で返却
}

void Kakeibo::SetZankin()
{
	ofstream kakei_file("kakei.txt", ios_base::trunc);
	kakei_file << zankin;
}

int Menu()
{
	string ret;
	cout << "1 : 収入 2 : 支出 3 : 残金表示 4 : 項目別表示 0 : 終了 ---";
	getline(cin, ret);
	// 文字列の 1,2,3だとかの文字を数値(int)に変換
	return (ret[0] - '0');
}

class KakeiEX :public Kakeibo
{
	int kyuyo;
	int sonota_in;
	int shokuhi;
	int kosaihi;
	int sonota_out;
public:
	KakeiEX();
	~KakeiEX();
	void Sishutsu_menu();
	void Shunyu_menu();
	void Disp_koumoku();
};
KakeiEX::KakeiEX()
{
	ifstream kakei_file("kakeibex_ext");
	if (!kakei_file)
	{
		kyuyo = 0; sonota_in = 0; shokuhi = 0;
		kosaihi = 0; sonota_out = 0;
	}
	else
	{
		kakei_file >> kyuyo >> sonota_in >> shokuhi >> kosaihi >> sonota_out;
	}
}

KakeiEX::~KakeiEX()
{
	ofstream kakei_file("kakeiex.txt", ios_base::trunc);
	kakei_file << kyuyo << endl;
	kakei_file << sonota_in << endl;
	kakei_file << shokuhi << endl;
	kakei_file << kosaihi << endl;
	kakei_file << sonota_out << endl;
}

void KakeiEX::Shunyu_menu()
{
	string buf; int money;
	while (1)
	{
		cout << "(a) 給与 (b) その他収入 --- "; getline(cin, buf);
		if (buf != "a" && buf != "b")
		{
			cout << "不正な入力!\n"; continue;
		}
		switch (buf[0])
		{
		case 'a':
			cout << "給与収入(円) --- "; getline(cin, buf);
			money = atoi(buf.c_str()); kyuyo += money;
			Shunyu(money); break;
		case 'b':
			cout << "その他の収入(円) --- "; getline(cin, buf);
			money = atoi(buf.c_str()); sonota_in += money;
			Shunyu(money); break;
		default:
			cout << "Error!\n"; break;
		}
		break;
	}
}

void KakeiEX::Sishutsu_menu()
{
	string buf; int money;
	while (1)
	{
		cout << "(a) 食費 (b) 交際費 (c) その他支出 --- "; getline(cin, buf);
		if (buf != "a" && buf != "b" && buf != "c")
		{
			cout << "不正な入力!\n"; continue;
		}
		switch (buf[0])
		{
		case 'a':
			cout << "食費(円) --- "; getline(cin, buf);
			money = atoi(buf.c_str()); shokuhi += money;
			Shishutu(money); break;
		case 'b':
			cout << "交際費(円) --- "; getline(cin, buf);
			money = atoi(buf.c_str()); kosaihi += money;
			Shishutu(money); break;
		case 'c':
			cout << "その他の支出(円) --- "; getline(cin, buf);
			money = atoi(buf.c_str()); sonota_out += money;
			Shishutu(money); break;
		default:
			cout << "Error!\n"; break;
		}
		break;
	}
};

void KakeiEX::Disp_koumoku()
{
	cout << "収入 **************\n";
	cout << setw(15) << left << "給与収入";
	cout << setw(8) << right << kyuyo << endl;
	cout << setw(15) << left << "その他の収入";
	cout << setw(8) << right << sonota_in << endl;
	cout << "--------------------\n";
	cout << setw(15) << left << "収入合計";
	cout << setw(8) << right << kyuyo + sonota_in << endl;
	cout << "支出 **************\n";
	cout << setw(15) << left << "食費";
	cout << setw(8) << right << shokuhi << endl;
	cout << setw(15) << left << "交際費";
	cout << setw(8) << right << kosaihi << endl;
	cout << setw(15) << left << "その他の支出";
	cout << setw(8) << right << sonota_out << endl;
	cout << "--------------------\n";
	cout << setw(15) << left << "支出合計";
	cout << setw(8) << right << shokuhi + sonota_out * kosaihi << endl;
}

int main()
{
	KakeiEX MyKakeiboex;
	bool loopend = false;
	cout << "猫でもわかる家計簿---" << "\n\n";
	while (true)
	{
		switch (Menu())
		{
		case 0:
			loopend = true;
			break;
		case 1:
			MyKakeiboex.Shunyu_menu();
			break;
		case 2:
			MyKakeiboex.Sishutsu_menu();
			break;
		case 3:
			MyKakeiboex.Disp_zankin();
			break;
		case 4:
			MyKakeiboex.Disp_koumoku();
			break;
		default:cout << "入力が不正\n";
			break;
		}
		if (loopend)break;
	}
#if false
	Kakeibo MyKakeibo;
	int ans; string buf; 	bool loopend = false;
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
#endif
}
