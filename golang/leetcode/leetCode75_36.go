package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pathSum(root *TreeNode, targetSum int) int {
	// create a function that recieves a *TreeNode, targetSum(*int), and an array of int
	// check left and right node and for loop through the array in order to find if the sum is equal to the target
	// the array should contain the current nodes value, and sum of each array with the current nodes value
	cnt := 0
	checkSum(root, &targetSum, []int{}, &cnt)
	return cnt
}

func checkSum(node *TreeNode, targetSum *int, previousSums []int, cnt *int) {
	if node == nil {
		return
	}
	newSums := []int{}
	for _, val := range previousSums {
		newSums = append(newSums, val+node.Val)
		if val+node.Val == *targetSum {
			*cnt++
		}
	}
	newSums = append(newSums, node.Val)
	if node.Val == *targetSum {
		*cnt++
	}
	checkSum(node.Left, targetSum, newSums, cnt)
	checkSum(node.Right, targetSum, newSums, cnt)
}

// TODO : redo this question
// try to reduce the memory with []int -> []*TreeNode
// addresses consumes lesser memory than integers

func pathSumV2(root *TreeNode, targetSum int) int {
	// create a function that recieves a *TreeNode, targetSum(*int), and an array of int
	// check left and right node and for loop through the array in order to find if the sum is equal to the target
	// the array should contain the current nodes value, and sum of each array with the current nodes value
	cnt := 0
	if root != nil {
		checkSum(root, &targetSum, []*TreeNode{root}, &cnt)
	}
	return cnt
}

func checkSumV2(node *TreeNode, targetSum *int, prevNodes []*TreeNode, cnt *int) {
	tmp := 0
	for i := len(prevNodes) - 1; i >= 0; i-- {
		tmp += prevNodes[i].Val
		if tmp == *targetSum {
			*cnt++
		}
	}

	if node.Left != nil {
		prevNodes = append(prevNodes, node.Left)
		checkSum(node.Left, targetSum, prevNodes, cnt)
		prevNodes = prevNodes[:len(prevNodes)-1]
	}
	if node.Right != nil {
		prevNodes = append(prevNodes, node.Right)
		checkSum(node.Right, targetSum, prevNodes, cnt)
		prevNodes = prevNodes[:len(prevNodes)-1]
	}
}
