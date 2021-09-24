package com.algorithmStudy.백준;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class P9663 {
    // int[] arr 로도 생각할 수 있다.
    // 해당 인덱스가 행 결과가 열이라고 생각할 수도 있다.
    // 행은 중복될 수 없다는 특징을 이용한 것이다. (퀸은 같은 행에 중복될 수 없다.)
    public static class Point {
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int N, cnt = 0;
    public static Stack<Point> queens = new Stack<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        N = Integer.parseInt(br.readLine());
        nQueen(0, 0);
        bw.write(cnt);
        bw.flush();
        bw.close();
    }

    public static boolean isCollision(int x, int y) {
        for (Point queen : queens) {
            if (x == queen.x || y == queen.y || Math.abs(x - queen.x) == Math.abs(y - queen.y))
                return true;
        }
        return false;
    }

    public static void nQueen(int depth, int beforeY) {
        if (depth == N) {
            cnt++;
            return;
        }
        for (int y = beforeY; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (!isCollision(x, y)) {
                    queens.push(new Point(x, y));
                    nQueen(depth + 1, y);
                    queens.pop();
                }
            }
        }
    }
}