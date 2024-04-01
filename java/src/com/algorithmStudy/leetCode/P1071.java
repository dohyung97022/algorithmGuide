package com.algorithmStudy.leetCode;

class P1071 {
    public String gcdOfStrings(String str1, String str2) {
        // find the shorter string
        // for loop the shorter to the longer but from incrementing characters of the shorter string
        // ex) str1 abcabc str2 abc, 1. a cannot loop str1, ab cannot loop str1, abc can loop str1.
        // answer abc
        boolean isStr1Shorter = false;
        if (str1.length() < str2.length()) {
            isStr1Shorter = true;
        }
        int i = 1;
        String dividor = "";
        while (true) {
            if (isStr1Shorter && isADividableByB(str2, str1.substring(0, i)) && isADividableByB(str1, str1.substring(0, i))) {
                dividor = str1.substring(0, i);
            }
            else if (!isStr1Shorter && isADividableByB(str1, str2.substring(0, i)) && isADividableByB(str2, str2.substring(0, i))) {
                dividor = str2.substring(0, i);
            }
            if (isStr1Shorter && i == str1.length()) {
                break;
            } else if (!isStr1Shorter && i == str2.length()) {
                break;
            }
            i++;
        }
        return dividor;
    }

    public boolean isADividableByB(String a, String b) {
        if (b.length() == 0) {
            return false;
        }
        int bi = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(bi)) {
                return false;
            }
            bi++;
            if (bi == b.length()) {
                bi = 0;
            }
        }
        if (bi == 0) {
            return true;
        } else {
            return false;
        }
    }
}