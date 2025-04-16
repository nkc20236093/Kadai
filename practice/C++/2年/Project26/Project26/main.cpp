#include <iostream>
#include <typeinfo>
#include <vector>
#include <algorithm>
using namespace std;

// C++11�ȍ~�̋@�\

//auto�ɂ��^���_

int main()
{
#if false
	int i = 10;
	auto d = 3.14;
	cout << "i�̌^" << typeid(i).name() << endl;
	cout << "d�̌^" << typeid(d).name() << endl;

	vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i * 10);
	}

	// vector�̃C�e���[�^��auto�Ō^���_
	// vector<int>::iterator�Ƃ������͒�������̂�
	for (auto a = v.begin(); a != v.end(); ++i)
	{
		cout << *a << " ";
	}
	cout << endl;

	// �͈̓x�[�X��for��
	int array[10];
	int sum = 0;
	for (int i = 0; i < 10; ++i)
	{
		array[i] = 2 * i + 1; // ���ݒ�
	}

	// for(�f�[�^�^�F�͈�)
	// �͈͂�R���e�i�͔͈͂Ƃ��Ďg�p�\
	for (auto i : array)
	{
		cout << i << " ";
		sum += i;
	}
	cout << " �̍��v��" << sum << endl;

	// �����_��
	// �L�q���@��
	//[�L���v�`��](�p�����[�^)->�߂�l{�֐��{��}
	
	// 2���Ԃ�
	// auto f = �����_�֐��A�Ƃ����悤�ɐ錾
	auto f = [](int x) {return x + x; };
	cout << f(10) << endl; // �����_�֐��Ăяo��

	// 2�̃p�����[�^����Z
	// [->double]�Ŗ߂�l�̌^���w�肵�Ă���B
	auto ff = [](double p, double q)->double
	{
		return p * q;
	};
	cout << ff(2.5, 0.5) << endl;

	// ������A�����ĕԂ�
	auto s = [](string s) {return s.append("�ł�"); };
	cout << s("C++") << endl;
#endif
	vector<int> v2;
	vector<int>::iterator s2, e;
	s2 = v2.begin();
	e = v2.end();

	// for_each�Ƃ����A���S���Y���֐�
	// for_each(iterator,iterator,function)
	for_each(s2, e, [](int x)
	{
		if (x % 2 == 0)
		{
			cout << "x�͋���\n";
		}
		else
		{
			cout << "x�͊�ł�\n";
		}
	});
	auto f = [](int x)
	{
		if (x % 2 == 0)
		{
			cout << "x�͋���\n";
		}
		else
		{
			cout << "x�͊�ł�\n";
		}
	};

	for_each(s2, e, f);
	// �]���̏������͂���
	for_each(s2, e, Function);
}

void Function(int x)
{
	if (x % 2 == 0)
	{
		cout << "x�͋���\n";
	}
	else
	{
		cout << "x�͊�ł�\n";
	}
}