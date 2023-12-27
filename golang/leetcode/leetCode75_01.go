package main

import "fmt"

// https://leetcode.com/problems/merge-strings-alternately/?envType=study-plan-v2&envId=leetcode-75

func mergeAlternately(word1 string, word2 string) string {

	var minLen, lesserIndex = getMinLenCompareString(word1, word2)
	var resultStr string

	for i := 0; i < minLen; i++ {
		resultStr += string(word1[i])
		resultStr += string(word2[i])
	}

	if lesserIndex == 0 {
		resultStr += word2[minLen:len(word2)]
	} else {
		resultStr += word1[minLen:len(word1)]
	}

	return resultStr
}

func getMinLenCompareString(word1 string, word2 string) (int, int) {
	if len(word1) < len(word2) {
		return len(word1), 0
	} else {
		return len(word2), 1
	}
}

func main() {
	// testcase
	// 1. len(word1) > len(word2)
	fmt.Printf("%s\n", mergeAlternately("abcdefgXXXXX", "abcdefg"))
	// 2. len(word1) < len(word2)
	fmt.Printf("%s\n", mergeAlternately("abcdefg", "abcdefgXXXXX"))
	// 3. len(word1) == len(word2)
	fmt.Printf("%s\n", mergeAlternately("abcdefg", "abcdefg"))
	// 4. len(word1) == len(word2) == 1
	fmt.Printf("%s\n", mergeAlternately("a", "a"))
	// 4. len(word1) == len(word2) == 100
	var testStr string
	for i := 0; i < 100; i++ {
		testStr += "a"
	}
	fmt.Printf("%s\n", mergeAlternately(testStr, testStr))
}
