#include <iostream>
using namespace std;

int main()
{
	// –â‘è1
	cout << "3”NA‘gƒQ[ƒ€‘‡Šw‰È" << endl << "27”Ô ‘ê‰l‘¾" << endl;
	// –â‘è2
	int num = 100;
	cout << num << endl;
	// –â‘è3
	int* plNum;
	plNum = &num;
	*plNum += 100;
	cout << *plNum << endl;
	// –â‘è4
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

	// –â‘è5

	return 0;
}
void Init(float a)
{
	a = 0;
}