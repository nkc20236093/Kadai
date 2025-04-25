#include <iostream>
#include <random>
#include "TRC.h"

string TRC::get()
{
	char chars[] = { 'A','B','C','D' };
	double probability[] = { 0.4,0.3,0.2,0.1 };

	discrete_distribution<> distribution(probability, probability + 4);
	random_device rd;
	mt19937 generator(rd());

	string random_string;

	for (int i = 0; i < 10; ++i) 
	{
		int index = distribution(generator);
		random_string += chars[index];
	}

	return random_string;
}