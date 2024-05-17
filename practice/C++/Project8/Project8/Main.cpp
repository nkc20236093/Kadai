#include <iostream>
using namespace std;

// project8
// ŠÖ”‚ÌƒI[ƒo[ƒ[ƒh‚Ì—ûK
// ŠÖ”–¼FArea
// –ß‚è’lFÀ”Œ^
// ˆø”–¼F©—Riˆø”‚ÌŒ^‚ÍÀ”Œ^j
// ‹@”\F‰~‚Ì–ÊÏA’·•ûŒ`‚Ì–ÊÏA‘äŒ`‚Ì–ÊÏ
// ‚ğ‹‚ß‚é
// ƒI[ƒo[ƒ[ƒh‚ğ—p‚¢‚ÄAAreaŠÖ”‚ğ3‚Âì¬
// ‚µA‹@”\‚ğÀ‘•‚·‚é‚±‚Æ
// ŠÖ”éŒ¾AƒfƒtƒHƒ‹ƒgˆø”‚È‚Ç‚ğg‚¤‚Æ‚È‚¨—Ç‚¢

// Às—á
// ‰~‚Ì”¼Œa‚ğ“ü—Í>ZZ
// ”¼ŒaZZ‚Ì‰~‚Ì–ÊÏ‚ÍZZ‚Å‚·
//
// ’·•ûŒ`‚Ì•A‚‚³‚ğ“ü—Í>ZZAZZ
// •ZZA‚‚³ZZ‚Ì’·•ûŒ`‚Ì–ÊÏ‚ÍZZ‚Å‚·
//
// ‘äŒ`‚Ì’ê•ÓA‚‚³‚ğ“ü—Í>ZZ
// ’ê•ÓZZA‚‚³››‚Ì‘äŒ`‚Ì–ÊÏ‚ÍZZ‚Å‚·

const double PI = 3.14;
float Area(float h, float w);
float Area(float r, float p = PI);
float Area(float t, float b, float h);

int main()
{
	float h1, w, r, t, b, h2, chou, en, dai;
	cout << "‰~‚Ì”¼Œa‚ğ“ü—Í-->";
	cin >> r;
	en = Area(r);
	cout << "‰~‚Ì–ÊÏ‚Í" << en << "‚Å‚·\n";

	cout << "’·•ûŒ`‚Ì•A‚‚³‚ğ“ü—Í‚ğ“ü—Í-->";
	cin >> h1, cin >> w;
	chou = Area(h1, w);
	cout << "’·•ûŒ`‚Ì–ÊÏ‚Í" << chou << "‚Å‚·\n";

	cout << "‘äŒ`‚Ìã•ÓA‰º•ÓA‚‚³‚ğ“ü—Í‚ğ“ü—Í-->";
	cin >> t, cin >> b, cin >> h2;
	dai = Area(t, b, h2);
	cout << "’·•ûŒ`‚Ì–ÊÏ‚Í" << dai << "‚Å‚·\n";
}

// ’·•ûŒ`
float Area(float h, float w)
{
	return static_cast<float>(h * w);
}
// ‰~
float Area(float r, double p) 
{
	return static_cast<float>(r * r * p);
}
// ‘äŒ`
float Area(float t, float b, float h)
{
	return static_cast<float>((t + b) * h / 2);
}
