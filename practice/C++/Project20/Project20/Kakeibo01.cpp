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
	cout << "�c��" << zankin << "�~" << endl;
}
int Menu()
{
	string ret;
	cout << "1 : ���� 2 : �x�o 3 : �c���\�� 0 : �I�� ---";
	getline(cin, ret);
	// ������� 1,2,3���Ƃ��̕����𐔒l(int)�ɕϊ�
	return (ret[0] - '0');
}

#if false
int main()
{
	Kakeibo MyKakeibo;
	int ans; string buf; bool loopend = false;
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
}
#endif