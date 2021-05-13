package main

func canJump(nums []int) bool {
	maxReach := 0
	for i, num := range nums {
		if maxReach >= len(nums)-1 {
			return true
		}

		if num == 0 && i == maxReach {
			return false
		}

		tempReach := i + num
		if tempReach > maxReach {
			maxReach = tempReach
		}
	}

	return true
}
