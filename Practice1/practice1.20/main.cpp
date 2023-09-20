#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	unsigned long long a, b;
	cin >> a >> b;
	string c = to_string(a);
	string d = to_string(b);


	sort(c.begin(), c.end());
	sort(d.begin(), d.end());
	if (c == d)
	{
		cout << "YES" << endl;
	}
	else 
	{
		cout << "NO" << endl;
	}
}
