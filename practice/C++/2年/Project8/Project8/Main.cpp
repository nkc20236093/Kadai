#include <iostream>
using namespace std;

// project8
// �֐��̃I�[�o�[���[�h�̗��K
// �֐����FArea
// �߂�l�F�����^
// �������F���R�i�����̌^�͎����^�j
// �@�\�F�~�̖ʐρA�����`�̖ʐρA��`�̖ʐ�
// �����߂�
// �I�[�o�[���[�h��p���āAArea�֐���3�쐬
// ���A�@�\���������邱��
// �֐��錾�A�f�t�H���g�����Ȃǂ��g���ƂȂ��ǂ�

// ���s��
// �~�̔��a�����>�Z�Z
// ���a�Z�Z�̉~�̖ʐς́Z�Z�ł�
//
// �����`�̕��A���������>�Z�Z�A�Z�Z
// ���Z�Z�A�����Z�Z�̒����`�̖ʐς́Z�Z�ł�
//
// ��`�̒�ӁA���������>�Z�Z
// ��ӁZ�Z�A���������̑�`�̖ʐς́Z�Z�ł�

const double PI = 3.14;
float Area(float h, float w);
float Area(float r, float p = PI);
float Area(float t, float b, float h);

int main()
{
	float h1, w, r, t, b, h2, chou, en, dai;
	cout << "�~�̔��a�����-->";
	cin >> r;
	en = Area(r);
	cout << "�~�̖ʐς�" << en << "�ł�\n";

	cout << "�����`�̕��A��������͂����-->";
	cin >> h1, cin >> w;
	chou = Area(h1, w);
	cout << "�����`�̖ʐς�" << chou << "�ł�\n";

	cout << "��`�̏�ӁA���ӁA��������͂����-->";
	cin >> t, cin >> b, cin >> h2;
	dai = Area(t, b, h2);
	cout << "�����`�̖ʐς�" << dai << "�ł�\n";
}

// �����`
float Area(float h, float w)
{
	return static_cast<float>(h * w);
}
// �~
float Area(float r, double p) 
{
	return static_cast<float>(r * r * p);
}
// ��`
float Area(float t, float b, float h)
{
	return static_cast<float>((t + b) * h / 2);
}
