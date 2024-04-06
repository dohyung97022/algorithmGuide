package com.algorithmStudy.leetCode;

public class P605 {
    class Solution {
        public boolean canPlaceFlowers(int[] flowerbed, int n) {
            // logic O(n)
            // --> move until you have a spot with (0 0 0), (0, 0, end of line), (beginning, 0, end of line)
            // n-- and place the flower
            // keep moving
            // if n if 0 at the end return true
            // else return false

            // would there be any edge cases?
            // where we could be punished for thinking greedy?
            // what about the end of the line?
            // [1, 0, 1, 0, 0]
            // [0, 0, 1, 0, 0]

            for (int i=0; i<flowerbed.length; i++) {
                if ((i-1 < 0 || flowerbed[i-1] == 0) && // left is start or 0
                        (i+1>=flowerbed.length || flowerbed[i+1] == 0) && // right is end or 0
                        (flowerbed[i] == 0)) { // middle is zero
                    flowerbed[i] = 1;
                    n--;
                }
            }
            if (n > 0) {
                return false;
            }
            return true;
        }
    }
}
