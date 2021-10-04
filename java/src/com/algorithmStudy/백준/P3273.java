package com.algorithmStudy.백준;

import java.util.Arrays;
import java.util.Scanner;

public class P3273 {
    public static void main(String[] args) {
        // 가정
        // 수열을 받는다.
        // 정렬을 한다.
        // 가장 작은 인덱스와 가장 큰 인덱스를 마킹한다.
        // 합을 구하면서 작으면 작은 인덱스를 늘린다.
        // 합을 구하면서 크면 큰 인덱스를 늘린다.

        Scanner scanner = new Scanner(System.in);
        int testCase = scanner.nextInt();
        int[] array = new int[testCase];
        for (int i = 0; i < testCase; i++) {
            array[i] = scanner.nextInt();
        }
        Arrays.sort(array);
        int wantedSum = scanner.nextInt();
        int start = 0;
        int end = testCase - 1;
        int cnt = 0;
        while (start < end) {
            int sum = array[start] + array[end];
            if (sum == wantedSum) {
                cnt++;
                end -= 1;
                start++;
            }
            if (sum > wantedSum)
                end -= 1;
            if (sum < wantedSum)
                start++;
        }
        System.out.println(cnt);
    }
}