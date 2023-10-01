#include <iostream>
using namespace std;

int main() 
{
	int number;
	cin >> number;

	int alphabeticCapacity = 26;
	int firstAsciiLetter = 65;
	string word = "";
	
	while (number > 0)
	{
		number--;
		word = char((number % alphabeticCapacity) + firstAsciiLetter) + word;
		number /= alphabeticCapacity;
	}

	cout << word;
}
