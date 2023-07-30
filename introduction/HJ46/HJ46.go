package main

import (
    "fmt"
)

func main() {
    var str string 
    var a int
    for {
        n, _ := fmt.Scan(&str, &a)
        if n==0 {
            break
        }
        for i:=0;i< a && i <= len(str);i++{
            fmt.Printf("%c",str[i])
        }
    }
}