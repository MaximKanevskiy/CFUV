#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double a, b;
	cin >> a;
	cin >> b;
	if (a > 0 && b > 0) 
	{
		cout << sqrt(pow(a, 2) + pow(b, 2)) << endl;
	}
}
