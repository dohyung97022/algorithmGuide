package main

func findMaxAverage(nums []int, k int) float64 {
	maxSum := 0
	curSum := 0
	for i := 0; i < k; i++ {
		curSum += nums[i]
	}
	maxSum = curSum
	for i := k; i < len(nums); i++ {
		curSum -= nums[i-k]
		curSum += nums[i]
		if curSum > maxSum {
			maxSum = curSum
		}
	}
	return float64(maxSum) / float64(k)
}
