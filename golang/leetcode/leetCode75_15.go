package main

func maxVowels(s string, k int) int {
	maxVowelCnt := 0
	curVowelCnt := 0

	for i := 0; i < k; i++ {
		if isVowel(s[i]) {
			curVowelCnt++
		}
	}
	maxVowelCnt = curVowelCnt

	for i := k; i < len(s); i++ {
		if isVowel(s[i-k]) {
			curVowelCnt--
		}
		if isVowel(s[i]) {
			curVowelCnt++
		}
		if curVowelCnt > maxVowelCnt {
			maxVowelCnt = curVowelCnt
		}
	}
	return maxVowelCnt
}

func isVowel(char byte) bool {
	return char == byte('a') || char == byte('e') || char == byte('i') || char == byte('o') || char == byte('u')
}
