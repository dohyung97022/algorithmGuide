package main

type CharInfo struct {
	locationY int
	locationX int
	steps     int
}

func nearestExit(maze [][]byte, entrance []int) int {
	// block entrance
	maze[entrance[0]][entrance[1]] = '+'

	// bfs approach
	queue := []CharInfo{}

	// character x,y, steps location as locationX, locationY
	queue = append(queue, CharInfo{locationY: entrance[0], locationX: entrance[1], steps: 0})

	// if que is not empty bsf as up right down left
	for len(queue) > 0 {
		charInfo := queue[0]
		charInfo.steps++
		queue = queue[1:]

		// up
		charInfo.locationY--
		if res := checkLocation(charInfo, &maze, &queue); res != -1 {
			return res
		}
		charInfo.locationY++
		// right
		charInfo.locationX++
		if res := checkLocation(charInfo, &maze, &queue); res != -1 {
			return res
		}
		charInfo.locationX--
		// down
		charInfo.locationY++
		if res := checkLocation(charInfo, &maze, &queue); res != -1 {
			return res
		}
		charInfo.locationY--
		// left
		charInfo.locationX--
		if res := checkLocation(charInfo, &maze, &queue); res != -1 {
			return res
		}
		charInfo.locationX++
	}
	// if the location is empty
	// put the location in the que

	// if the location is exit
	// return the steps taken

	// if the location is wall
	// continue

	// if the que is empty
	// return -1

	return -1
}

func checkLocation(charInfo CharInfo, maze *[][]byte, queue *[]CharInfo) int {
	if charInfo.locationY >= 0 && len(*maze) > charInfo.locationY && // is y within maze
		charInfo.locationX >= 0 && len((*maze)[0]) > charInfo.locationX && // is x within maze
		(*maze)[charInfo.locationY][charInfo.locationX] == '.' { // is an empty space

		if charInfo.locationY == 0 || charInfo.locationY == len(*maze)-1 || // is y at edge
			charInfo.locationX == 0 || charInfo.locationX == len((*maze)[0])-1 { // or is x at edge
			return charInfo.steps
		}
		(*maze)[charInfo.locationY][charInfo.locationX] = '+' // fill previous map
		*queue = append(*queue, charInfo)
	}
	return -1
}
