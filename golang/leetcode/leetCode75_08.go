package main

// failed, must have thought about the two pointer method

func increasingTriplet(nums []int) bool {
	// if the number has a lowwer left number
	// and this repeats 2 times, the result is true
	// the hasLowerLeftLowest keep the lowest number that has a lower left

	var isFirstSet bool = false
	var hasLowerLeftLowest int = 0
	for i := 0; i < len(nums); i++ {
		// 1. check if the current number is lower or higher than hasLowerLeftLowest

		if nums[i] > hasLowerLeftLowest && isFirstSet {
			// 2. return true if higher
			return true
		} else {
			// 3. if lower
			// 3-1. check if the number has a lower value in front
			for j := i; j >= 0; j-- {
				// 3-2. if true, replace hasLowerLeftLowest
				if nums[j] < nums[i] {
					hasLowerLeftLowest = nums[i]
					isFirstSet = true
					break
				}
			}
		}
	}
	// 4. return false if none is found
	return false
}
