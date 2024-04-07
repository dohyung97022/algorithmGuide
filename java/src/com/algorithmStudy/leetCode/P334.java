package com.algorithmStudy.leetCode;

public class P334 {
    class Solution {
        public boolean increasingTriplet(int[] nums) {
            // create two arrays that has a lowest number from the previous iteration
            // left array has lowest
            // right array will save the lowest while a inversed for loop

            // O(1)
            int[] left = new int[nums.length];
            int[] right = new int[nums.length];

            // O(n)
            left[0] = nums[0];
            for (int i=1; i<nums.length; i++) {
                if (nums[i] < left[i-1]) {
                    left[i] = nums[i];
                } else {
                    left[i] = left[i-1];
                }
            }
            // O(n)
            right[nums.length-1] = nums[nums.length-1];
            for (int i=nums.length-2; i>=0; i--) {
                if (nums[i] > right[i+1]) {
                    right[i] = nums[i];
                } else {
                    right[i] = right[i+1];
                }
            }
            // O(n)
            for (int i=1; i<nums.length-1; i++) {
                if (left[i-1] < nums[i] && nums[i] < right[i+1]) {
                    return true;
                }
            }

            return false;
        }
        // failed logic
        // public boolean increasingTriplet(int[] nums) {

        //     // logic
        //     // O(n)
        //     int i=Integer.MAX_VALUE;
        //     int j=Integer.MAX_VALUE;
        //     int k=Integer.MAX_VALUE;
        //     for (int l=0; l<nums.length; l++) {
        //         // puts a number in i
        //         // if i is already set and the number is lower than i
        //         // replace all i,j,k and palce the number in i
        //         // if in order
        //         // go to the next number j
        //         // and to the next number k repeating this logic
        //         // if all i,j,k is set, return true
        //         // [1, 2, 1, 2, 3]
        //         if (nums[l]<=i) {
        //             i = nums[l];
        //             j = Integer.MAX_VALUE;
        //             k = Integer.MAX_VALUE;
        //         } else if (nums[l]<=j) {
        //             j = nums[l];
        //             k = Integer.MAX_VALUE;
        //         } else if (nums[l]<=k) {
        //             k = nums[l];
        //             return true;
        //         }
        //         System.out.print(i);
        //         System.out.print(",");
        //         System.out.print(j);
        //         System.out.print(",");
        //         System.out.print(k);
        //         System.out.print("\n");
        //     }
        //     return false;
        // }
    }
}
