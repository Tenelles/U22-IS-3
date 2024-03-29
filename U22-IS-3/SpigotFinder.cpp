#include "SpigotFinder.h"

SpigotFinder::SpigotFinder(int size)
{
	_size = size;
	_remainsSize = _size * 10 / 3;
	_remains.resize(_remainsSize, 2);
	_transferNumber = 0;

	computePi();

	_pi.pop_back(); // Removing "excess" digit
}

void SpigotFinder::printPi() const
{
	for (size_t i = 0; i < _size; i++) {
		if (i == 1)
			cout << '.';
		cout << _pi[i];
	}
	cout << endl;

}

int SpigotFinder::getOperationsCount() const
{
	return _operationsCounter;
}

void SpigotFinder::computePi()
{
	for (size_t i = 0; i <= _size; i++)
	{
		computeAnotherDigit();
	}
}

void SpigotFinder::computeAnotherDigit()
{
	for (size_t i = _remainsSize - 1; i > 0; --i) {
		int sum = _remains[i] * 10 + _transferNumber;
		int denominator = 2 * i + 1;
		_transferNumber = sum / denominator * i;
		_remains[i] = sum % denominator;
		_operationsCounter += 7;
	}
	int sum = _remains[0] * 10 + _transferNumber;
	_transferNumber = 0;
	_remains[0] = sum % 10;
	_pi.push_back(sum / 10);
	for (size_t i = _pi.size() - 1; _pi[i] >= 10; --i)
	{
		++_pi[i - 1];
		_pi[i] %= 10;
		_operationsCounter += 2;
	}

}
