// Person.h
#pragma once
#include <string>

class Person
{
	// �A�N�Z�X�w��q���Ȃ��ꍇ��private�ɂȂ�
	std::string name;
	int age;
	char sex;
public:
	// �֐��錾
	// �N���X���Ɠ������O�̊֐����R���X�g���N�^�ƌĂ�
	// �R���X�g���N�^�ɂ͖߂�l�͂Ȃ�
	Person(const std::string&, int, char);
	int Show();
};
