package com.algorithmStudy.leetCode;

public class P7 {
    class Solution {
        public int reverse(int x) {
            int y = 1;
            int z = 1;
            boolean negative = false;
            if (x < 0) {
                negative = true;
                x = x * -1;
            }
            while (x / y > 1) { // O(n)
                y = y * 10;
            }
            int sum = 0;
            while (y != 0) { // O(n)
                sum += z * ((x / y) % 10);
                z = z * 10;
                y = y / 10;
            }

            if (negative) {
                sum = sum * -1;
            }
            return sum;
        }
    }
}
