package main

import (
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Структура для хранения данных о пассажире
type Person struct {
	Pcclass int
	Age     int
	Sex     string
	Name    string
}

// Слайс для сортировки объектов типа Person
type SortPerson []Person

// Функция, возвращающая длину слайса
func (sp SortPerson) Len() int {
	return len(sp)
}

// Функция для сравнения двух элементов слайса
func (sp SortPerson) Less(i, j int) bool {
	if sp[i].Age == sp[j].Age {
		return sp[i].Name < sp[j].Name
	}

	return sp[i].Age < sp[j].Age
}

// Функция для замены двух элементов слайса
func (sp SortPerson) Swap(i, j int) {
	sp[i], sp[j] = sp[j], sp[i]
}

// Функция splitCSV принимает строку CSV в качестве аргумента и возвращает объект Person.
func splitCSV(line string) Person {
	var key int = 0              // Переменная key используется для определения положения каждого поля в строке CSV
	var inQuotes bool = true     // Переменная для определения нахождения в кавычках
	var escapeQuote bool = false // Переменная для определения экранирования кавычек
	var buffer string = ""       // Пустой буффер
	var result Person

	// Итерируемся по каждому символу строки CSV
	for _, character := range line {
		if character == ',' { // Если символ - запятая, то это разделитель полей
			if inQuotes || escapeQuote { // Если мы находимся внутри кавычек или символ экранирован кавычками
				if key%12 == 2 { // Определяем, какое поле должно быть записано в структуру Person, и присваиваем значение из буфера
					if buffer == "" {
						result.Pcclass = -1
					} else {
						result.Pcclass, _ = strconv.Atoi(buffer)
					}
				} else if key%12 == 3 {
					result.Name = buffer
				} else if key%12 == 4 {
					result.Sex = buffer
				} else if key%112 == 5 {
					if buffer == "" {
						result.Age = -1
					} else {
						result.Age, _ = strconv.Atoi(buffer)
					}
				}
				buffer = "" // Очищаем буфер для следующего поля
				key += 1    // Переходим к следующему полю
			} else { // Если мы не внутри кавычек и символ не экранирован, то добавляем его в буфер
				buffer += ","
			}
		} else if character == '"' && inQuotes { // Если символ - кавычка и мы находимся внутри кавычек, то заканчиваем их
			inQuotes = false
		} else if character == '"' && escapeQuote { // Если символ - кавычка и она экранирована, то добавляем ее в буфер
			buffer = buffer + "\""
			escapeQuote = false
		} else if character == '"' { // Если символ - кавычка, то начинаем кавычки или указываем на экранирование кавычек
			escapeQuote = true
		} else {
			buffer += string(character)
		}
	}

	return result
}

func main() {
	// Считываем содержимое файла "train.csv" и сохраняем его в переменную fileContent
	fileBytes, _ := os.ReadFile("train.csv")
	fileContent := string(fileBytes)

	// Разделяем содержимое файла на отдельные строки по символу перевода строки '\r'
	lines := strings.Split(fileContent, "\r")

	// Объявляем переменные для хранения класса pcclass и возраста age, вводимые с клавиатуры пользователем
	var pcclass int
	var age int
	fmt.Scan(&pcclass, &age)

	// Объявляем срез names для хранения объектов типа Person
	var names []Person

	// Итерируемся по каждой строке в файле, начиная с первой строки (строка с индексом 1)
	for _, line := range lines[1:] {
		// Разбиваем каждую строку на поля типа Person, и присваиваем полученный объект record
		record := splitCSV(line)

		// Проверяем, является ли значение поля Pcclass равным -1, поле Sex пустым, значение поля Age равным -1 или поле Name пустым.
		// Если хотя бы одно из условий истинно, пропускаем текущую итерацию цикла.
		if record.Pcclass == -1 || record.Sex == "" || record.Age == -1 || record.Name == "" {
			continue
		}

		// Проверяем, является ли поле Sex равным "female", поле Pcclass равным значению переменной pcclass
		// и значение поля Age больше значения переменной age.
		// Если условие истинно, добавляем объект record в срез names.
		if record.Sex == "female" && record.Pcclass == pcclass && record.Age > age {
			names = append(names, record)
		}
	}

	// Сортируем срез names по полю Name в алфавитном порядке
	sort.Sort(SortPerson(names))

	for _, name := range names {
		fmt.Println(name.Name)
	}
}
