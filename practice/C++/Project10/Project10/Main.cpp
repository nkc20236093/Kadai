#include <iostream>
using namespace std;

// �֐�(�l�n��)
void func1(int a) { a = 100; }

// �|�C���^
void func2(int* pa) 
{
	*pa = 100;
}

int main()
{
	int x = 0;
	func1(x);	// func1�Ăяo��
	cout << "x�̒l��" << x << "�ł�\n";

	func2(&x);	// func2�Ăяo��
	cout << "x�̒l��" << x << "�ł�\n";
}