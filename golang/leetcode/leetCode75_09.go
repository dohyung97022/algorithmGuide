package main

import (
	"strconv"
)

func compress(chars []byte) int {
	// 1. create a custom for loop that checks the next index until that char is different
	var resultChars []byte
	var checkChar byte = chars[0]
	var cnt int = 0
	for i := 0; i <= len(chars); i++ {
		// if end of line or different char
		if i == len(chars) || checkChar != chars[i] {
			// add the character, cnt to a new array
			resultChars = append(resultChars, checkChar)
			if cnt != 1 {
				for _, char := range strconv.Itoa(cnt) {
					resultChars = append(resultChars, byte(char))
				}
			}
		}
		if i == len(chars) {
			break
		} else if checkChar == chars[i] {
			cnt++
		} else {
			cnt = 1
			checkChar = chars[i]
		}
	}
	for i, char := range resultChars {
		chars[i] = char
	}
	// 4. return the len of the new array
	return len(resultChars)
}

func main() {
	var chars []byte = []byte("aaabbbcc")
	compress(chars)
}
