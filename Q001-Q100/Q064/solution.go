package main

func minPathSum(grid [][]int) int {
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if i == 0 && j == 0 {
				continue
			}

			if i == 0 {
				grid[i][j] = grid[i][j-1] + grid[i][j]
			} else if j == 0 {
				grid[i][j] = grid[i-1][j] + grid[i][j]
			} else {
				v1 := grid[i][j] + grid[i-1][j]
				v2 := grid[i][j] + grid[i][j-1]
				if v1 > v2 {
					grid[i][j] = v2
				} else {
					grid[i][j] = v1
				}
			}
		}
	}

	return grid[len(grid)-1][len(grid[0])-1]
}
