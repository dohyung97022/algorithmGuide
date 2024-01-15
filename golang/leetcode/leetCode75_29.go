package main

import (
	"fmt"
	"math"
)

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteMiddle(head *ListNode) *ListNode {
	var listNodes []*ListNode
	fmt.Println(head.Next)
	for head != nil {
		listNodes = append(listNodes, head)
		head = head.Next
	}
	if len(listNodes) == 1 {
		return head
	}

	midIndex := int(math.Ceil(float64(len(listNodes)) / float64(2)))
	// we always have the previous index
	// if we do have the previous index and the next index
	// if we do have the previous index and no next index
	previousNode := listNodes[midIndex-1]
	previousNode.Next = nil
	if midIndex+1 <= len(listNodes)-1 {
		previousNode.Next = listNodes[midIndex+1]
	}
	return listNodes[0]
}

func main() {
	head := ListNode{Val: 2, Next: &ListNode{Val: 1}}
	fmt.Println(deleteMiddle(&head))
}

// we can try the fast and slow pointer method
