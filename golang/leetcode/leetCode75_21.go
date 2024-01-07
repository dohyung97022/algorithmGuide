package main

func uniqueOccurrences(arr []int) bool {
	// create a countMap of number to count
	// for loop arr in order to create this countMap
	countMap := make(map[int]int)
	for _, num := range arr {
		countMap[num]++
	}
	// create a occurMap of count to bool
	occurMap := make(map[int]bool)
	// for loop the countMap in order to create this occurMap
	for _, value := range countMap {
		// while doing so, if the occurMap of key exists, return false
		if occurMap[value] {
			return false
		}
		occurMap[value] = true
	}
	// if the loop finished, return true
	return true
}
