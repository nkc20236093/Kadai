#include <iostream>
using namespace std;

int main()
{
	// ���1
	cout << "3�NA�g�Q�[�������w��" << endl << "27�� ��l��" << endl;
	// ���2
	int num = 100;
	cout << num << endl;
	// ���3
	int* plNum;
	plNum = &num;
	*plNum += 100;
	cout << *plNum << endl;
	// ���4
	struct  float3
	{
		float x;
		float y;
		float z;
	};
	float3 pos{};
	pos.x += 10;
	pos.y -= 3.5;
	cout << pos.x << "," << pos.y << "," << pos.z << endl;

	// ���5

	return 0;
}
void Init(float a)
{
	a = 0;
}