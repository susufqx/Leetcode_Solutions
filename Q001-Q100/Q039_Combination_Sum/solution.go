package main

import "fmt"

func combinationSum(candidates []int, target int) [][]int {
	res := [][]int{}
	temp := []int{}
	_partCombinationSum(candidates, target, &res, temp, 0)

	return res
}

func _partCombinationSum(candidates []int, target int, res *[][]int, temp []int, start int) {
	if target < 0 {
		return
	}

	if target == 0 {
		addPart := make([]int, len(temp))
		copy(addPart, temp)
		*res = append(*res, addPart)
		return
	}

	for i := start; i < len(candidates); i++ {
		_partCombinationSum(candidates, target-candidates[i], res, append(temp, candidates[i]), i)
	}
}

func main() {
	candidates := []int{2, 3, 5}
	target := 8
	fmt.Println(combinationSum(candidates, target))
}
