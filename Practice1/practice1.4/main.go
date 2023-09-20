package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b float64
	fmt.Scan(&a, &b)
	if (math.Abs(a) <= 10000) && (math.Abs(b) <= 10000) {
		fmt.Printf("%.2f", a*b)
	}
}
