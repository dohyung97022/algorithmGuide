package main

func findDifference(nums1 []int, nums2 []int) [][]int {
	// create a map1 that contains the number of nums1
	var map1 = make(map[int]bool)
	for _, num := range nums1 {
		map1[num] = true
	}
	// create a map2 that contains the number of nums2
	var map2 = make(map[int]bool)
	for _, num := range nums2 {
		map2[num] = true
	}
	// for loop the map1 and check if the index exists in both map1 and map2
	result := [][]int{{}, {}}
	for i, _ := range map1 {
		if map2[i] == true {
			// if so, do not add to the result array
			// remove from the second array
			delete(map2, i)
			continue
		}
		// if not, add to the result array in the desired dimention
		result[0] = append(result[0], i)
	}
	for i, _ := range map2 {
		result[1] = append(result[1], i)
	}

	// return the result
	return result
}
