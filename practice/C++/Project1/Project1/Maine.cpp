// iostream�Ƃ����w�b�_��ǂݍ���
// iostream(���o�̓X�g���[��)
// input output stream�̗�
#include <iostream>

//C++�ł�main�֐�������s�����
void main()
{
	// HelloWorld�Əo�͂��鏈��
	// std::cout(�������o�͂��鏈��)
	// cout�́u<<�v�}���q�œn���ꂽ
	// ��������o�͂���
	// �u\n�v�͓��ꕶ���ŉ��s���Ӗ�����
	std::cout << "HelloWorld\n";

	// �����̓��͂ɂ���
	std::cout << "��������͂��Ă�������\n";
	int a; // �����^�ϐ�a
	//cin�́u>>�v���o�q�œ��͂��ꂽ�l��ϐ��ɑ������
	std::cin >> a;
	// a��\��
	std::cout << "a�̒l��" << a << "�ł�\n";

	// �L�[�̓��͑҂�
	system("pause");
}

// C++�ŏ������\�[�X�R�[�h�̓R���p�C�����邱�Ƃɂ��
// �@�B��ɕϊ������B�����������N(����)����
// ���s�t�@�C�����쐬����B������A�̗�����r���h�Ƃ���