#include <iostream>
using namespace std;

// �萔
// �֐��O�ɐ錾�����̂ŁAMain.cpp�S���Ŏg����
const double per = 0.1;

// �֐��錾
// �֐��錾�Ńf�t�H���g����������
int zei(int, double = per);	// �ō��݉��i���v�Z����֐�

// �֐��̃I�[�o�[���[�h(���d��`)
// �������O�̊֐��́A
// �V�O�l�`��(�����̌��A�����̌^)���Ⴄ��
// �錾���邱�Ƃ��ł���
int zei(int x);

int main()
{
	int teika, total;
	cout << "�艿(�Ŕ���)-->";
	cin >> teika;
	// �f�t�H���g����������֐���
	// �֐��Ăяo���̍ĂɈ������ȗ��ł���
	// zei�͈���2�����A1�ŌĂяo���Ă���
	//total = zei(teika);
	cout << "�ō��݉��i" << total << "�ł�\n";
}

// �ō��݉��i���v�Z����֐�
// �f�t�H���g��������p�����֐�
// 
int zei(int x, double r)
{
	return static_cast<int>(x * (per + 1));
}

//����1�Ԃ�zei�֐�
int zei(int x)
{
	return static_cast<int>(x * (per + 1));
}