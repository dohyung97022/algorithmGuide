package com.algorithmStudy.leetCode;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;

public class P345 {
    class Solution {
        public String reverseVowels(String s) {
            // O(2n)
            // for loop the string
            // find and save all the vowels and the index in a separate array
            // reverse for the string and reverse insert
            // do I use a string builder?
            // a string is a fixed and a immutable datatype so editing again and again is a waste of resource
            Set<Character> vowels = Set.of('a', 'e', 'i', 'o', 'u');
            List<Character> foundVowels = new ArrayList<>();
            StringBuilder sb = new StringBuilder();
            for (int i=0; i<s.length(); i++) {
                if (vowels.contains(Character.toLowerCase(s.charAt(i)))) {
                    foundVowels.add(s.charAt(i));
                }
            }
            int j = foundVowels.size()-1;
            for (int i=0; i<s.length(); i++) {
                if (vowels.contains(Character.toLowerCase(s.charAt(i)))) {
                    sb.append(foundVowels.get(j));
                    j--;
                } else {
                    sb.append(s.charAt(i));
                }
            }
            return sb.toString();
        }
    }
}
