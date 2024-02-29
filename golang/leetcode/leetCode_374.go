package main

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * func guess(num int) int;
 */

func guessNumber(n int) int {
	// how I would do it?
	// 0 ~ 100
	// guess 50
	// -1 : 0 ~ 50
	// 1 : 50 ~ 100
	// 0 : return 50
	// repeat

	// logic
	// create start, end int
	// guess the middle of start ~ end.
	// set start and end accordingly.

	// edge case
	// 1, 2, 3, 4, middle : 2
	// 1, 2, 3, 4, 5, middle : 3
	// 1, 2, middle : 1
	// no problemo

	// 1, 1, 2
	// solved with res == 1 && start == middle
	// if it tells you that it is in the right, and the start and middle is the same,
	// return the end

	start := 1
	end := n
	middle := int((start + end) / 2)
	res := -1

	for res != 0 {
		res := guess(middle)
		if res == -1 {
			end = middle
			middle = (start + end) / 2
		} else if res == 1 && start == middle {
			return end
		} else if res == 1 {
			start = middle
			middle = (start + end) / 2
		} else {
			return middle
		}
	}
	return middle
}
