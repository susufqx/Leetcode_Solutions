package main

import (
	"fmt"
	"sort"
)

func groupAnagrams(strs []string) [][]string {
	m := make(map[string][]string, len(strs))
	for _, str := range strs {
		r := wordSort(str)
		if _, ok := m[r]; ok {
			m[r] = append(m[r], str)
		} else {
			m[r] = []string{str}
		}
	}

	res := [][]string{}
	for _, values := range m {
		res = append(res, values)
	}

	return res
}

func wordSort(str string) string {
	l := []int{}
	for _, s := range str {
		l = append(l, int(s))
	}

	sort.Ints(l)
	r := ""
	for _, i := range l {
		r = r + string(rune(i))
	}

	return r
}

func main() {
	strs := []string{"eat", "tea", "tan", "ate", "nat", "bat"}
	fmt.Println(groupAnagrams(strs))
}
