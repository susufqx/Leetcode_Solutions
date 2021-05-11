package main

import "fmt"

func main() {
	a := []int{1, 2, 3, 4}
	fmt.Println(a)
	b := make([]int, 4)
	copy(b, a)
	fmt.Println(b)
	a[0] = 99
	fmt.Println(b)
	fmt.Println(a)
}
