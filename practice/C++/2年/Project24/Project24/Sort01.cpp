#include <iostream>
#include <vector>
// �A���S���Y���֐�
#include <algorithm> 
using namespace std;

// Show�֐�
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
//	// �A���S���Y���֐�sort
//	// �f�[�^�������ɕ��בւ���
//	sort(v.begin(), v.end());
//	Show(v);
//}