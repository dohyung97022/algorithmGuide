package main

func reverseList(head *ListNode) *ListNode {
	// head should not be manipulated
	// set pointer cur, next, prev

	var cur, next, prev *ListNode
	cur = head
	if cur != nil && cur.Next != nil {
		next = cur.Next
	}
	for next != nil {
		// move pointer values
		prev = cur
		cur = next
		next = cur.Next
		// the cur must be manipulated
		cur.Next = prev
		// error happens because both is a pointer
		// next is also changed because it is a pointer
	}
	return cur
}

func reverseList2(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	// lets think of a variable approach
	// head is the pointer that will move
	// if the prev is available it should be the head.Next
	var prev ListNode
	var next ListNode
	if head.Next != nil {
		next = *head.Next
	}
	for true {
		// head.Next = &prev
		prev = *head
		head = head.Next
		if next.Next != nil {
			next = *next.Next
		}
		if head.Next == nil {
			break
		}
	}
	return head
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList3(head *ListNode) *ListNode {
	if head == nil {
		return head
	}
	var prevPrev *ListNode
	var prev *ListNode
	for head != nil {
		prevPrev = prev
		prev = head
		head = head.Next
		prev.Next = prevPrev
	}
	return prev
}

func main() {
	head := ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3, Next: &ListNode{Val: 4, Next: &ListNode{Val: 5}}}}}
	reverseList2(&head)
}
