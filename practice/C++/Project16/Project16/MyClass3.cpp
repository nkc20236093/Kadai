#include "MyClass3.h"

// thisポインタには呼び出したオブジェクトへのポインタが格納されている
// thisは省略可能

int MyClass3::SetX(int n)
{
	this->x = n;
	return 0;
}
int MyClass3::ReadX(int* pn)
{
	*pn = this->x;
	return 0;
}