package main

func moveZeroes(nums []int) {
	var zeroCnt int = 0
	var fillingIdx int = 0

	for i := 0; i <= len(nums); i++ {
		if i == len(nums) {
			break
		}
		if nums[i] == 0 {
			zeroCnt++
		} else {
			nums[fillingIdx] = nums[i]
			fillingIdx++
		}
	}

	for j := 0; j < zeroCnt; j++ {
		nums[len(nums)-1-j] = 0
	}
}

// my answer has a sufficiently longer runtime, check the two pointer approach
// it seems that they take the approach of putting a left and right pointer in order to exchange the numbers and zero
