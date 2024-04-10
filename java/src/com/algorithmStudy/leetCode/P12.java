package com.algorithmStudy.leetCode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class P12 {
    class Solution {
// I             1
// IV            4
// V             5
// IX            9
// X             10
// XL            40
// L             50
// XC            90
// C             100
// CD            400
// D             500
// CM            900
// M             1000

//
// can we be greedy and place with the biggest number to the smallest?
// ex) 3915
// thoughts
// get the highest diget number = 3000
// add MMM to the string builder
// get the second highest diget number = 900
// is the only addable number 1, 10, 100? No, We can add whatever that comes for the biggest
// Can we add numbers like XL, XC? maybe?

        class RomanNumber {
            String character;
            Integer number;

            public RomanNumber(String character, Integer number) {
                this.character = character;
                this.number = number;
            }
        }

        public String intToRoman(int num) {
            List<RomanNumber> numbers = new ArrayList<>(Arrays.asList(
                    new RomanNumber("M", 1000),
                    new RomanNumber("CM", 900),
                    new RomanNumber("D", 500),
                    new RomanNumber("CD", 400),
                    new RomanNumber("C", 100),
                    new RomanNumber("XC", 90),
                    new RomanNumber("L", 50),
                    new RomanNumber("XL", 40),
                    new RomanNumber("X", 10),
                    new RomanNumber("IX", 9),
                    new RomanNumber("V", 5),
                    new RomanNumber("IV", 4),
                    new RomanNumber("I", 1)
            ));
            StringBuilder sb = new StringBuilder();
            for (RomanNumber n : numbers) { // O(1)
                while (n.number <= num) { // O(n)
                    num -= n.number;
                    sb.append(n.character);
                }
            }

            return sb.toString();
        }
    }
}
