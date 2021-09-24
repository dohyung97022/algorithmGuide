package com.algorithmStudy.백준fails;

import java.io.*;

// 가정
// 1. x, y 를 모두 돈다. 0 이 나온다면 2로 넘어간다.

// 2. 1~9까지 넣어보면서 스도쿠에 만족한다 -> x,y를 stack 에 넣는다. -> 배열에 숫자를 넣고 가정-1 로 돌아간다.
// 3. 스도쿠에 만족하지 않는다 -> 리턴한다.

// 4. 마지막 스택을 뺀다. 배열의 숫자를 다시 0으로 만든다. 나머지 1~9까지의 루프를 돈다.


// 스도쿠에 만족한다.
// 해당 가로줄이 1~9 까지의 숫자 중 중복되는 것이 없다.
// 해당 세로줄이 1~9 까지의 숫자 중 중복되는 것이 없다.
// 해당 3x3 이 1~9 까지의 숫자 중 중복되는 것이 없다.
// boolean[10] 을 통해 중복을 확인한다.

// 틀린 이유
// 반례
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0

public class P2580 {
    static int[][] board;
    static int N;
    static final int[][] boardDevision = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void inputBoard() throws Exception {
        String[] inputs = br.readLine().split(" ");
        board = new int[inputs.length][inputs.length];
        N = inputs.length;
        for (int x = 0; x < inputs.length; x++) {
            board[0][x] = Integer.parseInt(inputs[x]);
        }
        for (int y = 1; y < inputs.length; y++) {
            inputs = br.readLine().split(" ");
            for (int x = 0; x < inputs.length; x++) {
                board[y][x] = Integer.parseInt(inputs[x]);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        inputBoard();
        sudoku();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int l = 0; l < board.length; l++) {
            for (int i : board[l]) {
                bw.write(i + " ");
            }
            if (l != board.length -1)
                bw.write("\n");
        }
        bw.flush();
        bw.close();
    }

    public static void sudoku() {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (board[y][x] == 0) {
                    for (int i = 1; i <= 9; i++) {
                        int tmp = board[y][x];
                        board[y][x] = i;
                        if (isOk(y, x)) {
                            // System.out.println(x + " " + y + " = " + i);
                            // for (int[] line : board) {
                            //     System.out.println(Arrays.toString(line));
                            // }
                            // System.out.println('\n');
                            sudoku();
                        } else board[y][x] = tmp;
                    }
                }
            }
        }
    }

    public static boolean isOk(int y1, int x1) {
        // 세로줄
        boolean[] checker = new boolean[10];
        for (int y = 0; y < 9; y++) {
            if (board[y][x1] != 0) {
                if (!checker[board[y][x1]])
                    checker[board[y][x1]] = true;
                else return false;
            }
        }
        // 가로줄
        checker = new boolean[10];
        for (int x = 0; x < 9; x++) {
            if (board[y1][x] != 0) {
                if (!checker[board[y1][x]])
                    checker[board[y1][x]] = true;
                else return false;
            }
        }
        // 3x3
        checker = new boolean[10];
        int xDivision = 0, yDivision = 0; // 0,1,2
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (boardDevision[i][j] == y1)
                    yDivision = i;
                if (boardDevision[i][j] == x1)
                    xDivision = i;
            }
        }
        for (int x : boardDevision[xDivision]) {
            for (int y : boardDevision[yDivision]) {
                if (board[y][x] != 0) {
                    if (!checker[board[y][x]])
                        checker[board[y][x]] = true;
                    else return false;
                }
            }
        }
        return true;
    }
}