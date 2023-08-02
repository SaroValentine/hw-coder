package main

import (
	"fmt"
	"strings"
)

func main() {
	var a string
	var b string
	for {
		n, _ := fmt.Scan(&a, &b)
		if n == 0 {
			break
		} else {
			var res int
			length := len(a)
			for i:=0; i <length; i++ {
				for j:=i; j <= length; j++ {
					str := a[i:j]
					if strings.Contains(b, str) && len(str) > res {
						res = len(str)
					}
				}
			}
			fmt.Println(res)
		}
	}
}
