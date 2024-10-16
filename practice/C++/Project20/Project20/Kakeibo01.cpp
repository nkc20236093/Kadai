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
	cout << "Žc‹à" << zankin << "‰~" << endl;
}
int Menu()
{
	string ret;
	cout << "1 : Žû“ü 2 : Žxo 3 : Žc‹à•\Ž¦ 0 : I—¹ ---";
	getline(cin, ret);
	// •¶Žš—ñ‚Ì 1,2,3‚¾‚Æ‚©‚Ì•¶Žš‚ð”’l(int)‚É•ÏŠ·
	return (ret[0] - '0');
}

#if false
int main()
{
	Kakeibo MyKakeibo;
	int ans; string buf; bool loopend = false;
	cout << "”L‚Å‚à‚í‚©‚é‰ÆŒv•ë---" << "\n\n";
	while (true)
	{
		switch (Menu())
		{
		case 0:
			loopend = true;
			break;
		case 1:
			cout << "Žû“ü‹àŠz = "; getline(cin, buf);
			// atoiŠÖ”
			// •¶Žš‚ð®”‚É•ÏŠ·‚·‚é
			// string::c_strŠÖ”
			// •¶Žš—ñ‚Ö‚Ìƒ|ƒCƒ“ƒ^‚ð•Ô‹p‚·‚é
			MyKakeibo.Shunyu(atoi(buf.c_str()));
			break;
		case 2:
			cout << "Žxo‹àŠz = "; getline(cin, buf);
			MyKakeibo.Shishutu(atoi(buf.c_str()));
			break;
		case 3:
			MyKakeibo.Disp_zankin();
			break;
		default:cout << "“ü—Í‚ª•s³\n";
			break;
		}
		if (loopend)break;
	}
}
#endif