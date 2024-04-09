package com.algorithmStudy.leetCode;

public class P9 {
    class Solution {
        public boolean isPalindrome(int x) {
            if (x < 0) {
                return false;
            }
            if (x < 10) {
                return true;
            }
            long a = 1;
            while (x / a > 0) { // O(n)
                a = a * 10;
            }
            a = a / 10;
            long b = 1;
            // two pointer but with integers
            while (a != b && a > b) { // O(n/2) = O(n)
                if ((x / b) % 10 != (x / a) % 10) {
                    return false;
                }
                a = a / 10;
                b = b * 10;
            }
            if (a > b) {
                return false;
            }
            return true;
        }
    }
}
