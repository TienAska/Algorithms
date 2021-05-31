#include "Flips.h"

#include <random>
#include <iostream>

using namespace std;

void Flips::MainTest(const vector<string>& args)
{
	int T = stoi(args[0]);
	Counter heads("heads");
	Counter tails("tails");
	random_device rd;
	mt19937_64 generator(rd());
	bernoulli_distribution distribution(0.5);
	for (int i = 0; i < T; i++)
	{
		if ((distribution(generator))) heads.Increment();
		else tails.Increment();
	}
	cout << heads << endl;
	cout << tails << endl;
	int d = heads.Tally() - tails.Tally();
	cout << "delta: " << abs(d) << endl;
}
