package com.algorithmStudy.leetCode;

public class P43 {
    class Solution {
        public String multiply(String num1, String num2) {
            // constraints
            // cannot be converted to integer directly


            // failed attempt
            // the results overflow from Long
            // Long ans = 0L;
            // for (int i=0; i<num1.length(); i++) {
            //     for (int j=0; j<num2.length(); j++) {
            //         ans += Character.getNumericValue(num2.charAt(j)) * Character.getNumericValue(num1.charAt(i)) * (long)Math.pow(10, num2.length() - 1 - j) * (long)Math.pow(10, num1.length() -1 - i);
            //     }
            // }
            // return String.valueOf(ans);

            // thoughts
            // if the types in java cannot hold the multiplycation
            // we can create a array of a specific type in order to save such values
            // but can a index in a array be bigger than long?
            // but does the index itself have to be the number itself?
            // instead of 10, we can do 2?
            // 1 -> 1 10 -> 2 100 -> 3 ... etc
            // if a number is equal or exceeds 10, it is added to the second index
            // the process is repeated to the end
            // maybe sending to the second index should be done after the values are set.
            // that sould be faster in my opinion.

            // edge case
            // multiplied by 0

            // time complexity = O(n^2+3n) = O(n^2)
            if (num1.length() == 1 && num1.charAt(0) == '0' ||
                    num2.length() == 1 && num2.charAt(0) == '0') {
                return "0";
            }

            int[] saved = new int[num1.length() + num2.length()];
            for (int i = 0; i < num1.length(); i++) { // O(n)
                for (int j = 0; j < num2.length(); j++) {  // O(n^2)
                    saved[j + i] += Character.getNumericValue(num1.charAt(num1.length() - 1 - i)) * Character.getNumericValue(num2.charAt(num2.length() - 1 - j));
                }
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < num1.length() + num2.length(); i++) { // O(2n)
                if (i != num1.length() + num2.length() - 1) { // if not the last index
                    if (saved[i] >= 10) { // and lower than 10
                        saved[i + 1] += saved[i] / 10;
                        saved[i] = saved[i] % 10;
                    }
                } else if (saved[i] == 0) { // if last index, and is 0
                    continue;
                }
                sb.append(saved[i]);
            }
            return sb.reverse().toString(); // O(2n)
        }
    }
}
