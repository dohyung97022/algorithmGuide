package com.algorithmStudy.백준fails;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class P17298 {
    public static void main(String[] args) {
        // DP 인가?

        // For loop 을 돕니다.
        // 해당 숫자를 Map 로 넣습니다.
        // 다음 숫자에서 Map 의 값들을 돌며 더 큰 값이 존재하는지 확인합니다.
        // 결과 어레이에 넣어놓습니다.

        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        Map<Integer, Boolean> m = new HashMap<>();
        int[] dp = new int[1000001];
        int[] a = new int[t];
        Arrays.fill(dp,-1);
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            a[i] = n;
            for (Integer v : m.keySet()) {
                if (n > v && !m.get(v)) {
                    dp[v] = n;
                    m.put(v, true);
                }
            }
            m.put(n, false);
        }
        StringBuilder sb = new StringBuilder();
        for (int i : a){
            sb.append(dp[i]).append(" ");
        }
        System.out.println(sb);
    }
}