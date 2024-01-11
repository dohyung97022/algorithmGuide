package main

import (
	"fmt"
	"strconv"
	"strings"
)

func decodeString(s string) string {
	var i int
	result := decodeSquareBracket(&s, &i)
	return result
}

func decodeSquareBracket(s *string, i *int) string {
	var builder strings.Builder
	// for loop s from j
	var numByteArr []byte
	for *i < len(*s) {
		// if it hits a number
		if 48 <= byte((*s)[*i]) && byte((*s)[*i]) <= 57 {
			// get the number until [
			numByteArr = append(numByteArr, (*s)[*i])
			*i++
			continue
			// if it hits [
		} else if (*s)[*i] == '[' {
			// append the result of decodeSquareBracket
			*i++
			innerRes := decodeSquareBracket(s, i)
			repeat, _ := strconv.Atoi(string(numByteArr))
			for q := 0; q < repeat; q++ {
				builder.WriteString(innerRes)
			}
			numByteArr = []byte{}
		} else if (*s)[*i] == ']' {
			*i++
			return builder.String()
		} else {
			// if it hits a character
			// append the character
			builder.WriteByte((*s)[*i])
			*i++
		}
	}
	return builder.String()
}

func main() {
	fmt.Println(decodeString("3[a]2[bc]"))
}
