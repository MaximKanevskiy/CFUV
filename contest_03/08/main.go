package main

import "fmt"

func findNumberWithoutPair(numbers []int) int {
    result := 0
    
    for _, number := range numbers {
    	  // ^= операция исключающего ИЛИ
        // Помогает встретить число, которое повторяется
        // нечётное количество раз.
        result ^= number
    }
    
    return result
}

func main() {
    var size int
    fmt.Scan(&size)

    numbers := make([]int, size)
    
    for i := 0; i < size; i++ {
        fmt.Scan(&numbers[i])
    }

    fmt.Println(findNumberWithoutPair(numbers))
}
