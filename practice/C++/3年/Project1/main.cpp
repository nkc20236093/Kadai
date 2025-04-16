#include <iostream>
#include <vector>
using namespace std;


// 問題6
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
		cout << "問題6" << endl << offensive << "ダメージ与えた！" << endl;
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
	// 問題1
	cout << "問題1" << endl << "3年A組ゲーム総合学科" << endl << "27番 滝瑛太" << endl;
	
	// 問題2
	int num = 100;
	cout << "問題2" << endl << num << endl;

	// 問題3
	int* plNum;
	plNum = &num;
	*plNum += 100;
	cout << "問題3" << endl << *plNum << endl;

	// 問題4
	float3 pos{};
	pos.x += 10;
	pos.y -= 3.5;
	cout << "問題4" << endl << pos.x << "," << pos.y << "," << pos.z << endl;

	// 問題5
	Init(pos);
	cout << "問題5" << endl << pos.x << "," << pos.y << "," << pos.z << endl;

	// 問題6
	Player pl(100,100);
	pl.Attack();
	pl.SetOffensive(pl.defense);
	pl.Attack();

	// 問題7
	vector<int> numbers;
	cout << "問題7" << endl;
	cout << "数値を入れてください" << endl;
	for (int i = 0; i < 10; i++)
	{
		int value;
		cin >> value;
		numbers.push_back(value);
	}
	cout << "入力された数値を表示" << endl;
	int size = sizeof(numbers) / sizeof(numbers[0]);
	for (int i = 0; i < size; i++)
	{
		cout << numbers[i] << endl;
	}

	// 問題8
	Sort(numbers);
	cout << "問題8" << endl << "入力された数値を整列" << endl;
	for (const auto& num : numbers)
	{
		cout << num << endl;
	}

	// 問題9
	int limit;
	cout << "問題9" << endl << "上限を入力してください" << endl;
	cin >> limit;

	int sum = 0;
	for (int i = 1; i <= limit; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}
	cout << "3もしくは5で割り切れる正の整数の総和は" << sum << endl;

	// 問題10
	int max1, max2;
	cout << "2つの正の整数を入力してください" << endl;
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

	cout << "最大公約数: " << gcd << endl;
	
	int min1, min2;
	std::cout << "2つの正の整数を入力してください" << endl;
	std::cin >> min1 >> min2;

	int lcm = 1; 
	int max = (min1 > min2) ? min1 : min2;

	while (true) {
		if (lcm % min1 == 0 && lcm % min2 == 0) {
			break;
		}
		lcm++;
	}

	std::cout << "最小公倍数: " << lcm << std::endl;
	return 0;
}
