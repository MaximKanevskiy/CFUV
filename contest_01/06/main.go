package main

import "fmt"

func main() {
	var fiveThousand int = 0
	var oneThousand int = 0
	var fiveHundred int = 0
	var twoHundred int = 0
	var oneHundred int = 0
	var total int
	fmt.Scan(&total)

	if total >= 5000 {
		for fiveThousand = 0; total >= 5000; {
			total = total - 5000
			fiveThousand++
		}
	}
	if total >= 1000 {
		for oneThousand = 0; total >= 1000; {
			total = total - 1000
			oneThousand++
		}
	}
	if total >= 500 {
		for fiveHundred = 0; total >= 500; {
			total = total - 500
			fiveHundred++
		}
	}
	if total >= 200 {
		for twoHundred = 0; total >= 200; {
			total = total - 200
			twoHundred++
		}
	}
	if total >= 100 {
		for oneHundred = 0; total >= 100; {
			total = total - 100
			oneHundred++
		}
	}
	fmt.Print(fiveThousand, oneThousand, fiveHundred, twoHundred, oneHundred)

	var input string
	fmt.Scanf("%v", &input)
	fmt.Scanf(" ")
}
