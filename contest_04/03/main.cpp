#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

bool comp(std::map<int, std::string> a, std::map<int, std::string> b)
{
    if (std::stoi(a[5]) == std::stoi(b[5]))
    {
        return a[3] < b[3];
    }

    return std::stoi(a[5]) < std::stoi(b[5]);
}

// Функция преобразования строки в словарь
std::map<int, std::string> parseLine(std::string line)
{
    int key = 0; // Создаем переменную для ключа (индекса) элемента в словаре

    bool inQuites = true; // Переменная для определения нахождения в кавычках
    bool escapeQuote = false; // Переменная для определения экранирования кавычек

    std::string buffer = ""; // Буферная переменная для хранения значения элемента
    std::map<int, std::string> output; // Создаем пустой словарь (ключ-значение)

    for (auto character : line)
    {
        if (character == ',')
        {
            if (inQuites or escapeQuote) // Если находимся в кавычках, и не экранированная запятая
            {
                output[key] = buffer; // Записываем значение элемента в словарь
                buffer = ""; // Очищаем буфер
                key += 1; // Увеличиваем ключ (индекс) на 1 для следующего элемента
            }
            else
            {
                buffer += character;
            }
        }
        else if (character == '\"' and inQuites) // Если символ - кавычка, и мы находимся в кавычках
        {
            inQuites = false; // Выходим из кавычек
        }
        // Если символ - кавычка, и предыдущий символ был экранированной кавычкой
        else if (character == '\"' and escapeQuote)
        {
            buffer += "\"";
            escapeQuote = false;
        }
        else if (character == '\"')  // Если символ - кавычка
        {
            escapeQuote = true;
        }
        else 
        {
            buffer += character;
        }
    }

    return output;
}

int main() 
{
    std::ifstream file("train.csv");

    std::string line;
    std::vector<std::map<int, std::string>> data;

    int age;
    int pcclass;

    std::cin >> pcclass;
    std::cin >> age;

    // Пропускаем первую строку, так как она содержит заголовки столбцов
    getline(file, line, '\r');

    // Парсим каждую строку файла и добавляем подходящие записи в вектор
    while (not file.eof()) 
    {
        getline(file, line, '\r');
        std::map<int, std::string> buf_map = parseLine(line);

        // Пропускаем записи, в которых отсутствуют значения полей
        if (buf_map[4] == "" or buf_map[2] == "" or buf_map[5] == "") 
        {
            continue;
        }

        // Добавляем запись, если поле пола - "female", класс пассажира соответствует вводу 
        // и возраст больше введенного значения
        if (buf_map[4] == "female" and pcclass == std::stoi(buf_map[2]) and std::stoi(buf_map[5]) > age) 
        {
            data.push_back(buf_map);
        }
    }

    file.close();
    std::sort(data.begin(), data.end(), comp);

    for (auto element : data) 
    {
        std::cout << element[3] << '\n';
    }
}
