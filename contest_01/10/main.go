package main

import "fmt"

func main() {
	var a, b, c string
	fmt.Scan(&a, &b, &c)
	if a == "Нет" {
		if b == "Нет" {
			if c == "Нет" {
				fmt.Println("Кот")
			} else {
				fmt.Println("Жираф")
			}
		} else {
			if c == "Нет" {
				fmt.Println("Курица")
			} else {
				fmt.Println("Страус")
			}
		}
	} else {
		if b == "Нет" {
			if c == "Нет" {
				fmt.Print("Дельфин")
			} else {
				fmt.Println("Плезиозавры")
			}
		} else {
			if c == "Нет" {
				fmt.Println("Пингвин")
			} else {
				fmt.Println("Утка")
			}
		}
	}
}
