package main

import "fmt"

func equalPairs(grid [][]int) int {
	// map[[]int][2]int
	// for loop grid.length
	// check the indexed row, column
	// the value of the maps first index is the row cnt, second index is the column cnt
	// for loop the values of the map
	// increment the multiplication
	checkMap := make(map[string][]int)
	for i := 0; i < len(grid); i++ {
		row := fmt.Sprintf("%v", grid[i])
		var columnArr []int
		for j := 0; j < len(grid); j++ {
			columnArr = append(columnArr, grid[j][i])
		}
		column := fmt.Sprintf("%v", columnArr)

		_, exists := checkMap[row]
		if !exists {
			checkMap[row] = []int{0, 0}
		}
		_, exists = checkMap[column]
		if !exists {
			checkMap[column] = []int{0, 0}
		}
		checkMap[row][0]++
		checkMap[column][1]++
	}

	result := 0
	for _, value := range checkMap {
		if value[0] == 0 || value[1] == 0 {
			continue
		}
		result += value[0] * value[1]
	}
	return result
}
