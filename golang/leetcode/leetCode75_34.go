package main

import "reflect"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	// approach recursive
	// search from the left to right
	// recursive return if it has hit the end
	// pointer to an array in order to keep the leaf nodes in order
	arr := []int{}
	fillArray(&arr, root1)
	arr2 := []int{}
	fillArray(&arr2, root2)
	return reflect.DeepEqual(arr, arr2)
}

func fillArray(arr *[]int, node *TreeNode) {
	if node == nil {
		return
	}
	// check left and right
	fillArray(arr, node.Left)
	fillArray(arr, node.Right)
	if node.Left == nil && node.Right == nil {
		*arr = append(*arr, node.Val)
	}
}
