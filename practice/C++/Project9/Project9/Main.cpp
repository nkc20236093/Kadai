#include<iostream>
using namespace std;
int main()
{
    char c;
    int i;
    double d, e;
    //�ϐ��̓�������̂ǂ����ɔz�u�����
    //�z�u���ꂽ�ꏊ���A�h���X�Ƃ����A
    //���̃A�h���X��\������̂�
    //�u&�v�̃A�h���X���Z�q
    //&a �̂悤�ɕϐ��̑O�ɕt����
    //�����╶����̃A�h���X�\����
    //void*�^�ɃL���X�g�@��: (void*)&c
    cout << "�ϐ�c�̃A�h���X" << (void*)&c << "�ł�\n";
    cout << "�ϐ�i�̃A�h���X" << &i << "�ł�\n";
    cout << "�ϐ�d�̃A�h���X" << &d << "�ł�\n";
    cout << "�ϐ�e�̃A�h���X" << &e << "�ł�\n";

    //�ϐ��̃T�C�Y�i�o�C�g���j��\��
    //sizeof���g���ƁA�ϐ��̃T�C�Y���킩��
    cout << "char�^:" << sizeof(c) << endl;
    cout << "int�^:" << sizeof(i) << endl;
    cout << "float�^:" << sizeof(float) << endl;
    cout << "double�^:" << sizeof(d) << endl;

    //�|�C���^�Ƃ�
    //�A�h���X�����邽�߂̕ϐ��̂���
    //�u*�v�Ƃ����|�C���^���Z�q���g��
    //�� int�^��a�̃A�h���X������|�C���^�����
    //int a;
    //int *pa =&a;
    //int�^��a�̃A�h���X������|�C���^�����ꍇ
    //int�^�̃|�C���^���Ƃ킩��悤�A�^���w�肷��K�v������

    int a;           //int�^�̕ϐ�a
    int* pa = &a;    //int�^�̃|�C���^(int�̕ϐ��A�h���X)
    cin >> a;
    cout << "�ϐ�a�̒l" << a << endl;
    cout << "�ϐ�a�̃A�h���X" << &a << endl;
    //�ԐڎQ�Ɓu*�v�ԐڎQ�Ǝq���g��
    //�A�h���X����A�A�h���X�ɉ��������Ă邩�m�F
    //�����a�̓A�h���X(&a)�������Ă�̂�
    //���̃A�h���X�l���擾���邱�Ƃ��ł���
    cout << "*pa�̒l��" << *pa << endl;
    //�ԐڎQ�Ƃ�p���āA�A�h���X�̒��g��ύX
    //a�̒l��ύX���ĂȂ����A
    //�|�C���^����a�̒l��ύX�o���Ă��܂�
    *pa = 0;
    cout << "a�̒l��" << a << endl;

}