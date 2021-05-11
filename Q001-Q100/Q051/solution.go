package main

import (
	"fmt"
	"strings"
)

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

func solveNQueens(n int) [][]string {
	res := [][]string{}

	m := [][]string{}
	m = fillPoint(m, n)
	res = solveNQ(m, res, 0, n)

	return res
}

func solveNQ(m, res [][]string, row, n int) [][]string {
	if n == row {
		t := []string{}
		for i := 0; i < n; i++ {
			t = append(t, strings.Join(m[i], ""))
		}
		// fmt.Println(t)
		res = append(res, t)
	} else {
		for i := 0; i < n; i++ {
			if canInsert(m, row, i) {
				m[row][i] = "Q"
				res = solveNQ(m, res, row+1, n)
				m[row][i] = "."
			}
		}
	}

	return res
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

func main() {
	fmt.Println(solveNQueens(4))
}
