package com.algorithmStudy;

import java.util.Scanner;

public class P8958 {
    public static void main(String[] args) {
        int comboCounter = 0, testCaseLen, res = 0;
        String input;
        Scanner scanner = new Scanner(System.in);

        testCaseLen = scanner.nextInt();

        for (int i = 0; i < testCaseLen; i++) {
            input = scanner.next();
            for (int q = 0; q < input.length(); q++) {
                if (input.charAt(q) == 'O') {
                    comboCounter++;
                } else {
                    comboCounter = 0;
                }
                res += comboCounter;
            }
            comboCounter = 0;
            System.out.println(res);
            res = 0;
        }
    }
}
