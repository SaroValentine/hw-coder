package main

import (
	"fmt"
	"sort"
)

func main() {
	var a, b int
	for {
		_, err := fmt.Scan(&a, &b)
		if err != nil {
			break
		}

		arr := make([]int, a)
		for i := 0; i < a; i++ {
			fmt.Scan(&arr[i])
		}
		sort.Ints(arr)

		for i := 0; i < b; i++ {
			fmt.Printf("%d ", arr[i])
		}
	}
}
