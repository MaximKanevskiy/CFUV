package main

import "fmt"

func offset(i int) {
	if i < 10 {
		fmt.Print("   ")
	}
	if i > 9 && i < 100 {
		fmt.Print("  ")
	} else if i > 99 {
		fmt.Print(" ")
	}
}

func main() {
	var row int
	var column int

	fmt.Scan(&row, &column)

	fmt.Print("    |")
	for i := 1; i <= column; i++ {
		offset(i)
		fmt.Print(i)
	}
	fmt.Print("\n   --")
	for i := 1; i <= column; i++ {
		fmt.Print("----")
	}
	fmt.Print("\n")

	for i := 1; i <= row; i++ {
		offset(i)
		fmt.Print(i, "|")
		for j := 1; j <= column; j++ {
			offset(i * j)
			fmt.Print(i * j)
		}
		fmt.Print("\n")
	}
}
