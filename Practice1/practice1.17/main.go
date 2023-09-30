package main

import "fmt"

func main() {
    var n, l, p, w, max_l, max_p int
    fmt.Scan(&n)
    var array [] int

    for i := 0; i < n; i++ {
        var f int
        fmt.Scan(&f)
        array = append(array, f)
    }

    l = 0
    p = n - 1
    max_l = array[l]
    max_p = array[p]

    for {
        if max_l >= max_p {
            w = w + max_p - array[p]
            p = p - 1

            if max_p > array[p] {
               max_p = max_p
            } else {
               max_p = array[p]
            }
        } else {
            w = w + max_l - array[l]
            l++

            if max_l > array[l] {
                max_l = max_l
            } else {
                max_l = array[l]
            }
        }

        if l >= p {
            break
        }
    }
    
    fmt.Println(w)
}
