package main

import "fmt"

func consecutiveNumbersSumRes(n int) [][]int {
	res := [][]int{}
	maxAna := n/2 + 1

	for k := 1; k <= maxAna; k++ {
		target := n - k*(k+1)/2
		if target <= 0 {
			break
		}

		if target%(k+1) == 0 {
			start := target / (k + 1)
			end := start + k
			addArray := []int{}
			for it := start; it <= end; it++ {
				addArray = append(addArray, it)
			}
			res = append(res, addArray)
		}

	}

	return res
}

func main() {
	fmt.Println(consecutiveNumbersSumRes(15))
	// fmt.Println(consecutiveNumbersSum(9))
}
