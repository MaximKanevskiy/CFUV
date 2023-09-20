package main

import "fmt"

func readInt(s string, x *int) {
	fmt.Print(s + ": ")
	var y int = 0
	fmt.Scan(&y)
	*x = y
}

func main() {
	var amount int = 0
	fmt.Scan(&amount)

	array := make([]float64, amount)
	temp := make([]float64, amount)

	for i := 0; i < amount; i++ {
		var element int = 0
		fmt.Scan(&element)
		array[i] = float64(element)
	}

	if amount >= 2 {
		for i := 1; i < amount-1; i++ {
			temp[i] = (array[i-1] + array[i] + array[i+1]) / 3
		}
	}

	temp[0] = array[0]
	temp[len(temp)-1] = array[len(array)-1]

	for i := 0; i < amount; i++ {
		var element float64 = temp[i]
		fmt.Print(element, "  ")
	}
}
