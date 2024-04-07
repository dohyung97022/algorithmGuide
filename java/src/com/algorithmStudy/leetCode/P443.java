package com.algorithmStudy.leetCode;

import java.util.ArrayList;
import java.util.List;

public class P443 {
    class Solution {
        public int compress(char[] chars) {
            // O(n)

            // assign value to memory
            char c = chars[0];
            int cnt=0;
            List<Character> ans = new ArrayList<>();

            // for loop to to assign
            for (int i=0; i<chars.length+1; i++) {
                if (i==0) {
                    c = chars[0];
                }
                if (i == chars.length || c != chars[i]) { // the value is not the same, or end of line
                    ans.add(c);
                    if (i != chars.length) {
                        c = chars[i];
                    }
                    if (cnt == 1) { // not print if size 1
                        continue;
                    }
                    for (char ch :String.valueOf(cnt).toCharArray()) {
                        ans.add(ch);
                    }
                    cnt = 1;
                } else if (c == chars[i]) { // if the value is same as c
                    cnt++;
                }
                // edge case
                // is the last index and a different character

            }

            for (int i=0; i<ans.size(); i++) {
                chars[i] = ans.get(i);
            }
            return ans.size();
        }
    }
}
