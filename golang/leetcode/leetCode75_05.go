package main

func reverseVowels(s string) string {
	// 1. change the string to an array of bytes
	vowels := []byte{byte('a'), byte('e'), byte('i'), byte('o'), byte('u'),
		byte('A'), byte('E'), byte('I'), byte('O'), byte('U')}
	sBytes := []byte(s)
	vBytes := []byte{}
	for i, sByte := range sBytes {
		// 2. for loop change the value to 255 if it is a vowel and save the value in another array
		for _, vowel := range vowels {
			if sByte == vowel {
				vBytes = append(vBytes, sByte)
				sBytes[i] = 255
				break
			}
		}
	}
	// 3. for loop the changed array and if the value is 255, change it to the vowel array in   reversed order
	for i, sByte := range sBytes {
		if sByte == 255 {
			sBytes[i] = vBytes[len(vBytes)-1]
			vBytes = vBytes[:len(vBytes)-1]
		}
	}
	// 4. return the array into a string
	return string(sBytes)
}
