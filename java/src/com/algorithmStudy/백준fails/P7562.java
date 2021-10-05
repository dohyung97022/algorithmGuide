package com.algorithmStudy.백준fails;

import java.io.IOException;
import java.util.Queue;
import java.util.Scanner;

// 실패의 이유, 반례를 조금 더 생각해보자.
// 아예 불가능한 경우는 어떻게 될까?
// depth 가 아예 출력되지 않는다.
public class P7562 {
    public static class Point {
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int finX, finY, size, depth = 0;
    static boolean[][] board;
    static Queue<Point> pointQueue;
    static int[] horseX = {-1, -2, -2, -1, 1, 2, 1, 2};
    static int[] horseY = {-2, -1, 1, 2, -2, -1, 2, 1};


    public static void bfs() {
        Point point = pointQueue.poll();
        // 이미 이동한 경우면 세지 않습니다.
        if (board[point.x][point.y])
            return;
        // 이동하는 위치가 fin 의 위치일 경우
        if (point.x == finX && point.y == finY)
            System.out.println(depth);
        // 이동하였습니다.
        board[point.x][point.y] = true;
        // 말이 이동할 수 있는 경우를 모두 생각
        for (int i = 0; i < 8; i++) {
            int dx = horseX[i] + point.x;
            int dy = horseY[i] + point.y;
            // 0보다 커야 하고 보드판 안에 들어가야 한다.
            if (0 > dx || 0 > dy || dx >= size || dy >= size) {
                // 넘어가는 경우
                continue;
            }
            pointQueue.add(new Point(dx, dy));
        }
    }

    public static void main(String[] args) throws IOException {
        // 가정
        // 1. testcase 를 받는다.
        // 2. testcase 마다 판의 크기와 시작 위치, 목표 위치를 받는다.
        // 3. bfs 접근
        // 4. 큐 안에 현제 위치에서 가능한 모든 범위를 넣는다.
        // 5. 이미 이동한 경우에 해당하면 해당 위치를 arr 안에 true 로 지정하여 리턴한다.
        // 6. 가능한 모든 범위를 넣을 때마다 cnt 를 ++ 한다.
        // 7. 원하는 위치에 이동하게 되면 cnt 를 반환한다.

        Scanner scanner = new Scanner(System.in);
        int testCase = scanner.nextInt();
        for (int i = 0; i < testCase; i++) {
            size = scanner.nextInt();
            board = new boolean[size][size];
            pointQueue.add(new Point(scanner.nextInt(), scanner.nextInt()));
            finX = scanner.nextInt();
            finY = scanner.nextInt();
            while (!pointQueue.isEmpty()) {
                bfs();
                depth ++;
            }
        }
    }
}