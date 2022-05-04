package main

import (
	"fmt"
	"strconv"
	"strings"
)

func inChars(cs []string, c string) bool {
	for _, ci := range cs {
		if ci == c {
			return true
		}
	}

	return false
}

func isNumber(s string) bool {
	chars := []string{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ".", "+", "-", "e", "E"}
	vals := strings.Split(s, "")
	for i, val := range vals {
		if !inChars(chars, val) {
			return false
		}

		if val == "+" || val == "-" {
			if i+1 > len(vals)-1 {
				return false
			}

			if vals[i+1] == "+" || vals[i+1] == "-" {
				return false
			}

			var vs []string
			if i == 0 {
				vs = vals[i+1:]
			} else {
				if vals[i-1] == "e" || vals[i-1] == "E" {
					vs = append(vals[:i-1], vals[i+1:]...)
				} else {
					return false
				}
			}

			return isNumber(strings.Join(vs, ""))
		}

		if val == "." {
			if i+1 > len(vals)-1 {
				if len(vals) == 1 {
					return false
				}

				_, e := strconv.Atoi(strings.Join(vals[:len(vals)-1], ""))
				return e == nil
			}

			if inChars(vals[i+1:], ".") {
				return false
			}

			return isNumber(strings.Join(vals[i+1:], ""))
		}

		if val == "e" || val == "E" {
			if i == 0 {
				return false
			}

			if i+1 > len(vals)-1 {
				return false
			}

			if inChars(vals[i+1:], "e") || inChars(vals[i+1:], "E") {
				return false
			}

			_, e := strconv.Atoi(strings.Join(vals[i+1:], ""))
			return e == nil
		}
	}

	return true
}

func main() {
	fmt.Println(isNumber(".-4"))
}
