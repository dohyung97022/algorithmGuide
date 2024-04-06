package com.algorithmStudy.leetCode;

import java.util.ArrayList;
import java.util.List;

public class P151 {
    class Solution {
        public String reverseWords(String s) {
            s = s.trim();
            String[] list = s.split(" ");
            List<String> trimList = new ArrayList<>();
            for (int i=0; i<list.length; i++) {
                list[i] = list[i].trim();
                if (list[i] != "") {
                    trimList.add(list[i]);
                }
            }
            StringBuilder sb = new StringBuilder();
            for (int i=trimList.size()-1; i>=0; i--) {
                sb.append(trimList.get(i));
                if (i != 0) {
                    sb.append(" ");
                }
            }
            return sb.toString();
        }
    }
}
