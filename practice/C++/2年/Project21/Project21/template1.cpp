#include <iostream>
using namespace std;

// �e���v���[�g�֐�
template<typename T> void comp(T a, T b)
{
	if (a > b)
	{
		cout << a << "��" << b << "�����傫��\n";
	}
	else if (a < b)
	{
		cout << a << "��" << b << "����������\n";
	}
	else
	{
		cout << a << "��" << b << "�͓�����\n";
	}
}

// �����̌^���g�����e���v���[�g�֐�
template<typename A,typename B>
A func(A a, B b)
{
	cout << "a = " << a << endl;
	cout << "b = " << a << endl;
	cout << "�߂�l = " << a << endl;
	return a;
}

// �e���v���[�g�֐��̃I�[�o�[���[�h
template<typename T>
void func(T a)
{
	cout << a << endl;
}
template<typename T>
void func(T a, T b)
{
	cout << a << "," << b << endl;
}
template<typename T>
void func(T a, T b, T c)
{
	cout << a << "," << b << "," << c << endl;
}

int main()
{
	func(1.25);
	func(5, 6);
	func("���񂽂�", "1���ڂ�", "�J�������c");

#if false
	char c; int i;
	i = func(1, "abc");
	c = func('A', 12.5);

	comp(2, 3);
	comp(2.5, 0.5);
	comp('a', 'b');
	comp('s', 'S');
#endif
}