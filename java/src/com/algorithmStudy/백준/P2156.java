package com.algorithmStudy.백준;

import java.util.Scanner;
// 가정
// 점화식
// 1. n 번째 포도주를 마실 경우
// 1-1. n 번째 포도주 + n-1 번째 포도주 + n-3 번의 쵀대값
// 1-2. n 번째 포도주 + n-2 번의 최대값
// 1-3. n-1 번째 최대값

// DP
// maxWines 안에 이전의 max 값들 넣기
public class P2156 {
    public static int[] wines;
    public static Integer[] maxWines;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCase = scanner.nextInt();
        wines = new int[testCase + 1];
        maxWines = new Integer[testCase + 1];
        for (int i = 0; i < testCase; i++) {
            wines[i] = scanner.nextInt();
        }
        maxWines[0] = wines[0];
        System.out.println(maxWine(testCase));
    }

    public static int maxWine(int n) {
        if (n < 0)
            return 0;
        if (maxWines[n] == null) {
            // 1-1. n 번째 포도주 + n-1 번째 포도주 + n-3 번의 쵀대값
            int c = maxWine(n - 3) + wines[n - 1] + wines[n];
            // 1-2. n 번째 포도주 + n-2 번의 최대값
            int b = maxWine(n - 2) + wines[n];
            // 1-3. n-1 번째 최대값
            int a = maxWine(n - 1);

            maxWines[n] = Math.max(a, Math.max(b, c));
        }
        return maxWines[n];
    }
}

// 시간초과
// 변화 내용
// Integer[] 로 만들경우 == null 조건문을 사용할 수 있다.
