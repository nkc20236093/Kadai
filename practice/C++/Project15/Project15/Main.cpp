#include <iostream>
using namespace std;

int main()
{
	// �ϐ��̓X�^�b�N�������ɔz�u�����
	// �X�^�b�N�������̓���
	// �������̃A�N�Z�X�͑������e�ʂ͏�����
	// �ϐ��̓X�R�[�v�O�ŏ�����
	int a;

	// �L�[�v������
	// ��e�ʂŃA�N�Z�X���x��
	// ��x�������玩���ŏ����܂ŏ����Ȃ�
	int num;
	cout << "�m�ۂ���v�f�������\n";
	cin >> num;
	// new���Z�q��p���āA�q�[�v�̈悩�烁�����m��
	// new���Z�q�͊m�ۂ����A�h���X�𓾂�
	int* ptr = new int[num];
	for (int i = 0; i < num; ++i)
	{
		cout << i << "�Ԗڂ̃f�[�^:";
		cin >> ptr[i];
	}
	for (int i = 0; i < num; ++i)
	{
		cout << i << "�Ԗڂ̃f�[�^��:" << ptr[i] << endl;
	}
	// delte���Z�q�ŏ���
	// ����͔z��Ȃ̂ŁAdelete[]���Z�q���g��
	delete[] ptr;
}