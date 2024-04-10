package com.algorithmStudy.leetCode;

public class P29 {
    class Solution {
        // thoughts
        // if we cannot use *, /, %
        // we can only use +, -, >, <

        // logic
        // division is just subtracting the element n times
        // how much can we subtract a number until the remain is lesser than 0
        // this way we can just return the truncated number

        // ex) 7, 2
        // 7 - 2 = 5 (ans++)
        // 5 - 2 = 3 (ans++)
        // 3 - 2 = 1 (ans++)
        // 1 - 2 = -1
        // return 3

        // edge cases
        // dividend = 0
        //
        public int divide(int dividend, int divisor) {
            float dividendF = (float) dividend;
            float divisorF = (float) divisor;

            int ans = 0;
            boolean reversed = false;
            if (dividendF == 0) {
                return 0;
            }
            if (divisorF < 0 && dividendF > 0 || divisorF > 0 && dividendF < 0) {
                reversed = true;
            }
            if (divisorF < 0) {
                divisorF = divisorF * -1;
            }
            if (dividendF < 0) {
                dividendF = dividendF * -1;
            }
            while (dividendF > 0 && dividendF >= divisorF) {
                dividendF -= divisorF;
                ans++;
            }
            if (reversed) {
                ans *= -1;
            }
            return ans;
        }
    }
}
