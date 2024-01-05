package main

// all the people are attempting the "zeroCount" method.
// seems like the best and fast answer, but still, well thought os the testcases.

func longestSubarray(nums []int) int {
	// check left and right element in order to check for these cases
	leftPnt := 0
	rightPnt := 0
	movePnt := 0
	maxCnt := 0
	tmpCnt := 0

	for i := 0; i < len(nums); i++ {
		if nums[i] == 0 {
			continue
		}

		// set leftPnt, rightPnt and i to the rightmost 1
		leftPnt = i
		rightPnt = i
		for rightPnt+1 < len(nums) && nums[rightPnt+1] == 1 {
			rightPnt++
		}
		// move i to the rightmost pointer
		i = rightPnt

		// case 1. can remove left element
		tmpCnt = rightPnt - leftPnt + 1
		movePnt = -1
		if leftPnt+movePnt >= 0 && nums[leftPnt+movePnt] == 0 {
			movePnt--
			for leftPnt+movePnt >= 0 && nums[leftPnt+movePnt] == 1 {
				movePnt--
				tmpCnt++
			}
		} else {
			// case 2. cant remove left element
			tmpCnt--
		}
		if tmpCnt > maxCnt {
			maxCnt = tmpCnt
		}

		tmpCnt = rightPnt - leftPnt + 1
		movePnt = 1
		if rightPnt+movePnt < len(nums) && nums[rightPnt+movePnt] == 0 {
			// case 3. can remove right element
			movePnt++
			for rightPnt+movePnt < len(nums) && nums[rightPnt+movePnt] == 1 {
				movePnt++
				tmpCnt++
			}
		} else {
			// case 4. cant remove right element
			tmpCnt--
		}
		if tmpCnt > maxCnt {
			maxCnt = tmpCnt
		}

		// case 5. array [0]
		// case 6. array [1]
	}
	return maxCnt
}
