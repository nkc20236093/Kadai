#include <iostream>
#include <string>
#include <typeinfo> // typeidを使う用
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

// クラスの外でクラスの関数定義
template<typename T> void MyClass<T>::GetDataType()
{
	cout << "現在の型は" << typeid(T).name() << "で値は : " << a << endl;
}

int main()
{
	MyClass<int>mc1(1);
	MyClass<const char*>mc2("猫でもわかる");
	MyClass<string> mc3("C++プログラミング");
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