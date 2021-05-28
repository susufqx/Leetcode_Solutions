package main

import "fmt"

func generateMatrix(n int) [][]int {
	res := [][]int{}

	// initial -1 n x n matrix
	for i := 0; i < n; i++ {
		addArray := []int{}
		for j := 0; j < n; j++ {
			addArray = append(addArray, -1)
		}

		res = append(res, addArray)
	}

	i, j, count := 0, 0, 0
	direction := "right"
	borders := []int{1, n - 1, 0, n - 1} // up, down, left, right
	for count < n*n {
		count++
		fmt.Println("~~~~~", i, j, count)
		res[i][j] = count
		switch direction {
		case "right":
			j++
			if j > borders[3] {
				direction = "down"
				i++
				j--
				borders[3]--
			}
		case "down":
			i++
			if i > borders[1] {
				direction = "left"
				j--
				i--
				borders[1]--
			}
		case "left":
			j--
			if j < borders[2] {
				direction = "up"
				i--
				j++
				borders[2]++
			}
		case "up":
			i--
			if i < borders[0] {
				direction = "right"
				j++
				i++
				borders[0]++
			}
		}
	}

	return res
}

func main() {
	fmt.Println(generateMatrix(5))
}
