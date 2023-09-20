#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (abs(b - a) < abs(c - a))
	{
		cout << "B" << " " << abs(b - a) << endl;
	}
	else
	{
		cout << "C" << " " << abs(c - a) << endl;
	}
}
