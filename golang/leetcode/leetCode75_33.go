package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// depth first
func maxDepth(root *TreeNode) int {
	// recursive
	return checkDepth(0, root)
}

func checkDepth(level int, node *TreeNode) int {
	// if the given node is nil, it will return the leaf level
	if node == nil {
		return level
	}
	level++
	leftDepth := checkDepth(level, node.Left)
	rightDepth := checkDepth(level, node.Right)
	// compare each node and return the higher
	if leftDepth > rightDepth {
		return leftDepth
	}
	return rightDepth
}
