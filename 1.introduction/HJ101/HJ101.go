package main

import (
	"fmt"
	"sort"
)

func main() {
	var a int
	for {
		_, err := fmt.Scan(&a)
		if err != nil {
			break
		}

		arr := make([]int, a)
		for i := 0; i < a; i++ {
			fmt.Scan(&arr[i])
		}

		var flag int
		fmt.Scan(&flag)

		sort.Slice(arr, func(i, j int) bool {
            if flag == 0 {
                return arr[i]<=arr[j]
            }
			return arr[i]>arr[j]
		})

		for i := 0; i < len(arr); i++ {
			fmt.Printf("%d ", arr[i])
		}
	}
}
