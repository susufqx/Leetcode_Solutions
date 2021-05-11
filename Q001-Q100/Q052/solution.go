package main

func fillPoint(m [][]string, n int) [][]string {
	for i := 0; i < n; i++ {
		t := []string{}
		for j := 0; j < n; j++ {
			t = append(t, ".")
		}
		m = append(m, t)
	}

	return m
}

func totalNQueens(n int) int {
	count := 0

	m := [][]string{}
	m = fillPoint(m, n)
	solveNQ(m, &count, 0, n)

	return count
}

func solveNQ(m [][]string, count *int, row, n int) {
	if n == row {
		*count++
	} else {
		for i := 0; i < n; i++ {
			if canInsert(m, row, i) {
				m[row][i] = "Q"
				solveNQ(m, count, row+1, n)
				m[row][i] = "."
			}
		}
	}

}

func canInsert(m [][]string, row, column int) bool {
	for i := 0; i < len(m); i++ {
		if m[i][column] == "Q" {
			return false
		}

		if row+column-i >= 0 && row+column-i < len(m) && m[i][row+column-i] == "Q" {
			return false
		}

		if column-row+i >= 0 && column-row+i < len(m) && m[i][column-row+i] == "Q" {
			return false
		}
	}

	return true
}
