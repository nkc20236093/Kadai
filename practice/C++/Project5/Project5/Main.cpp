#include <iostream>
using namespace std;

int mani()
{
	//�L���X�g���Z�q(p86)

	// 10/4�̌��ʂ�2.5���������̌^�̌v�Z�Ȃ̂�
	// �������͏����A2�ɂȂ�
	float a = 10;
	int b = 4;
	cout << "a / b = " << (a / b) << "\n";
	// �^�𖳗����ϊ�����
	// �ϊ��������^��()���g���Ă������
	// ���̌^�͕ϊ������
	// float�^��a��int�^��b�̌v�Z�ł�
	// �v�Z���ʂ�float�ɈÖٓI�ɕϊ������
	cout << "a / b = " << (float)(a / b) << "\n";

	// ���x�ȕ��ϊ�
	double d;
	d = static_cast<double>(a) / b;
	cout << "d = " << d << "\n";

	// const_cast<�^>(�ϐ�)
	const int ca = 10; //const�͒萔
	// ca = 10;
	// ����ca��const?cast�Ŗ������ύX�ł��邪�قڎg��Ȃ��̂Ŗ��O�����o���Ă���

	// reinterprest_cast<�^>(�ϐ�)
	// �|�C���^��ʂ̌^�ɕϊ�����̂Ɏg���B
	// �g�p����ɂ͊댯�𔺂�
	// void* ptr;
	// Player* pl;
	// pl = reinterpret_cast<Player>(ptr);

	// �r�b�g���Z(p71)

	// unsigned�c���̒l�̂�
	// signed�c���̒l�E���̒l�̗�������
	// ���i�g���Ă�int�͎���signed int
	// short�������^(int����������l��������)
	// int��32bit(���ɂ���ĕω�)
	// short��16bit(���ɂ���ĕω�)
	// 0000 0000 0000 0000
	unsigned short sa, sb;
	sa = 1;	// 0001
	sb = 3; // 0011

	// �r�b�g��
	cout << "sa & sb = " << (sa & sb) << endl;
	// �r�b�g�a
	cout << "sa | sb = " << (sa | sb) << endl;
	// �r�b�g��
	cout << "sa ^ sb = " << (sa ^ sb) << endl;
	// �ے�(0��1�̔��])
	cout << "~sa = " << (unsigned short)(~sa);

	// �V�t�g���Z
	short sx = 12;

	// 0000 0110
	// 0000 1100 //���V�t�g1����Ɓ��A�E�V�t�g1����Ɓ�
	// 0001 1000
	// 0011 0000 // ���V�t�g2
	cout << sx << "������0�V�t�g = " << (sx << 0) << endl;
	cout << sx << "������1�V�t�g = " << (sx << 1) << endl;
	cout << sx << "������2�V�t�g = " << (sx << 2) << endl;
	
	//����擾�t���O
	enum  WepaonGet
	{
		Sword	 = (1 << 0), // 0000 0001
		Gun		 = (1 << 1), // 0000 0010
		Hanmmer  = (1 << 2), // 0000 0100
		Lance	 = (1 << 3), // 0000 1000
		Arrow	 = (1 << 4), // 0001 0000
		Axe		 = (1 << 5), // 0010 0000
		Knife	 = (1 << 6), // 0100 0000
		Clab	 = (1 << 7), // 1000 0000
	};
	unsigned short wFlag = 0;
	wFlag |= WepaonGet::Sword; //Sword���擾����
	wFlag |= WepaonGet::Gun;   //Gun���擾����

	if (wFlag & WepaonGet::Sword)
	{
		cout << "Sword���擾���Ă���\n";
	}
	if (wFlag & WepaonGet::Gun)
	{
		cout << "Gun���擾���Ă���\n";
	}
	if (wFlag & WepaonGet::Axe)
	{
		cout << "Axe���擾���Ă���\n";
	}
	return b;
}