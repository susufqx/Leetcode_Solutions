package main

import "fmt"

func permuteUnique(nums []int) [][]int {
	res := [][]int{}

	if len(nums) == 1 {
		return append(res, nums)
	}

	if len(nums) == 2 {
		res = append(res, nums)
		if nums[0] == nums[1] {
			return res
		}

		newNums := make([]int, 2)
		newNums[0] = nums[1]
		newNums[1] = nums[0]
		res = append(res, newNums)
		return append(res)
	}

	record := map[int]bool{}
	for i, num := range nums {
		if record[num] == true {
			continue
		}

		record[num] = true
		tnums := make([]int, len(nums))
		copy(tnums, nums)
		newNums := append(tnums[:i], tnums[i+1:]...)
		r := permuteUnique(newNums)
		for _, items := range r {
			add := []int{num}
			res = append(res, append(add, items...))
		}
	}

	return res
}

func main() {
	nums := []int{1, 1, 3}
	fmt.Println(permuteUnique(nums))
}
