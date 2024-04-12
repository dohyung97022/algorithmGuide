package com.algorithmStudy.leetCode;

public class P62 {
    class Solution {
        public int uniquePaths(int m, int n) {
            // thoughts
            // so, the robot can only move right or down
            // if this is the case,
            // the space between up and left can be moved by the sum of cases of up and left
            // ex
            // 1, 1, 1, 1
            // 1, 2, 3, 4
            // 1, 3, 6, 10
            // as we see, the space is an addition of up and left
            // therefor we can get the bottom right by just for looping throught the space

            // logic
            // for looping x and for looping y
            // if the space has left, or right
            // add the sum as the space
            // repeat
            int[][] matrix = new int[m][n];
            matrix[0][0] = 1;
            for (int y = 0; y < m; y++) {
                for (int x = 0; x < n; x++) {
                    if (y - 1 >= 0) {
                        matrix[y][x] += matrix[y - 1][x];
                    }
                    if (x - 1 >= 0) {
                        matrix[y][x] += matrix[y][x - 1];
                    }
                }
            }
            return matrix[m - 1][n - 1];
        }
    }
}
