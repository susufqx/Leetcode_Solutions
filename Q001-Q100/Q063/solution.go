package main

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	si := false
	sj := false
	for i := 0; i < len(obstacleGrid); i++ {
		for j := 0; j < len(obstacleGrid[i]); j++ {
			if i == 0 && j == 0 {
				if obstacleGrid[0][0] == 1 {
					return 0
				} else {
					obstacleGrid[0][0] = -1
				}

				continue
			}

			if i == 0 {
				if obstacleGrid[i][j] == 0 {
					if !si {
						obstacleGrid[i][j] = -1
					}
				}

				if obstacleGrid[i][j] == 1 {
					si = true
				}
			} else if j == 0 {
				if obstacleGrid[i][j] == 0 {
					if !sj {
						obstacleGrid[i][j] = -1
					}
				}

				if obstacleGrid[i][j] == 1 {
					sj = true
				}
			} else {
				if obstacleGrid[i][j] == 1 {
					continue
				}

				if obstacleGrid[i-1][j] != 1 && obstacleGrid[i][j-1] == 1 {
					obstacleGrid[i][j] = obstacleGrid[i-1][j]
				}

				if obstacleGrid[i-1][j] == 1 && obstacleGrid[i][j-1] != 1 {
					obstacleGrid[i][j] = obstacleGrid[i][j-1]
				}

				if obstacleGrid[i-1][j] != 1 && obstacleGrid[i][j-1] != 1 {
					obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1]
				}
			}

		}
	}

	res := -obstacleGrid[len(obstacleGrid)-1][len(obstacleGrid[0])-1]
	if res == -1 {
		return 0
	}

	return res
}
