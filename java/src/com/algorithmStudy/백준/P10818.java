package com.algorithmStudy.백준;

import java.util.Scanner;

// edge case
// 1. 주어지는 정수가 -1,000,000 일 때
// 2. 주어지는 정수가 1,000,000 일 때
// 3. 처음 주어지는 정수가 1 일 때
// 4. 처음 주어지는 정수가 1,000,000 일 때

public class P10818 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int input, inputLen, min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        inputLen = scanner.nextInt();

        for (int i = 0; i < inputLen; i++) {
            input = scanner.nextInt();
            if (input < min) min = input;
            if (input > max) max = input;
        }

        System.out.println(min + " " + max);
    }
}