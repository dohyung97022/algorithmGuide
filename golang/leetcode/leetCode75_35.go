package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func goodNodes(root *TreeNode) int {
	// keep largest value in memory
	// create a function that has the goodCnt and node as variable
	// recursively check node by node
	// add 1 if the current node is "good"
	// return goodCnt

	goodCnt := 0
	addGood(&goodCnt, root, root.Val)
	return goodCnt
}

// bfs
func addGood(goodCnt *int, root *TreeNode, maxVal int) {
	if root.Val >= maxVal {
		*goodCnt++
		maxVal = root.Val
	}
	if root.Left != nil {
		addGood(goodCnt, root.Left, maxVal)
	}
	if root.Right != nil {
		addGood(goodCnt, root.Right, maxVal)
	}
}
