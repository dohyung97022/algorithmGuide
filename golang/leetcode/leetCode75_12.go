package main

func maxArea(height []int) int {
	// idea 1
	// 1. set two pointers on the left and right
	l, r, temp := 0, len(height)-1, 0
	width := widthArea(height, l, r)

	for l < r {

		// 2. get the lower length of the left and right in order to calculate the len
		if height[l] < height[r] {
			temp = height[l]
			// 3. the lower pointer moves to the center in order to find a longer value
			for height[l] <= temp && l < r {
				l++
			}

		} else {
			temp = height[r]
			for height[r] <= temp && l < r {
				r--
			}
		}
		// 4. if a longer value is found, compare with the previous width in order to make a new width
		temp = widthArea(height, l, r)
		if width < temp {
			width = temp
		}
	}

	// 5. return the width
	return width
}

func widthArea(height []int, l int, r int) int {
	if height[l] < height[r] {
		return (r - l) * height[l]
	} else {
		return (r - l) * height[r]
	}
}
