package main

import (
	"fmt"
	"math"
)

func main() {
	var humanBreathing float64 = 0.5
	var fiftyYearOak float64 = 20
	var twentyFiveYearPoplar float64 = 32
	var daysInYear float64 = 365
	var breathingPerYear = humanBreathing * daysInYear
	fmt.Println(breathingPerYear, math.Ceil(breathingPerYear/twentyFiveYearPoplar), math.Ceil(breathingPerYear/fiftyYearOak))
}
