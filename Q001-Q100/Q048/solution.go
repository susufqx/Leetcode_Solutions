package main

import "fmt"

func rotate(matrix [][]int) {
	n := len(matrix)
	if n == 1 {
		return
	}

	temp := matrix[0][0]
	right := n - 2
	i := 0
	j := 0
	mid := n / 2
	for right >= j {
		a := i
		b := j
		temp = matrix[a][b]
		if !(n%2 == 1 && a == mid && b == mid) {
			for k := 0; k < 4; k++ {
				record := matrix[b][n-1-a]
				matrix[b][n-1-a] = temp
				temp = record
				t := a
				a = b
				b = n - 1 - t
			}
		}

		if j < right {
			j++
		} else {
			i++
			j = i
			right--
		}
	}
}

func main() {
	// matrix := [][]int{[]int{1, 2, 3}, []int{4, 5, 6}, []int{7, 8, 9}}
	// matrix := [][]int{[]int{1, 2}, []int{3, 4}}
	matrix := [][]int{[]int{5, 1, 9, 11}, []int{2, 4, 8, 10}, []int{13, 3, 6, 7}, []int{15, 14, 12, 16}}
	fmt.Println(matrix)
	rotate(matrix)
	fmt.Println(matrix)
}
