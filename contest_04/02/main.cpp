#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

int main()
{
	std::ifstream file("data.json");

	json jsonFile;
	file >> jsonFile;

	int user_id;
	std::cin >> user_id;

    int completed_tasks = 0;

    for (const auto& project : jsonFile)
    {
        for (const auto& task : project["tasks"]) 
        {
            if (task["user_id"] == user_id && task["completed"] == true) 
            {
                completed_tasks++;
            }
        }
    }

    std::cout << completed_tasks;

    return 0;
}
