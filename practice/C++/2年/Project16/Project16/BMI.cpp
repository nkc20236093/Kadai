#include <iostream>
using namespace std;
#include "BMI.h"

// ŠÖ”’è‹`
int BMI::SetData()
{
	cout << "g’·(m)---";
	cin >> bl;
	cout << "‘Ìd(kg)---";
	cin >> bw;
	bmi = bw / (bl * bl);
	return 0;
}
int BMI::ShowBMI()
{
	cout << "BMI = " << bmi << endl;
	return 0;
}