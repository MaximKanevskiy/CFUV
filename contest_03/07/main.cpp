#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int main() 
{
    std::ifstream file("data.txt");
    
    std::string target;
    std::cin >> target;

    std::map<std::string, int> wordsCount;
    std::string word;

    while (file >> word) 
    {
        if (word == target)
        {
            std::string nextWord;
            file >> nextWord;
            
            if (nextWord != "stopword")
            {
                wordsCount[nextWord]++;
            }
        }
    }

    std::vector<std::pair<std::string, int>> sortedWords;

    for (const auto& pair : wordsCount)
    {
        sortedWords.emplace_back(pair.first, pair.second);
    }

    std::sort(sortedWords.begin(), sortedWords.end(), [](const auto& a, const auto& b) {
        return a.second != b.second ? a.second > b.second : a.first < b.first;
        });

    if (sortedWords.empty())
    {
        std::cout << "-" << std::endl;
    }
    else
    {
        for (int i = 0; i < 3 && i < sortedWords.size(); ++i)
        {
            std::cout << sortedWords[i].first << " ";
        }

        std::cout << std::endl;
    }
}
