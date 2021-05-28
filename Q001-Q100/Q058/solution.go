package main

func lengthOfLastWord(s string) int {
	start := false
	count := 0
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == ' ' {
			if start {
				break
			}
		} else {
			start = true
			count++
		}
	}

	return count
}
