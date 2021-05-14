package main

func insert(intervals [][]int, newInterval []int) [][]int {
	a := []int{}
	a = append(a, newInterval...)
	for _, interval := range intervals {
		a = append(a, interval...)
	}

	quickSort(a, 0, len(a)-1)
	res := [][]int{}
	for i, v := range a {
		if newInterval[0] == v {
			if i%2 != 0 {
				newInterval[0] = a[i-1]
			}
		}

		if newInterval[1] == v {
			if i%2 == 0 {
				newInterval[1] = a[i+1]
			}

		}
	}

	i := 0
	add := true
	for i < len(a)-1 {
		if a[i] == newInterval[0] && add {
			res = append(res, newInterval)
			add = false
		} else if a[i] < newInterval[0] || a[i] > newInterval[1] {
			res = append(res, []int{a[i], a[i+1]})
		}
		i = i + 2
	}

	return res
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
