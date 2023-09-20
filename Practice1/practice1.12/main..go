package main

import "fmt"

func main() {
	var x int
	var count int
	fmt.Scan(&x)
	if x >= 0 {
		for i := 0; x != 1; i++ {
			if x%2 == 0 {
				x = x / 2
				count++
			} else {
				x = 3*x + 1
				count++
			}
		}
	}
	fmt.Println(count)
}
