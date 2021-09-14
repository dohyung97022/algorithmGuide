package com.algorithmStudy.백준fails;

import java.util.Scanner;

public class P11053 {
    // dp 안에는 이전 a[] 들의 순차 부분수열 중 가장 긴 값이 들어가 있다.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        int max = 0;
        int[] a = new int[t];
        int[] dp = new int[t];
        for (int i = 0; i < t; i++) {
            a[i] = scanner.nextInt();
        }

        for (int i = 0; i < t; i++) {
            int min = 0;
            for (int j = 0; j < i; j++) {
                if (a[j] < a[i])
                    if (dp[j] > min)
                        min = dp[j];
            }
            dp[i] = min + 1;
            if (max < dp[i])
                max = dp[i];
        }
        System.out.println(max);
    }
}