package main

import "fmt"

func quickSort(intervals [][]int, left, right int) {
	if left < right {
		i, j := left, right
		flag := intervals[(left+right)/2][0]
		for i <= j {
			for intervals[i][0] < flag {
				i++
			}

			for intervals[j][0] > flag {
				j--
			}

			if i <= j {
				intervals[i], intervals[j] = intervals[j], intervals[i]
				i++
				j--
			}
		}

		if left < j {
			quickSort(intervals, left, j)
		}

		if right > i {
			quickSort(intervals, i, right)
		}
	}
}

func merge(intervals [][]int) [][]int {
	// for i, interval := range intervals {
	// 	for j := i + 1; j < len(intervals); j++ {
	// 		if interval[0] > intervals[j][0] {
	// 			temp := intervals[i]
	// 			intervals[i] = intervals[j]
	// 			intervals[j] = temp
	// 		}
	// 	}
	// }
	quickSort(intervals, 0, len(intervals)-1)
	return sortMerge(intervals)
}

func sortMerge(intervals [][]int) [][]int {
	fmt.Println("ssss  : ", intervals)
	for i, interval := range intervals {
		if i > 0 {
			if intervals[i-1][1] >= interval[0] {
				intervals[i][0] = intervals[i-1][0]
				if interval[1] < intervals[i-1][1] {
					intervals[i][1] = intervals[i-1][1]
				}

				return sortMerge(append(intervals[:i-1], intervals[i:]...))
			}
		}
	}

	return intervals
}

// [[1,3],[2,6],[8,10],[15,18]]
func main() {
	t := [][]int{}
	a1 := []int{1, 4}
	a3 := []int{1, 5}
	a2 := []int{8, 10}
	a4 := []int{15, 18}
	t = append(t, a1, a2, a3, a4)
	fmt.Println(t)
	fmt.Println(merge(t))
}
