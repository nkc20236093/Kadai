// �I�u�W�F�N�g�w��
// C++�̓I�u�W�F�N�g�w���^�v���O����
// �N���X�A�p���A�J�v�Z�����A�|�����[�t�B�Y���Ȃ�
// �����������v�f���������

// �N���X�̂����炢
#include <iostream>
using namespace std;

// �N���X�̒�`
class Stdunt
{
	// �A�N�Z�X�w��q��ݒ�	
	// private�͔���J�Apublic�͌��J
public:
	int year = 0;			// �w�N
	string className;		// �N���X��
	int studentNo = 0;		// �o�Ȕԍ�
	//�����������J(������`���Ȃ���private)�ɂȂ�
private:
	string studentName;		// ����
public:
	void SetStudentName(string name)
	{
		studentName = name;
	}
	string GetStudentName()
	{
		return studentName;
	}
};

//�@���΂ɂ���
//�f�[�^�i�ϐ��j���܂Ƃ߂���^(c����)
//���͊֐������Ă�
//�A�N�Z�X�w��̓f�t�H���g��public
struct Teacher
{
	int year = 0;
	string className = "";
};
int main()
{
	cout << "�N���X�̂����炢\n";
	Stdunt s1;
	// ���J��(public)�ɒl��ݒ�
	s1.year = 2;
	s1.className = "�Q�[�������w��";
	s1.studentNo = 29;
	s1.SetStudentName("�� �l��");
	// �\��
	cout << "year = " << s1.year << "\n";
	cout << "className = " << s1.className << "\n";
	cout << "studentNo = " << s1.studentNo << "\n";
	cout << "studentName = " << s1.GetStudentName() << "\n";

	Teacher t1;
	t1.year = 2;
	t1.className = "�Q�[�������w��2�NA�g";

	cout << "TeacherYear = " << t1.year << "\n";
	cout << "className = " << t1.className << "\n";
}