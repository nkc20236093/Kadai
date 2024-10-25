#include <iostream>
#include <vector>
using namespace std;

// �W���e���v���[�g���C�u����
// STL(Standard Template Library)
// �R���e�i�A�����q�A�A���S���Y������

int main()
{
#if false
	// Vector�N���X(STL���p�ӂ���R���e�i��1��)
	// �z��̂悤�ȘA���ŃI�u�W�F�N�g��ۊǂł���N���X
	// �z��͂��炩���ߗv�f����ݒ肵�Ȃ��Ƃ����Ȃ���Vector�͊�ł��ǉ��ł���

	vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i * 2); // vector�̖����Ƀf�[�^��ǉ�
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << "v[" << i << "]" << v[i] << endl;
	}

	// �����q
	// �C�e���[�^(iterator)
	// �R���e�i���̗v�f�ɏ��ԂɃA�N�Z�X������@��񋟂���
	vector<int> v;			  // �R���e�i
	vector<int>::iterator pv; // �����q
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(20 - i);
	}
	pv = v.begin();
	// �����q������(�̎�)���w���ĂȂ��Ȃ烋�[�v
	while (pv != v.end())
	{
		cout << *pv << ", "; // �����q���w���v�f��\��
		++pv;				 // ���̗v�f��
	}
	cout << endl;

#endif
	vector<char> v(4); // 4�̗v�f�����Ǝw��
	vector<char>::iterator pv;
	// 4���̗v�f�𔽕��q�Őݒ�
	pv = v.begin();
	*pv = 'x'; // �Ԑډ��Z�q���g���āAiterator���w���ꏊ�ɗv�f����
	++pv;
	*pv = 'y';
	++pv; *pv = 'z';
	++pv; *pv = 'a';
	// �����q���g�킸�ɗv�f��\��
	for (vector<char>::size_type i = 0; i < v.size(); ++i)
	{
		cout << v[i] << ", ";
	}
	cout << endl;
	// �����q���g�����\��
	for (pv = v.begin(); pv != v.end(); ++pv)
	{
		cout << *pv << ", ";
	}
	cout << endl;
}

