package main

import (
	"fmt"
	"strconv"
)

func getPermutation(n int, k int) string {
	ori := []int{}
	for i := 0; i < n; i++ {
		ori = append(ori, i+1)
	}

	res := []int{}
	k = k - 1
	for i := 0; i < n; i++ {
		f := factorial(n - i - 1)
		v := k/f + 1
		k = k % f
		for j := 0; j < n; j++ {
			if ori[j] > 0 {
				v--
				if v == 0 {
					res = append(res, ori[j])
					ori[j] = 0
					break
				}
			}
		}
	}

	s := ""
	for _, it := range res {
		s += strconv.Itoa(it)
	}

	return s
}

func factorial(n int) int {
	if n == 0 {
		return 1
	}

	res := 1
	for i := 1; i <= n; i++ {
		res *= i
	}

	return res
}

func main() {
	fmt.Println("-----", getPermutation(9, 32))
	fmt.Println("-----", getPermutation(4, 17))
}
