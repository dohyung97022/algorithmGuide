package com.algorithmStudy.leetCode;

public class P2 {
    /**
     * Definition for singly-linked list.
     * public class ListNode {
     * int val;
     * ListNode next;
     * ListNode() {}
     * ListNode(int val) { this.val = val; }
     * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
     * }
     */
    class Solution {
        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            // add both values in the list nodes
            // if the value surpasses 10, push over the 10 as 1 and leave the %
            // O(n)
            ListNode ans = new ListNode();
            ListNode node = ans;
            int overflow = 0;
            while (l1 != null || l2 != null) {
                int val = overflow;
                if (l1 != null) {
                    val += l1.val;
                    l1 = l1.next;
                }
                if (l2 != null) {
                    val += l2.val;
                    l2 = l2.next;
                }
                overflow = val / 10;
                int leftover = val % 10;
                node.val = leftover;
                if (l1 != null && l2 != null) {
                    node.next = new ListNode();
                    node = node.next;
                }
            }
            return ans;
        }
    }
}
