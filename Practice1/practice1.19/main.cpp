#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	std::vector<std::string> string;
	while (true)
	{
		std::string temp;
		std::cin >> temp;
		if (temp == "end") break;
		string.push_back(temp);
	}

	sort(string.begin(), string.end());
	std::string temp = "";

	for (int i = 0; i < string.size() - 1; i++)
	{
		if (string[i] == string[i + 1] && string[i] != temp)
		{
			std::cout << string[i] << ' ';
			temp = string[i];
		}
	}
}
