package main

func pivotIndex(nums []int) int {
	// create a new array with the sums of the nums until that index
	// the len(sums) is len(nums)+1 that starts with a 0
	sums := []int{0}
	for i, num := range nums {
		sums = append(sums, sums[i]+num)
	}

	for i := 0; i < len(sums)-1; i++ {
		// the sum of the left can be found by what value is in the new array
		// the sum of the right can be found by the sub of the last index and the current index
		// if the both sums are equal return the index
		if sums[i] == sums[len(sums)-1]-sums[i]-nums[i] {
			return i
		}
	}
	// if not until the end, return -1
	return -1
}
