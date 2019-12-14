// Sukharev Kirill, NPI-01-18, 21:49 24.11.2019

#include <iostream>
#include "SpigotFinder.h"

using namespace std;

int main()
{
	int size;
	do {
		cout << "Enter number of signs PI: ";
		cin >> size;	
	} while (size < 0);
	SpigotFinder pi(size);
	pi.printPi();
	return 0;
}
