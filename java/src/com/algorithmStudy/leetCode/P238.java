package com.algorithmStudy.leetCode;

public class P238 {
    class Solution {
        public int[] productExceptSelf(int[] nums) {
            // there can be an approach in such that the logic can be simplified
            // it feels like there could be a left multiplier and a right multiplier

            // assumtion and thoughts
            // what happens if I start at the biggining
            // what happens if I start at the middle
            // what happens if I start at the end
            // [1, 2, 3, 4, 5, 6, 7]
            // [left, i, right]
            // [left*i, i+1, right/i]
            //

            // logic (O(n))
            //
            int left = 1;
            int right = 1;
            for (int i = 1; i < nums.length; i++) {
                right = right * nums[i];
            }
            int[] res = new int[nums.length];
            for (int i = 0; i < nums.length; i++) {
                res[i] = left * right;
                left = left * nums[i];
                if (i + 1 < nums.length && nums[i + 1] == 0) {
                    right = 0;
                } else if (i + 1 < nums.length && nums[i + 1] != 0) {
                    right = right / nums[i + 1];
                }
            }
            return res;
        }
    }
}
