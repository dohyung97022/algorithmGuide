package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func rightSideView(root *TreeNode) []int {
	// seems easy enough
	result := []int{}
	if root == nil {
		return result
	}
	saveRightVals(root, &result, 0)
	return result
}

func saveRightVals(root *TreeNode, result *[]int, level int) {
	// no right most element is set
	if len(*result) == level {
		*result = append(*result, root.Val)
	}

	if root.Right != nil {
		saveRightVals(root.Right, result, level+1)
	}
	if root.Left != nil {
		saveRightVals(root.Left, result, level+1)
	}
}
