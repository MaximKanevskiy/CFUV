#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	float approximateValue = sqrt(12) * (1 - (1.0 / (3 * 3)) + (1.0 / (5 * 3 * 3)) - (1.0 / (7 * pow(3, 3))) + (1.0 / (9 * pow(3, 4))) - (1.0 / (11 * pow(3, 5))));
	cout << approximateValue << endl;
}
