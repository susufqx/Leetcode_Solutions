package main

func insert(intervals [][]int, newInterval []int) [][]int {
	// return merge(append(intervals, newInterval))
	a := []int{}
	a = append(a, newInterval...)
	for _, interval := range intervals {
		a = append(a, interval...)
	}

	quickSort(a, 0, len(a)-1)
	res := [][]int{}
	left, right := 0, 0
	for i, v := range a {
		if newInterval[0] == v {
			if i%2 != 0 {
				newInterval[0] = a[i-1]
				left = i - 1
			} else {
				left = i
			}
		}

		if newInterval[1] == v {
			if i%2 == 0 {
				newInterval[1] = a[i+1]
				right = i + 1
			} else {
				right = i
			}

		}
	}

}

func quickSort(nums []int, left, right int) {
	if left < right {
		i, j := left, right
		flag := nums[(left+right)/2]
		for i <= j {
			for nums[i] < flag {
				i++
			}

			for nums[j] > flag {
				j--
			}

			if i <= j {
				nums[i], nums[j] = nums[j], nums[i]
				i++
				j--
			}
		}

		if left < j {
			quickSort(nums, left, j)
		}

		if right > i {
			quickSort(nums, i, right)
		}
	}
}
