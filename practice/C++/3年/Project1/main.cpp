#include <iostream>
using namespace std;

int main()
{
	// βθ1
	cout << "3NAgQ[wΘ" << endl << "27Τ κlΎ" << endl;
	// βθ2
	int num = 100;
	cout << num << endl;
	// βθ3
	int* plNum;
	plNum = &num;
	*plNum += 100;
	cout << *plNum << endl;
	// βθ4
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

	// βθ5

	return 0;
}
void Init(float a)
{
	a = 0;
}