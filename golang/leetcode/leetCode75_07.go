package main

func productExceptSelf(nums []int) []int {
	var value int
	var leftArray []int
	var rightArray []int
	var resultArray []int

	// 1. for loop to create left array that saves the previous products
	for i := 0; i < len(nums); i++ {
		value = nums[i]
		if i != 0 {
			value = value * leftArray[i-1]
		}
		leftArray = append(leftArray, value)
	}

	// 2. reverse for loop to create right array that saves the previous products
	for i := 0; i < len(nums); i++ {
		value = nums[len(nums)-1-i]
		if i != 0 {
			value = value * rightArray[i-1]
		}
		rightArray = append(rightArray, value)
	}

	// 3. get the product of the left and the right array and return it
	for i := 0; i < len(nums); i++ {
		value = 1
		if i-1 >= 0 {
			value = value * leftArray[i-1]
		}
		if len(nums)-2-i >= 0 {
			value = value * rightArray[len(nums)-i-2]
		}
		resultArray = append(resultArray, value)
	}

	return resultArray
}
