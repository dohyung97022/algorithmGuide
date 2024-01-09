package main

func closeStrings(word1 string, word2 string) bool {
	// "cabbba"
	// "caabbb"
	// "caabbb" -> map[byte]int charToCnt -> {'c':1, 'a':2, 'b':3}
	// charToCnt -> cntToCnt -> {1:1, 2:1, 3:1}
	charToCnt1, cntToCnt1 := getCharToCntAndCntToCnt(word1)

	// "abbccc" -> map[byte]int charToCnt -> {'a':1, 'b':2, 'c':3}
	// charToCnt -> cntToCnt -> {1:1, 2:1, 3:1}
	charToCnt2, cntToCnt2 := getCharToCntAndCntToCnt(word2)

	// we must need all the caracters && we must need all the numbers
	// for loop charToCnt in order to check if the character exists
	for char, _ := range charToCnt1 {
		if charToCnt2[char] == 0 {
			return false
		}
	}
	// for loop cntToCnt in order to check if the number count matches
	for num, cnt := range cntToCnt1 {
		if cntToCnt2[num] != cnt {
			return false
		}
	}
	// if both matches return true
	// else return false
	return true
}

func getCharToCntAndCntToCnt(word string) (map[byte]int, map[int]int) {
	charToCnt := make(map[byte]int)
	for _, char := range word {
		charToCnt[byte(char)]++
	}
	cntToCnt := make(map[int]int)
	for _, cnt := range charToCnt {
		cntToCnt[cnt]++
	}
	return charToCnt, cntToCnt
}
