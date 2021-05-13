package main

import "fmt"

func spiralOrder(matrix [][]int) []int {
	res := []int{}
	m := len(matrix)
	n := len(matrix[0]) // because m >= 1
	i := 0
	j := 0
	direction := "right"
	border := [4]int{1, m - 1, 0, n - 1} // up 0, down 1, left 2, right 3
	for len(res) < m*n {
		res = append(res, matrix[i][j])
		switch direction {
		case "right":
			if j+1 <= border[3] {
				j++
			} else {
				i++
				border[3]--
				direction = "down"
			}
		case "down":
			if i+1 <= border[1] {
				i++
			} else {
				j--
				border[1]--
				direction = "left"
			}
		case "left":
			if j-1 >= border[2] {
				j--
			} else {
				i--
				border[2]++
				direction = "up"
			}
		case "up":
			if i-1 >= border[0] {
				i--
			} else {
				j++
				border[0]++
				direction = "right"
			}
		}
	}

	return res
}

func main() {
	m := [][]int{}
	c := 1
	for i := 0; i < 3; i++ {
		line := []int{}
		for j := 0; j < 3; j++ {
			line = append(line, c)
			c++
		}
		m = append(m, line)
	}

	fmt.Println("-----", m)
	fmt.Println("~~~~~", spiralOrder(m))
}
