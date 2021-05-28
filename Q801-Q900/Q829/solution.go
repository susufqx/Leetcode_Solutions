package main

import "fmt"

func consecutiveNumbersSum(n int) int {
	count := 1
	maxAna := n/2 + 1

	for k := 1; k <= maxAna; k++ {
		target := n - k*(k+1)/2
		if target <= 0 {
			break
		}

		if target%(k+1) == 0 {
			count++
		}

	}

	return count
}

func main() {
	fmt.Println(consecutiveNumbersSum(84418900))
	// fmt.Println(consecutiveNumbersSum(9))
}
