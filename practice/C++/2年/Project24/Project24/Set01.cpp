#include <iostream>
#include <set>
#include <string>
using namespace std;

// set�R���e�i�ɂ̓L�[�������i�[����

int main()
{
	set<int> s;
	set<char> c;
	set<int>::iterator ps;
	set<char>::iterator pc;

	// set�R���e�i��insert�Ŋi�[
	s.insert(10); s.insert(5); s.insert(8);
	s.insert(12); s.insert(8);
	for (ps = s.begin(); ps != s.end(); ++ps)
	{
		cout << *ps << ", ";
	}
	cout << endl;

	c.insert('x'); c.insert('d'); c.insert('a');
	c.insert('c'); c.insert('b');
	for (pc = c.begin(); pc != c.end(); ++pc)
	{
		cout << *pc << ", ";
	}
	cout << endl;

};