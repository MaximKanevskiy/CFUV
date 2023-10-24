package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
)

type Task struct {
	UserID    int    `json:"user_id"`
	ID        int    `json:"id"`
	Title     string `json:"title"`
	Completed bool   `json:"completed"`
}

type Project struct {
	ProjectID int    `json:"project_id"`
	Tasks     []Task `json:"tasks"`
}

func main() {
	// Чтение данных из файла
	file, err := ioutil.ReadFile("data.json")
	if err != nil {
		fmt.Println("Ошибка чтения файла:", err)
		return
	}

	var projects []Project

	// Декодирование данных JSON
	err = json.Unmarshal(file, &projects)
	if err != nil {
		fmt.Print(err)
		return
	}

	// Ввод идентификатора пользователя
	var userID int
	fmt.Scan(&userID)

	// Подсчет количества завершенных
	//задач для пользователя с указанным идентификатором
	completedTasks := 0
	for _, project := range projects {
		for _, task := range project.Tasks {
			if task.UserID == userID && task.Completed {
				completedTasks++
			}
		}
	}

	fmt.Print(completedTasks)
}
