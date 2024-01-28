package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func maxLevelSum(root *TreeNode) int {
	// create a struct with a level variable
	// create a variable of maxSum
	// current level, currentLevelSum

	queue := []*TreeNode{root}
	levelQueue := []int{1}
	maxSum := root.Val
	curLevelSum := 0
	maxLevel := 1
	curLevel := 1

	bfs(&queue, &levelQueue, &curLevelSum, &maxSum, &curLevel, &maxLevel)
	return maxLevel
}

func bfs(
	queue *[]*TreeNode, levelQueue *[]int, curLevelSum *int, maxSum *int, curLevel *int, maxLevel *int) {
	if len(*queue) == 0 {
		if *maxSum < *curLevelSum {
			*maxSum = *curLevelSum
			*maxLevel = *curLevel
		}
		return
	}

	node := (*queue)[0]
	level := (*levelQueue)[0]
	*queue = (*queue)[1:]
	*levelQueue = (*levelQueue)[1:]

	if level != *curLevel {
		if *maxSum < *curLevelSum {
			*maxSum = *curLevelSum
			*maxLevel = *curLevel
		}
		*curLevel = level
		*curLevelSum = 0
	}

	*curLevelSum += node.Val

	if node.Right != nil {
		*queue = append(*queue, node.Right)
		*levelQueue = append(*levelQueue, level+1)
	}
	if node.Left != nil {
		*queue = append(*queue, node.Left)
		*levelQueue = append(*levelQueue, level+1)
	}
	bfs(queue, levelQueue, curLevelSum, maxSum, curLevel, maxLevel)
}

// a different approach
// this way, has better runtime and memory
// this approach saves and tracks the level by curQue and nextQue

func maxLevelSumV2(root *TreeNode) int {
	// create a struct with a level variable
	// create a variable of maxSum
	// current level, currentLevelSum

	curQue := []*TreeNode{root}
	nextQue := []*TreeNode{}
	maxSum := root.Val
	curSum := root.Val
	maxLevel := 1
	curLevel := 1

	bfs(&curQue, &nextQue, &curSum, &maxSum, &maxLevel, &curLevel)
	return maxLevel
}

func bfsV2(
	curQue *[]*TreeNode, nextQue *[]*TreeNode, curSum *int, maxSum *int, maxLevel *int, curLevel *int) {
	// when curQue is finished
	if len(*curQue) == 0 {
		// check if curSum is higher
		if *maxSum < *curSum {
			*maxSum = *curSum
			*maxLevel = *curLevel
		}
		if len(*nextQue) == 0 {
			return
		}
		*curSum = 0
		*curLevel++
		*curQue = *nextQue
		*nextQue = []*TreeNode{}
	}

	*curSum += (*curQue)[0].Val
	if (*curQue)[0].Right != nil {
		*nextQue = append(*nextQue, (*curQue)[0].Right)
	}
	if (*curQue)[0].Left != nil {
		*nextQue = append(*nextQue, (*curQue)[0].Left)
	}
	*curQue = (*curQue)[1:]

	bfs(curQue, nextQue, curSum, maxSum, maxLevel, curLevel)
}

// third approach
// this way, I for loop the curQue itself.
// removed the nextQue

func maxLevelSumV3(root *TreeNode) int {
	curQue := []*TreeNode{root}
	maxSum := root.Val
	curSum := root.Val
	maxLevel := 1
	curLevel := 1

	bfs(&curQue, &curSum, &maxSum, &maxLevel, &curLevel)
	return maxLevel
}

func bfsV3(curQue *[]*TreeNode, curSum *int, maxSum *int, maxLevel *int, curLevel *int) {
	nextQue := []*TreeNode{}
	*curSum = 0
	for _, node := range *curQue {
		*curSum += node.Val
		if node.Right != nil {
			nextQue = append(nextQue, node.Right)
		}
		if node.Left != nil {
			nextQue = append(nextQue, node.Left)
		}
	}

	// check if curSum is higher
	if *maxSum < *curSum {
		*maxSum = *curSum
		*maxLevel = *curLevel
	}
	*curLevel++

	if len(nextQue) != 0 {
		bfs(&nextQue, curSum, maxSum, maxLevel, curLevel)
	}
}
