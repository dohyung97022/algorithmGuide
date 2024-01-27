package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var answer *TreeNode

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	// create a function that checks if it as p or q
	// the function is recursive so if the deeper function returns that it has p or q it will be returned to the
	// upper level that it has p or q
	// if the function returns as to have both p and q, it will save it as the answer if the answer does not exist.
	// if the answer already exists, it should not be tampered as it is the lowest level of ancestors.
	answer = nil
	checkContains(root, p, q)
	return answer
}

func checkContains(node, p, q *TreeNode) (bool, bool) {
	// return if answer is already found
	if answer != nil {
		return false, false
	}
	var containsP, containsQ, recContainsP, recContainsQ bool
	// check left
	if node.Left != nil {
		recContainsP, recContainsQ = checkContains(node.Left, p, q)
		if node.Left == p || recContainsP {
			containsP = true
		} else if node.Left == q || recContainsQ {
			containsQ = true
		}
	}
	// check right
	if node.Right != nil {
		recContainsP, recContainsQ = checkContains(node.Right, p, q)
		if node.Right == p || recContainsP {
			containsP = true
		} else if node.Right == q || recContainsQ {
			containsQ = true
		}
	}
	// check self
	if node == p {
		containsP = true
	} else if node == q {
		containsQ = true
	}

	if answer == nil && containsP == true && containsQ == true {
		answer = node
	}

	return containsP, containsQ
}
