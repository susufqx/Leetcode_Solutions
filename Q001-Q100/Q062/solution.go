package main

import "fmt"

func uniquePaths(m int, n int) int {
	d := make([][]int, m)
	for i := range d {
		d[i] = make([]int, n)
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if i == 0 || j == 0 {
				fmt.Println("------", i, "   ", j)
				d[i][j] = 1
			} else {
				d[i][j] = d[i-1][j] + d[i][j-1]
			}
		}
	}

	return d[m-1][n-1]
}

func main() {
	fmt.Println(uniquePaths(51, 9))
}
