#include<iostream>
using namespace std;

int main() {
    //�z��͔z��+[�v�f��]�Œ�`
    int a[4] = { 1, 2, 3, 4 };
    //�v�f�����w�肹���ɒ�`���ł���
    //���̏ꍇ���������K�v
    int b[] = { 5,6,7,8 };
    //int c[]; //�������q���Ȃ��ăG���[

    // sizeof(�z��) / sizeof(���̔z��̗v�f)
    int size = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < size; ++i) {
        //�z��̃A�h���X��\��
        cout << "&a[" << i << "] = " << &a[i] << endl;
    }
    cout << endl;
    // a�Ƃ����z�񖼂̃A�h���X��\��
    // &�Ƃ��������ĂȂ����A�A�h���X���\�������
    // �z�񖼂��g���Ɣz��̐擪�A�h���X���\�������
    // a��&a�͓����A�h���X��\�������
    cout << "a = " << a << endl;
    // int�^�̃|�C���gp��a�z��̐擪�A�h���X����
    int* p = a;
    for (int i = 0; i < size; i++)
    {
        // �|�C���^���g����a�z��̒��g���m�F
        cout << "(p + " << i << ") = " << *(p + i) << endl;
        // �z��a�̃|�C���^��p�͔z��̂悤�ɂ��g����
        cout << "(p[" << i << "] = " << p[i] << endl;
    }

}