package main

// failed approach
func maxOperations(nums []int, k int) int {
	// put a right pointer at nums
	// for loop nums in order to check if the sum is k
	maxOperations := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] == 0 {
			continue
		}
		// if the number is 0, just pass
		for j := len(nums) - 1; i < j; j-- {
			if nums[j] == 0 {
				continue
			}
			// if the number and the right pointer sum is k, set the index value of nums to 0, and increment maxOperations
			if nums[i]+nums[j] == k {
				nums[j] = 0
				maxOperations++
				break
			}
		}
	}
	return maxOperations
}

// accepted but still a bit slow
func maxOperations2(nums []int, k int) int {
	// create a map of number to cnt
	numberCnt := make(map[int]int)

	// for loop the nums to fill in the map of number to cnt
	for i := 0; i < len(nums); i++ {
		numberCnt[nums[i]]++
	}
	// for loop the keys of the map to check for the pair and remove both cnt to add to the operationCnt
	operationCnt := 0
	lowestValue := 0
	for key, value := range numberCnt {
		if k-key == key {
			lowestValue = numberCnt[key] / 2
		} else if numberCnt[k-key] > value {
			lowestValue = value
		} else {
			lowestValue = numberCnt[k-key]
		}

		numberCnt[key] = 0
		numberCnt[k-key] = 0
		operationCnt = operationCnt + lowestValue
	}

	// return the operationCnt
	return operationCnt
}

func main() {
	maxOperations2([]int{1, 2, 3, 4}, 5)
}
