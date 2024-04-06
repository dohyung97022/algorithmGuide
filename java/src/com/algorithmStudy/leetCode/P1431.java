package com.algorithmStudy.leetCode;

import java.util.ArrayList;
import java.util.List;

public class P1431 {
    class Solution {
        public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
            // O(2n)
            // for loop twice
            // for loop to find the biggest number
            // for loop to find if the number is extraCandies away from the biggest number
            int max = 0;
            for (int i=0; i<candies.length; i++) {
                if (candies[i] > max) {
                    max = candies[i];
                }
            }
            List<Boolean> ans = new ArrayList<Boolean>(candies.length);
            for (int i=0; i<candies.length; i++) {
                Boolean larger = false;
                if (max - extraCandies <= candies[i]) {
                    larger = true;
                }
                ans.add(larger);
            }
            return ans;
        }
    }
}
