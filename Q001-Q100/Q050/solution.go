package main

import "fmt"

func myPow(x float64, n int) float64 {
	if n == 0 {
		if x == 0.0 {
			return 0 // wrong 0^0
		}

		return 1
	}

	if n == 1 {
		return x
	}

	if n < 0 {
		return myPow(1/x, -n)
	}

	m := n / 2
	r := n % 2
	if r == 1 {
		return myPow(x*x, m) * x
	}

	return myPow(x*x, m)
}

func main() {
	fmt.Println(myPow(0.00001, 2147483647))
}
