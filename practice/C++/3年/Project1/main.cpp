#include <iostream>
#include <vector>
#include "TRC.h"
using namespace std;


// ���6
class Player
{
	int32_t offensive;
public:
	int32_t defense;

	Player(int i1, int i2)
	{
		offensive = i1;
		defense = i2;
	}

	void Attack()
	{
		cout << offensive << "�_���[�W�^�����I" << endl;
	}

	void SetOffensive(int32_t a) 
	{
		offensive += a;
	}
};

struct  float3
{
	float x;
	float y;
	float z;
};
void Init(float3& pos)
{
	pos.x = 0.0f;
	pos.y = 0.0f;
	pos.z = 0.0f;
}
void Sort(vector<int>& vec)
{
	int n = vec.size();
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j) {
			if (vec[j] > vec[j + 1])
			{
				swap(vec[j], vec[j + 1]);
			}
		}
	}
}

int main()
{
	// ���1
	cout << "���1" << endl << "3�NA�g�Q�[�������w��" << endl << "27�� ��l��" << endl;
	
	// ���2
	int num = 100;
	cout << "���2" << endl << num << endl;

	// ���3
	int* plNum;
	plNum = &num;
	*plNum += 100;
	cout << "���3" << endl << *plNum << endl;

	// ���4
	float3 pos{};
	pos.x += 10;
	pos.y -= 3.5;
	cout << "���4" << endl << pos.x << "," << pos.y << "," << pos.z << endl;

	// ���5
	Init(pos);
	cout << "���5" << endl << pos.x << "," << pos.y << "," << pos.z << endl;

	// ���6
	cout << "���6" << endl;
	Player pl(100,100);
	pl.Attack();
	pl.SetOffensive(pl.defense);
	pl.Attack();

	// ���7
	vector<int> numbers;
	cout << "���7" << endl;
	cout << "���l�����Ă�������" << endl;
	for (int i = 0; i < 10; i++)
	{
		int value;
		cin >> value;
		numbers.push_back(value);
	}
	cout << "���͂��ꂽ���l��\��" << endl;
	int size = sizeof(numbers) / sizeof(numbers[0]);
	for (int i = 0; i < size; i++)
	{
		cout << numbers[i] << endl;
	}

	// ���8
	Sort(numbers);
	cout << "���8" << endl << "���͂��ꂽ���l�𐮗�" << endl;
	for (const auto& num : numbers)
	{
		cout << num << endl;
	}

	// ���9
	int limit;
	cout << "���9" << endl << "�������͂��Ă�������" << endl;
	cin >> limit;

	int sum = 0;
	for (int i = 1; i <= limit; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}
	cout << "3��������5�Ŋ���؂�鐳�̐����̑��a��" << sum << endl;

	// ���10
	int max1, max2;
	cout << "2�̐��̐�������͂��Ă�������" << endl;
	cin >> max1 >> max2;

	int min = (max1 < max2) ? max1 : max2;
	int gcd = 1;

	for (int i = min; i > 0; --i)
	{
		if (max1 % i == 0 && max2 % i == 0) 
		{
			gcd = i; 
			break;
		}
	}

	cout << "�ő����: " << gcd << endl;
	
	int min1, min2;
	cout << "2�̐��̐�������͂��Ă�������" << endl;
	cin >> min1 >> min2;

	int lcm = 1; 
	int max = (min1 > min2) ? min1 : min2;

	while (true) {
		if (lcm % min1 == 0 && lcm % min2 == 0) {
			break;
		}
		lcm++;
	}

	cout << "�ŏ����{��: " << lcm << endl;

	// ���EX
	// ABACABCBDA�EDACABAABBC�ECABDABABCA �̗l�ɁAA40% �EB30% �EC20% �ED10% �̕��z��10������std::string��Ԃ��@�\���������N���X���쐬����B

	// �N���X��TRC.cpp�Œ�`����ATRC.h��include���ė��p����

	// �N���X�� TRC
	// �����o�֐�  get(void) �w��̕��z��10��������string��Ԃ��B�Ăяo����閈�ɈقȂ�z�u�ɂȂ�B

	//	�g�p��
	TRC obj;
	cout << "���EX" << endl;
	cout << obj.get() << endl;
	cout << obj.get() << obj.get() << endl;

	return 0;
}
