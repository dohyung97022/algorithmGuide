package main

// this seems a simple and easy question
func largestAltitude(gain []int) int {
	var highest int
	var sum int
	for _, height := range gain {
		sum += height
		if sum > highest {
			highest = sum
		}
	}
	return highest
}
