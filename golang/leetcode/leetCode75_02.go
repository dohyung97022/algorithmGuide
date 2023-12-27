package main

import "fmt"

// https://leetcode.com/problems/greatest-common-divisor-of-strings/?envType=study-plan-v2&envId=leetcode-75

func gcdOfStrings(str1 string, str2 string) string {
	// 1. find the shorder length string
	var shorterStr string
	if len(str1) < len(str2) {
		shorterStr = str1
	} else {
		shorterStr = str2
	}

	// 2. iterate from the whole of the shorter string and remove each character
	var resultStr string
	for i := 0; i < len(shorterStr); i++ {
		resultStr = shorterStr[0 : len(shorterStr)-i]

		// 2-1. check if the shorter string is dividable
		// 2-2. check if the longer string is dividable
		if isDevidable(str1, resultStr) && isDevidable(str2, resultStr) {
			// 3. return from iteration if both string is dividable
			return resultStr
		}
	}

	// 4. return empty string if not dividable
	return ""
}

func isDevidable(devidingStr string, devidingByStr string) bool {
	// 2-1-1. is the string len devidable by the deviding string?
	if len(devidingStr)%len(devidingByStr) > 0 {
		return false
	}
	// 2-1-2. for loop each character of the devidingStr
	var j = 0
	for i := 0; i < len(devidingStr); i++ {
		if !(devidingStr[i] == devidingByStr[j]) {
			return false
		}
		j++
		if j == len(devidingByStr) {
			j = 0
		}
	}
	return true
}

func main() {
	// same string
	fmt.Printf("%v\n", gcdOfStrings("abc", "abc"))
	// str1 is the divider, str2 is being divided
	fmt.Printf("%v\n", gcdOfStrings("abc", "abcabc"))
	// str2 is the divider, str1 is being divided
	fmt.Printf("%v\n", gcdOfStrings("abcabc", "abc"))
	// str2, str1 is len 1
	fmt.Printf("%v\n", gcdOfStrings("a", "a"))
	// str1 is len 1
	fmt.Printf("%v\n", gcdOfStrings("a", "aaa"))
	// str2 is len 1
	fmt.Printf("%v\n", gcdOfStrings("abc", "a"))
}
