package main

func canPlaceFlowers(flowerbed []int, n int) bool {
	var availableSpots int = 0
	// 1. for loop flowerbed
	for i := 0; i < len(flowerbed); i++ {
		// 2. check the current index for adjacent values

		if flowerbed[i] == 1 {
			continue
		}
		// 3. if the adjacent value is all zero, and the value itself is zero
		// 3-1. or if the adjacent value cannot be indexed due to its array size
		var isLeftEmpty bool
		if i-1 < 0 {
			isLeftEmpty = true
		} else {
			isLeftEmpty = flowerbed[i-1] == 0
		}
		var isRightEmpty bool
		if i+1 >= len(flowerbed) {
			isRightEmpty = true
		} else {
			isRightEmpty = flowerbed[i+1] == 0
		}

		if isLeftEmpty && isRightEmpty {
			// 4. add number to available spots
			availableSpots += 1
			flowerbed[i] = 1
		}
	}
	// 5. return true if n is lower or equal to available spots
	return n <= availableSpots
}
