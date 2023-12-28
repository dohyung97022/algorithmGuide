package main

func kidsWithCandies(candies []int, extraCandies int) []bool {
	// 1. for loop for the highest number of candies in candies array
	var highestCandieCnt int = 0
	for i := 0; i < len(candies); i++ {
		if candies[i] > highestCandieCnt {
			highestCandieCnt = candies[i]
		}
	}

	// 2. for loop and add extraCandies to check if the number is higer than what is found in 1.
	var result []bool
	for i := 0; i < len(candies); i++ {
		result = append(result, candies[i]+extraCandies >= highestCandieCnt)
	}

	// 3. return the boolean array
	return result
}
