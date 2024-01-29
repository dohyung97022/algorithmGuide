package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func searchBST(root *TreeNode, val int) *TreeNode {
	// simple enough
	return bfs(root, &val)
}

func bfs(node *TreeNode, val *int) *TreeNode {
	if node == nil {
		return nil
	} else if node.Val == *val {
		return node
	} else if *val < node.Val {
		return bfs(node.Left, val)
	} else {
		return bfs(node.Right, val)
	}
}
