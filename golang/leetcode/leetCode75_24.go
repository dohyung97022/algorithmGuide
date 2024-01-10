package main

func removeStars(s string) string {
	var sStack []byte
	for i := 0; i < len(s); i++ {
		if s[i] == '*' {
			sStack = sStack[:len(sStack)-1]
		} else {
			sStack = append(sStack, byte(s[i]))
		}
	}
	return string(sStack)
}
