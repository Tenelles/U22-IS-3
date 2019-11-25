#pragma once
#include <iostream>

#include <vector>

using namespace std;

class SpigotFinder
{
public:
	SpigotFinder(int size);

	void printPi() const;
	int getOperationsCount() const;

private:
	void computePi();
	void computeAnotherDigit();

	vector<short int> _pi;
	vector<int> _remains;
	int _transferNumber;
	int _operationsCounter;
	int _size;
};
