#include <iostream>
#include <stdio.h>

using namespace std;

void Celect();
void main()
{
	int ent;
	cout << "---���ȏЉ�v���O�����J�n---\n�� �G���^�[�L�[�������Ɛi�݂܂�\n";
	while ((ent = cin.get()) == '\n')
	{
		Celect();
	}
}
void Celect()
{
	int x;
	cout << "���������ȏЉ��I�����Ă�������\n\n";
	cout << "1. �D���ȃQ�[�� : 2. �D���Ȗ{: 3. �D���ȉf��\n\n";
	cin >> x;
	if (x == 1)
	{
		cout << "ghostwireTOKYO�ł��ˁB\n���l�ɂȂ������������Ԃ��a���v�f����܂�ȃQ�[���ł�\n\n";
	}
	else if (x == 2)
	{
		cout << "�ߖ`�ł���\n�����ېV�Ɠ��̌��t�V�тƐl�̐S�������Ȃ��̂ɓG��薡�����E���q�[���[�Ƃ��Ď�l�����\��Ă܂�\n\n";
	}
	else if (x == 3)
	{
		cout << "����ς胏���s�[�X�ł���\n�Ō�Ɍ����̂�Stampede�ł�\n\n";
	}
	Celect();
}

