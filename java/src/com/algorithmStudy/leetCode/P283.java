package com.algorithmStudy.leetCode;

public class P283 {
    class Solution {
        public void moveZeroes(int[] nums) {
            // thoughts
            // simple pointer problem

            // methods
            // single pointer method
            // have a single pointer that moves to the right
            // keep pushing 0 to the right and for loop repeat
            // this could be a O(n^2)

            // double pointer method
            // have two pointers that moves to the right
            // the first pointer is followed with the second pointer
            // the first checks if it is > 0, and the second pointer checks if it is 0
            // if the condition is met, exchange the pointers
            // if not move the pointers to the right
            // but the second pointer must move only if it is not a 0 until it finds a 0
            // and the first pointer must keep moving if it is a 0 until it finds a x>0
            // O(2n)

            // ex
            // [0 (pointer), 1 (pointer), 0, 3, 12]
            // [1 (pointer), 0 (pointer), 0, 3, 12] exchanged
            // [1, 0(pointer), 0, 3(pointer), 12] moved
            // [1, 3(pointer), 0, 0(pointer), 12] exchanged
            // [1, 3, 0(pointer), 0, 12([pointer])] moved
            // [1, 3, 12(pointer), 0, 0([pointer])] exchanged

            int p1 = 0;
            int p2 = 1;
            int tmp = 0;
            while (p2 < nums.length) {
                if (nums[p1] == 0 && nums[p2] != 0 && p1 < p2) {
                    tmp = nums[p1];
                    nums[p1] = nums[p2];
                    nums[p2] = tmp;
                }

                if (nums[p1] != 0) {
                    p1++;
                    if (p1 == nums.length) {
                        break;
                    }
                }

                p2++;
            }
        }
    }
}
