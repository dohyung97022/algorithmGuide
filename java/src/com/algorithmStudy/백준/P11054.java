package com.algorithmStudy.백준;

import java.util.Scanner;

public class P11054 {
    // 모든 인덱스마다 증가폭의 길이와 감소폭의 길이를 저장한다.
    // 다음 인덱스로 넘어가면 이전 인덱스들의 DP 최대 길이를 이용하여 ++ 한다.
    // 다음 증가폭과 감소폭을 측정한다.
    // 증가폭의 경우 순방향, 감소폭의 경우 역방향으로 이동한다.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int test = scanner.nextInt();
        int[] a = new int[test];
        int[] dpUp = new int[test];
        int[] dpDw = new int[test];
        int longest = 1;
        for (int i = 0; i < test; i++) {
            a[i] = scanner.nextInt();
        }
        // 순방향
        for (int i = 0; i < test; i++) {
            int max = 0;
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j])
                    if (dpUp[j] > max)
                        max = dpUp[j];
            }
            dpUp[i] = max + 1;
        }
        // 역방향
        for (int i = test-1; i >= 0; i--) {
            int max = 0;
            for (int j = test-1; j >= i; j--) {
                if (a[i] > a[j])
                    if (dpDw[j] > max)
                        max = dpDw[j];
            }
            dpDw[i] = max + 1;

            if (longest < (dpUp[i] + dpDw[i]))
                longest = dpUp[i] + dpDw[i];
        }
        System.out.println(longest - 1);
    }
}