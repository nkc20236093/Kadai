#include <iostream>
using namespace std;

#if false

#endif
// ���Z�q�̃I�[�o�[���[�h
class Vector 
{
	double x, y;
public:
	void Set(double a, double b);
	void Read(double* a, double* b);
	double GetX() const { return x; }
	double GetY() const { return y; }
	// ���Z�q�̃I�[�o�[���[�h
	Vector operator +(const Vector& A);
	Vector operator -(const Vector& A);
	double operator *(const Vector& A);
	Vector operator *(double d);
};
void Vector::Set(double a, double b)
{
	x = a; y = b;
};
void Vector::Read(double* a, double* b)
{
	*a = x; *b = y;
};
// +���Z�q�̃I�[�o�[���[�h
Vector Vector::operator+(const Vector& A)
{
	Vector C;
	C.x = x + A.x;
	C.y = y + A.y;
	return C;
};
// +���Z�q�̃I�[�o�[���[�h
Vector Vector::operator-(const Vector& A)
{
	Vector C;
	C.x = x - A.x;
	C.y = y - A.y;
	return C;
};
// *���Z�q�̃I�[�o�[���[�h
double Vector::operator*(const Vector& A)
{
	return x * A.x + y * A.y;
};
// *���Z�q(double�̒l�Ə�Z)
Vector Vector::operator*(double d) 
{
	Vector V;
	V.x = x * d;
	V.y = y * d;
	return V;
};
// double * Vector�̊֐�(�����o�֐��ł͂Ȃ�)
Vector operator*(double a, const Vector& v)
{
	Vector z;
	z.Set(a * v.GetX(), a * v.GetY());
	return z;
};

int main()
{
#if false
	Vector v1, v2, v3;
	v1.Set(2, 8);
	v2.Set(2.5, 3.5);
	// �N���X���m�̑����Z
	v3 = v1 + v2;
	double a, b;
	v3.Read(&a, &b);
	cout << a << endl << b << endl;
#endif
	Vector v4, v5;
	v5.Set(2, 3);
	// Vector + double
	v4 = 2 * v5;
	cout << "v4 = " << v4.GetX() << "," << v4.GetY() << endl;
	// Vector * double
	v4 = v4 * 2.0;
	cout << "v4 = " << v4.GetX() << "," << v4.GetY() << endl;
}