#include <iostream>
#include <cstring> //������֘A�̋@�\
using namespace std;

int main()
{
	char str1[32];
	char str2[32];
	cout << "str1�����\n";
	cin.getline(str1, 32);
	cout << "str2�����\n";
	cin.getline(str2, 32);
	int cmp = strcmp(str1, str2); // �������r
	if (cmp < 0) 
	{
		cout << str1 << "��" << str2 << "�����O�ɂ���";
	}
	else if (cmp > 0)
	{
		cout << str1 << "��" << str2 << "�������ɂ���";
	}
	else
	{
		cout << str1 << "��" << str2 << "�͓���������";
	}
	cout << endl;
	
	rsize_t len; // ������̒��������߂�
	len = strlen(str1);
	cout << str1 << "�̒�����" << len << "�ł�\n";

	// ������̃R�s�[
	// strcpy�̓G���[���N���₷����肪����
	// strcp_s���g���悤�ɂȂ���
	// (�R�s�[����T�C�Y���w�肷��)
	strcpy_s(str1, 32, "aaa");
	cout << "strcpy���str1��" << str1 << "�ł�\n";

	// ������̘A��
	// strcat
	strcat_s(str1, 32, "�l");
	cout << "strcat���str1��" << str1 << "�ł�\n";

	// string�Ƃ����߂�����֗��Ȃ���
	string s1 = "aaa", s2 = "sama";
	s1 + s2;	// �A����+�ŏo����
	int size = s1.length();
	cout << size << endl;
	cout << s1[0] << endl;			// 1�����ڂ̕����ɃA�N�Z�X
	rsize_t index = s2.find("m");	// �����̏ꏊ������
	if (s1 == "aaa")
	{
		cout << "����!!";
	}
}