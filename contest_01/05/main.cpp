#include <iostream>
#include <math.h>
using namespace std;

int main() 
{
  	double mass, height;
	  cin >> mass >> height;
	  double bmi = mass / pow(height, 2);
	  cout << bmi << endl;
}
