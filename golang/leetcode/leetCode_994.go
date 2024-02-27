package main

type Element struct {
	x    int
	y    int
	step uint8
}

func orangesRotting(grid [][]int) int {
	// logic
	// for loop the grid
	// put all the rotten locations in the queue
	// count all the fresh orange

	// if the que is not empty
	// check 4 directions
	// if direction is not in bound, skip
	// if it is a blank skip
	// if it is a rotten skip
	// if it is a fresh orange, add in queue, remove fresh cnt, change to rotten, add step
	// if the step is higher than max, set max to step

	// if all queue is checked, check fresh cnt
	// if cnt is 0 return the steps

	var maxStep uint8 = 0
	var freshCnt uint8 = 0
	que := []Element{}

	for y, row := range grid {
		for x, val := range row {
			if val == 2 {
				que = append(que, Element{x: x, y: y, step: 0})
			} else if val == 1 {
				freshCnt++
			}
		}
	}

	for len(que) > 0 {
		if freshCnt == 0 {
			break
		}
		val := que[0]
		que = que[1:]

		val.x++
		check(val, &grid, &que, &freshCnt, &maxStep)
		val.x--

		val.y++
		check(val, &grid, &que, &freshCnt, &maxStep)
		val.y--

		val.x--
		check(val, &grid, &que, &freshCnt, &maxStep)
		val.x++

		val.y--
		check(val, &grid, &que, &freshCnt, &maxStep)
		val.y++
	}
	if freshCnt != 0 {
		return -1
	}
	return int(maxStep)
}

func check(element Element, grid *[][]int, que *[]Element, freshCnt *uint8, maxStep *uint8) {
	if element.y < 0 || element.y > len(*grid)-1 || // y out of range
		element.x < 0 || element.x > len((*grid)[0])-1 || // x out of range
		(*grid)[element.y][element.x] == 0 || (*grid)[element.y][element.x] == 2 { // empty or rotten
		return
	}
	(*grid)[element.y][element.x] = 2 // mark visited as rotten
	element.step++
	if element.step > *maxStep {
		*maxStep = element.step
	}
	*que = append(*que, element)
	*freshCnt--
}
