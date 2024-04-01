package com.algorithmStudy.leetCode;

class P1768 {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder sb = new StringBuilder();
        int minLen = 0;
        int maxLen = 0;
        // get the minLen of the min word
        // for loop the minLen in order to add word1 and word2
        // for loop from minLen to maxLen to the word
        if (word1.length() > word2.length()) {
            minLen = word2.length();
            maxLen = word1.length();
        } else {
            minLen = word1.length();
            maxLen = word2.length();
        }

        for (int i = 0; i < maxLen; i++) {
            if (i < minLen) {
                sb.append(word1.charAt(i));
                sb.append(word2.charAt(i));
                continue;
            }
            if (word1.length() > word2.length()) {
                sb.append(word1.charAt(i));
            } else {
                sb.append(word2.charAt(i));
            }
        }
        return sb.toString();
    }
}