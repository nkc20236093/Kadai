#include<iostream>//���o�͊֘A�w�b�_�ǂݍ���
//����w�b�_�́u""�v�ł������ăC���N���[�h
#include "Test.h"


//std���O��Ԃ����悤�ustd:�v���ȗ��ł���
using namespace std;

//�v���g�^�C�v�錾(�֐��錾)
void Update();

void main() //���C���֐�
{
    Update();

    TestUpdate();
}

//Update�֐�(���g������)
void Upddate()
{
    std::cout << "���o�͊֘A\n"; //�����o��
    //   using �����Ă���cout << "���o�͊֘A\n";  //�����o��
    int x;		// ����
    float f;	// ����
    char c;		// �����^(1����)
    string s;	// ������^
    cout << "x�����\n"; cin >> x;
    cout << "x�̒l��" << x << "�ł�\n";
    cout << "f�����\n"; cin >> f;
    cout << "f�̒l��" << f << "�ł�\n";
    cout << "c�����\n"; cin >> c;
    cout << "c�̒l��" << c << "�ł�\n";
    cout << "s�����\n"; cin >> s;
    cout << "s�̒l��" << s << "�ł�\n";
}
