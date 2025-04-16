#include <iostream>
#include <vector>
// アルゴリズム関数
#include <algorithm> 
using namespace std;

// Show関数
void Show(vector<char> v)
{
	for (vector<char>::iterator pv = v.begin(); pv != v.end(); ++pv)
	{
		cout << *pv << endl;
	}
};

//int main()
//{
//	vector<char> v;
//	v.push_back('d'); v.push_back('b');
//	v.push_back('c'); v.push_back('a');
//	Show(v);
//
//	// アルゴリズム関数sort
//	// データを昇順に並べ替える
//	sort(v.begin(), v.end());
//	Show(v);
//}