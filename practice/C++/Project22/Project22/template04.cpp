#include <iostream>
#include <string>
#include <typeinfo> // typeid���g���p
using namespace std;

template<typename T> 
class MyClass
{
	T a;
public:
	MyClass(T x) :a(x) {}
	//void Show(T b) {}
	//{
	//	cout << "\""<< a  << "\" + " 
	//		<< "\""<< b  << "\" = " 
	//		<< a + b << endl;
	//}
	void GetDataType();
};

// �N���X�̊O�ŃN���X�̊֐���`
template<typename T> void MyClass<T>::GetDataType()
{
	cout << "���݂̌^��" << typeid(T).name() << "�Œl�� : " << a << endl;
}

int main()
{
	MyClass<int>mc1(1);
	MyClass<const char*>mc2("�L�ł��킩��");
	MyClass<string> mc3("C++�v���O���~���O");
	mc1.GetDataType();
	mc2.GetDataType();
	mc3.GetDataType();

	//MyClass<int> myint(2);
	//MyClass<double>mydouble(1.25);
	//MyClass<char>mychar('c');
	//myint.Show(3);
	//mydouble.Show(2.75);
	//mychar.Show('c');
}