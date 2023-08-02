package main

import (
	"fmt"
)

var res [][]int

func main() {
	var m, n int
	fmt.Scan(&m, &n)

	nums := make([][]int, m)
	for i := 0; i < m; i++ {
		nums[i] = make([]int, n)
		for j := 0; j < n; j++ {
			fmt.Scan(&nums[i][j])
		}
	}

	dfs(nums, m, n, 0, 0)
	for _, x := range res {
		fmt.Printf("(%d,%d)\n", x[0], x[1])
	}
	fmt.Printf("(%d,%d)\n", m-1, n-1)
}
func dfs(nums [][]int, m, n, i, j int) bool {
	if i == m-1 && j == n-1 {
		return true
	}

	if i < 0 || i >= m || j < 0 || j >= n || nums[i][j] == 1 || nums[i][j] == -1 {
		return false
	}

	nums[i][j] = -1
	res = append(res, []int{i, j})

	if dfs(nums, m, n, i+1, j) || dfs(nums, m, n, i-1, j) || dfs(nums, m, n, i, j+1) || dfs(nums, m, n, i, j-1) {
		return true
	}

	nums[i][j] = 0
	res = res[:len(res)-1]
	return false
}
