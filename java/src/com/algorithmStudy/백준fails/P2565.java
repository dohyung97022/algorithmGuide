package com.algorithmStudy.백준fails;

import java.util.*;

public class P2565 {
    public static class Line {
        int a;
        int b;

        public Line(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    public static void main(String[] args) {
        // 전깃줄이 교차한다는 것은 어떠한 개념일까?

        // 교차하지 않는다.
        // 다른 선의 A 값이 더 적다
        // 다른 선의 B 값이 더 적다

        // 다른 선의 A 값이 더 크다
        // 다른 선의 B 값이 더 크다


        // 가장 많이 교차하는 선을 1개씩 삭제한다.


        // 가정
        // 1. 교차하는 정보를 저장한다. (줄의 인덱스는 받은 순서이다)
        // boolean[선][교차 선] = boolean
        // 2. 총 교차되는 지점들의 갯수를 저장한다.
        // 3. 가장 교차하는 줄이 많은 선부터 차래대로 없앤다.
        // (그 줄이 교차한 곳의 선도 없앤다.)
        // 4. 총 교차되는 지점의 갯수를 해당하는 만큼 줄인다.
        // 5.


        Scanner scanner = new Scanner(System.in);
        int testCase = scanner.nextInt();
        List<Line> lines = new ArrayList<>();
        boolean[][] crossLines = new boolean[testCase][testCase];
        int[] crossCount = new int[testCase];
        int totalCross = 0;
        for (int i = 0; i < testCase; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            for (int j = 0; j < lines.size(); j++) {
                boolean isCross;
                if (a > lines.get(j).a)
                    isCross = !(b > lines.get(j).b);
                else
                    isCross = !(b < lines.get(j).b);
                if (isCross) {
                    crossLines[i][j] = isCross;
                    crossLines[j][i] = isCross;
                    crossCount[i]++;
                    crossCount[j]++;
                    totalCross++;
                }
            }
            lines.add(new Line(a, b));
        }

    }
}