package main

import "strings"

// TODO : lets memorize some basic functions in go
// By memorizing some basic functionality like `strings.` it would be way easier.

// My answer
func reverseWords(s string) string {
	// 1. change the s into a array of unicode bytes
	sBytes := []byte(s)
	wordBytes := []byte{}
	resultBytes := []byte{}
	// 2. for loop backwards the array until it hits a space
	for i := len(sBytes) - 1; i >= 0; i-- {
		if sBytes[i] != byte(' ') {
			// 3-1. if not space, it adds the word into wordBytes in reverse
			wordBytes = append(wordBytes, sBytes[i])
		}

		// 3-2. if space, add the word(reversed) in the result byte array
		if 0 < len(wordBytes) && (sBytes[i] == byte(' ') || i == 0) {
			for 0 < len(wordBytes) {
				resultBytes = append(resultBytes, wordBytes[len(wordBytes)-1])
				wordBytes = wordBytes[:len(wordBytes)-1]
			}
			resultBytes = append(resultBytes, byte(' '))
		}
	}

	// trim last
	for resultBytes[len(resultBytes)-1] == byte(' ') {
		resultBytes = resultBytes[:len(resultBytes)-1]
	}

	// 4. return the result array as string
	return string(resultBytes)
}

// best answer
func reverseWords2(s string) string {
	// Split the input string into words
	words := strings.Fields(s)

	// Initialize pointers for the word reversal
	low, high := 0, len(words)-1

	// Swap words using the two-pointer approach
	for low < high {
		words[low], words[high] = words[high], words[low]
		low++
		high--
	}

	// Join the reversed words back into a single string and trim spaces
	return strings.TrimSpace(strings.Join(words, " "))
}
