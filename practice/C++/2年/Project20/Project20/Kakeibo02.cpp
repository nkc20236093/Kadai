#include <iostream>
#include <string>
#include <iomanip> // �}�j���s���[�^
#include <fstream> // �t�@�C�����o��
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
		cout << "�c�� : " << zankin << "�~\n";
	}
	int GetZankin();
	void SetZankin();
};

int Kakeibo::GetZankin()
{
	string zan;
	ifstream kakei_file("kakei.tex"); //�t�@�C�����J��
	if (!kakei_file)
	{
		return 0; //�G���[�I��
	}
	kakei_file >> zan; //�c���ݒ�
	return (atoi(zan.c_str())); //int�^�ŕԋp
}

void Kakeibo::SetZankin()
{
	ofstream kakei_file("kakei.txt", ios_base::trunc);
	kakei_file << zankin;
}

int Menu()
{
	string ret;
	cout << "1 : ���� 2 : �x�o 3 : �c���\�� 4 : ���ڕʕ\�� 0 : �I�� ---";
	getline(cin, ret);
	// ������� 1,2,3���Ƃ��̕����𐔒l(int)�ɕϊ�
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
		cout << "(a) ���^ (b) ���̑����� --- "; getline(cin, buf);
		if (buf != "a" && buf != "b")
		{
			cout << "�s���ȓ���!\n"; continue;
		}
		switch (buf[0])
		{
		case 'a':
			cout << "���^����(�~) --- "; getline(cin, buf);
			money = atoi(buf.c_str()); kyuyo += money;
			Shunyu(money); break;
		case 'b':
			cout << "���̑��̎���(�~) --- "; getline(cin, buf);
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
		cout << "(a) �H�� (b) ���۔� (c) ���̑��x�o --- "; getline(cin, buf);
		if (buf != "a" && buf != "b" && buf != "c")
		{
			cout << "�s���ȓ���!\n"; continue;
		}
		switch (buf[0])
		{
		case 'a':
			cout << "�H��(�~) --- "; getline(cin, buf);
			money = atoi(buf.c_str()); shokuhi += money;
			Shishutu(money); break;
		case 'b':
			cout << "���۔�(�~) --- "; getline(cin, buf);
			money = atoi(buf.c_str()); kosaihi += money;
			Shishutu(money); break;
		case 'c':
			cout << "���̑��̎x�o(�~) --- "; getline(cin, buf);
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
	cout << "���� **************\n";
	cout << setw(15) << left << "���^����";
	cout << setw(8) << right << kyuyo << endl;
	cout << setw(15) << left << "���̑��̎���";
	cout << setw(8) << right << sonota_in << endl;
	cout << "--------------------\n";
	cout << setw(15) << left << "�������v";
	cout << setw(8) << right << kyuyo + sonota_in << endl;
	cout << "�x�o **************\n";
	cout << setw(15) << left << "�H��";
	cout << setw(8) << right << shokuhi << endl;
	cout << setw(15) << left << "���۔�";
	cout << setw(8) << right << kosaihi << endl;
	cout << setw(15) << left << "���̑��̎x�o";
	cout << setw(8) << right << sonota_out << endl;
	cout << "--------------------\n";
	cout << setw(15) << left << "�x�o���v";
	cout << setw(8) << right << shokuhi + sonota_out * kosaihi << endl;
}

int main()
{
	KakeiEX MyKakeiboex;
	bool loopend = false;
	cout << "�L�ł��킩��ƌv��---" << "\n\n";
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
		default:cout << "���͂��s��\n";
			break;
		}
		if (loopend)break;
	}
#if false
	Kakeibo MyKakeibo;
	int ans; string buf; 	bool loopend = false;
	cout << "�L�ł��킩��ƌv��---" << "\n\n";
	while (true)
	{
		switch (Menu())
		{
		case 0:
			loopend = true;
			break;
		case 1:
			cout << "�������z = "; getline(cin, buf);
			// atoi�֐�
			// �����𐮐��ɕϊ�����
			// string::c_str�֐�
			// ������ւ̃|�C���^��ԋp����
			MyKakeibo.Shunyu(atoi(buf.c_str()));
			break;
		case 2:
			cout << "�x�o���z = "; getline(cin, buf);
			MyKakeibo.Shishutu(atoi(buf.c_str()));
			break;
		case 3:
			MyKakeibo.Disp_zankin();
			break;
		default:cout << "���͂��s��\n";
			break;
		}
		if (loopend)break;
	}
#endif
}
