package main

import "fmt"

func main() {
    var islandLength, left, right, waterBlocks, max_left, max_right int
    fmt.Scan(&islandLength)
    var heights []int

    for i := 0; i < islandLength; i++ {
        var height int
        fmt.Scan(&height)
        heights = append(heights, height)
    }

    left = 0
    right = islandLength - 1
    max_left = heights[left]
    max_right = heights[right]

    for {
        if max_left >= max_right {
            waterBlocks = waterBlocks + max_right - heights[right]
            right = right - 1

            if max_right > heights[right] {
                max_right = max_right
            } else {
                max_right = heights[right]
            }
        } else {
            waterBlocks = waterBlocks + max_left - heights[left]
            left++
            if max_left > heights[left] {
                max_left = max_left
            } else {
                max_left = heights[left]
            }
        }

        if left >= right {
            break
        }
    }

    fmt.Println(waterBlocks)
}
