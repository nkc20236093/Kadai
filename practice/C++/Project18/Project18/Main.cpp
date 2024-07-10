#include <iostream>
using namespace std;

#if false
// �t�����h�֐��A�t�����h�N���X�ɂ���

class  A
{
	int x;
public:
	A() :x(0) {}
	A(int n) :x(n) {}
	void Show()
	{
		cout << "x = " << x << endl;
	};
	// �t�����h�֐�
	// �����o�֐��ł͂Ȃ�
	friend void FShow(A a);
};

class B :public A
{
	int x;
public:
	B() :x(1000) {}
	void Show()
	{
		cout << "x = " << x << endl;
	};
};
// �t�����h�֐��̎���
// ����J�����o�ɃA�N�Z�X�ł���
void FShow(A a)
{
	cout << "x = " << a.x << endl;
};

// �O���錾(���g�͂��Ƃŏ������)
class Dog;
class Cat;

class Cat
{
	string voice;
public:
	Cat() : voice("�ɂ�[") {}
	friend void GetVoice(Cat tama, Dog pochi);
};
class Dog
{
	string voice;
public:
	Dog() :voice("��������") {}
	friend void GetVoice(Cat tama, Dog pochi);
};
// �t�����h�֐��̎���
void GetVoice(Cat tama, Dog pochi)
{
	cout << "�L��" << tama.voice << endl;
	cout << "����" << pochi.voice << endl;
};

#endif

class A2
{
	int x;
public:
	A2() :x(10) {}
	friend class B2;
};
class B2
{
public:
	void Func(A2 a) 
	{
		// A��B���t�����h�N���X�Ƃ��Ă���̂�
		// B��A�̔���J���ɃA�N�Z�X�ł���
		a.x = 0;
	};
};
class C :public B2
{
public:
	// �e������public��func�ɂ̓A�N�Z�X�ł���̂�
	// ���ʓI��A�̒l��ύX�ł���
	void Func2(A2 a)
	{
		// a.x = 0;	// �F�B����Ȃ��̂ŕύX�ł��Ȃ�
		Func(a);	// �e�͗F�B�Ȃ�ŁA�e�̗�
	};
};
int main()
{
#if false
	A Obj1(10), Obj2;
	Obj1.Show();
	FShow(Obj1);
	Obj2.Show();
	FShow(Obj2);

	B b;
	// B��x��\��
	b.Show();
	// A�̃t�����h�֐������s
	FShow(b);

	Cat a;
	Dog b;
	// �t�����h�֐��Ăяo��
	GetVoice(a, b);


#endif

}