#include "MyClass3.h"

// this�|�C���^�ɂ͌Ăяo�����I�u�W�F�N�g�ւ̃|�C���^���i�[����Ă���
// this�͏ȗ��\

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