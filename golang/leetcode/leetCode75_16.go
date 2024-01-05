package main

// failed
func longestOnes(nums []int, k int) int {
	// create a new array that adds 1 and subtracts 0
	sumed_nums := []int{}
	for j, i := 0, 0; i < len(nums); i++ {
		if nums[i] == 1 && sumed_nums[j] > 0 {
			sumed_nums[j]++
		} else if nums[i] == 1 && sumed_nums[j] < 0 {
			j++
			sumed_nums[j]++
		} else if nums[i] == 0 && sumed_nums[j] > 0 {
			j++
			sumed_nums[j]--
		} else if nums[i] == 0 && sumed_nums[j] < 0 {
			sumed_nums[j]--
		}
	}

	tempK := k
	// for loop and ignore - values
	for i := 0; i < len(sumed_nums); i++ {
		if sumed_nums[i] < 0 {
			continue
		}
	}
	// if we can fill both, check both values and pick what we should fill
	// greedy algorithm approach, just attach to the bigger sum

}

func getMaxFilled(sumed_nums []int, leftIdx int, rightIdx int, currCnt int, tempK int) {
	// if a + value is found, check the left and right values if we can fill any
	if sumed_nums[leftIdx+1]+tempK >= 0 {
		// if we can fill right, add the value that we can connect
	}
	if sumed_nums[rightIdx-1]+tempK >= 0 {
		// if we can fill left, add the value that we can connect
	}
}
