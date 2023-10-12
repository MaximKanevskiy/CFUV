#include <iostream>
#include <map>

int main()
{
	int sequenceSize;
	int maximumRepetitions = 0;
	std::cin >> sequenceSize;

	std::map<std::string, int> words;

	for (int i = 0; i < sequenceSize; i++)
	{
		std::string buffer;
		std::cin >> buffer;
		words[buffer]++;
		
		if (maximumRepetitions < words[buffer]) 
		{
			maximumRepetitions = words[buffer];
		}
	}

	for (const auto& [key, value] : words)
	{
		if (value == maximumRepetitions) 
		{
			std::cout << key << ' ';
		}
	}
}
