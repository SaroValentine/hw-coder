package main

import (
    "fmt"
)

func main() {
    var num float32
     for {
        n, _ := fmt.Scan(&num)
        if n == 0 {
            break
        } else {
            fmt.Printf("%d\n", int(num + 0.5))
        }
    }
}