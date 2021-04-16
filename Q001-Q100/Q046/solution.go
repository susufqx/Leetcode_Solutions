package main

import "fmt"

func permute(nums []int) [][]int {
	return sub_permute(nums)
}

func sub_permute(nums []int) (res [][]int) {
	if len(nums) == 1 {
		return append(res, nums)
	}

	if len(nums) == 2 {
		res = append(res, nums)
		newNums := make([]int, 2)
		newNums[0] = nums[1]
		newNums[1] = nums[0]
		res = append(res, newNums)
		return append(res)
	}

	for i, num := range nums {
		tnums := make([]int, len(nums))
		copy(tnums, nums)
		newNums := append(tnums[:i], tnums[i+1:]...)
		r := sub_permute(newNums)
		for _, items := range r {
			add := []int{num}
			res = append(res, append(add, items...))
		}
	}

	return res
}

func main() {
	nums := []int{1, 2, 3, 4}
	fmt.Println(permute(nums))
}
