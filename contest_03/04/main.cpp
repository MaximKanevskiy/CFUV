#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
    int size1, size2;
    std::cin >> size1;
    std::vector<std::string> words1(size1);

    for (int i = 0; i < size1; i++) 
    {
        std::cin >> words1[i];
    }

    std::cin >> size2;
    std::vector<std::string> words2(size2);

    for (int i = 0; i < size2; i++) 
    {
        std::cin >> words2[i];
    }

    sort(words1.begin(), words1.end());
    sort(words2.begin(), words2.end());

    std::vector<std::string> general_words;

    set_intersection(words1.begin(), words1.end(), words2.begin(), words2.end(), back_inserter(general_words));

    for (int i = 1; i < size(general_words); i++)
    {
        if (general_words[i] == general_words[i - 1])
        {
            general_words.erase(general_words.begin() + i);
        }
    }

    sort(general_words.begin(), general_words.end());

    if (general_words.size() == 0) {
        std::cout << -1 << std::endl;
    }
    else 
    {
        for (std::string word : general_words) 
        {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
}
