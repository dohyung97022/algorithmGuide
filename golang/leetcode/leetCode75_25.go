package main

func asteroidCollision(asteroids []int) []int {
	// for loop asteroids
	// add the i into a stack
	// collision logic
	// only if peek() is a + and i is a - they collide
	// if the abs values are equal they both get destroyed
	// if a abs value is higher, the lower value is destroyed
	// redo the collision logic until they do not collide
	// return the array if loop is complete

	var astStack []int
	for i := 0; i < len(asteroids); {
		// only if peek() is a + and i is a - they collide
		if !(len(astStack) > 0 && astStack[len(astStack)-1] > 0 && asteroids[i] < 0) {
			astStack = append(astStack, asteroids[i])
			i++
		} else if abs(astStack[len(astStack)-1]) == abs(asteroids[i]) {
			// if the abs values are equal they both get destroyed
			astStack = astStack[:len(astStack)-1]
			i++
		} else if abs(astStack[len(astStack)-1]) > abs(asteroids[i]) {
			// right value is destroyed
			i++
		} else if abs(astStack[len(astStack)-1]) < abs(asteroids[i]) {
			// left value is destroyed
			astStack = astStack[:len(astStack)-1]
			// needs to keep checking
		}
	}
	return astStack
}

func abs(num int) int {
	if num > 0 {
		return num
	} else {
		return -num
	}
}
