package main

func maxSubArray(nums []int) int {
	sum := nums[0]
	max := nums[0]
	for i, v := range nums {
		if i == 0 {
			continue
		}

		if sum < 0 {
			if v > sum {
				sum = v
				if max < sum {
					max = sum
				}
			}
		} else {
			sum += v
			if max < sum {
				max = sum
			}
		}
	}

	return max
}
