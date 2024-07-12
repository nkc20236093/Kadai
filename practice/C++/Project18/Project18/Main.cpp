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

// ���d�p��
class B3_1
{
	int x;
public:
	B3_1() :x(10) {}
	void ShowB3_1()
	{
		cout << "x = " << x << endl;
	};
};
class B3_2
{
	int y;
public:
	B3_2() :y(20) {};
	void ShowB3_2()
	{
		cout << "y = " << y << endl;
	};
};
// B3_1��B3_2�𑽏d�p��
class C2 :public B3_1, public B3_2
{
	int d;
public:
	C2() :d(30) {}
	void ShowC2()
	{
		cout << "d = " << d << endl;
	};
};

// �Ђ��`�p��
class B4_1
{
protected:
	int x;
public:
	void ShowX()
	{
		cout << "x = " << x << endl;
	}
	B4_1() :x(10)
	{
		cout << "B4_1�̃R���X�g���N�^\n";
		cout << "x��10�ɐݒ�\n";
	};
};
class B4_2 :virtual public B4_1
{
public:
	B4_2()
	{
		cout << "B4_2�̃R���X�g���N�^\n";
		x = 100;
		cout << "x��100�ɐݒ�\n";
	};
};
class B4_3 :virtual public B4_1
{
public:
	B4_3()
	{
		cout << "B4_3�̃R���X�g���N�^\n";
		x = 200;
		cout << "x��200�ɐݒ�\n";
	};
};
// B4_2�AB4_3�Ђ��`�p������C3
class C3 :public B4_2, public B4_3
{
public:
	void Show()
	{
		cout << "�N���XC3��Show�֐���x��\��:" << x << endl;
	};
};
#endif
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

	// ���̍쐬
	C2 der;
	der.ShowB3_1();	// B3_1�̃����o�֐�
	der.ShowB3_2();	// B3_2�̃����o�֐�
	der.ShowC2();	// C2�̃����o�֐�

	// �e�ɓ������O�̊֐������鎞��
	// �X�R�[�v�������Z�q���g��
	der.B3_1::ShowB3_1();
	der.B3_2::ShowB3_2();

	C3 c3;
	c3.Show();
#endif
}