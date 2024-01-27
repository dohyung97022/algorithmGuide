package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func longestZigZag(root *TreeNode) int {
	// if the mother node is read from right, its child does not need to read left
	// same applies of left mother to right child

	// do we need to go recursive? bfs?
	// if we do it recursive, we can send in two integers to add up to right and left.
	// or we can just send if the parent was from the left or right by a boolean
	// but what if the node is a root?
	// we can just send the parent node address as a parameter and check where it was sent from

	// can we go dfs?

	// bfs seems much more of the simple approach.
	// dfs can lead to excessive memory use and unnessaceary search.
	maxDepth := 0
	bfs(root, nil, 0, &maxDepth)
	return maxDepth
}

func bfs(node *TreeNode, parentNode *TreeNode, parentDepth int, maxDepth *int) {
	if parentDepth > *maxDepth {
		*maxDepth = parentDepth
	}
	if node.Right != nil {
		if parentNode != nil && parentNode.Left == node {
			bfs(node.Right, node, parentDepth+1, maxDepth)
		} else {
			bfs(node.Right, node, 1, maxDepth)
		}
	}
	if node.Left != nil {
		if parentNode != nil && parentNode.Right == node {
			bfs(node.Left, node, parentDepth+1, maxDepth)
		} else {
			bfs(node.Left, node, 1, maxDepth)
		}
	}
}
