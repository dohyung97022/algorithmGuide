package com.algorithmStudy.백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P10989 {
    public static void main(String[] args) throws IOException {

        // 부족했던 점
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // 속도가 Scanner 보다 빠르다.

        // 카운팅 정렬
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCaseLen = Integer.parseInt(br.readLine());
        int[] intArry = new int[10001];
        for (int i = 0; i < testCaseLen; i++) {
            intArry[Integer.parseInt(br.readLine())]++;
        }
        br.close();
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 1; i <= 10000; i++) {
            for (int j = 0; j < intArry[i]; j++) {
                stringBuilder.append(i).append("\n");
            }
        }
        System.out.println(stringBuilder);
    }
}
