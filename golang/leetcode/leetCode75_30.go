package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {
	// If I connect 1 and 3
	// the 2.Next would still have the 3
	// so you can connect 2.Next.Next(4) to 2.Next
	// keep the 2
	// connect the end of the odd loop with 2
	var pointer *ListNode = head
	var firstEvenHead *ListNode = nil
	if head == nil || head.Next == nil {
		return head
	} else {
		firstEvenHead = head.Next
	}
	for true {
		nextHead := pointer.Next
		if pointer.Next != nil {
			pointer.Next = pointer.Next.Next
		}
		if nextHead != nil {
			if nextHead.Next != nil && nextHead.Next.Next != nil {
				nextHead.Next = nextHead.Next.Next
			} else {
				nextHead.Next = nil
			}
		}
		if pointer.Next == nil {
			break
		}
		pointer = pointer.Next
	}
	pointer.Next = firstEvenHead
	return head
}
