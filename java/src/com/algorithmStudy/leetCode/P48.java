package com.algorithmStudy.leetCode;

public class P48 {
    class Solution {
        public void rotate(int[][] matrix) {
            // Constraints
            // You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

            // thoughts
            // If we cannot save the whole matrix,
            // what happens if we save the ripped off part when modified?
            // and continue doing so while modifying?

            // funny thought
            // The tornado method
            // identify the 'to be moved' line
            // save the 'to be modified' line in memory
            // change the 'to be modified' to 'to be moved' line.
            // repeat to the next line like a tornado.
            // O(n) = this method will loop throught the whole n once. (tornado going inwards)

            // but how would we implement such method?
            // [0~x][0] 'to be moved'
            // [x][0~y] 'to be modified', 'to be moved'
            // [0~x][y] 'to be modified', 'to be moved'
            // [0][0~y] 'to be modified', 'to be moved'
            // [0~x][0] 'to be modified'

            // repeat but go inwards the tornado
            // [1~x-1][1] 'to be moved'
            // [x-1][1~y-1] 'to be modified', 'to be moved'
            // [1~x-1][y-1] 'to be modified', 'to be moved'
            // [1][1~y-1] 'to be modified', 'to be moved'
            // [1~x-1][1] 'to be modified'

            // repeat
            // repeat but go inwards the tornado
            // [n~x-n][n]
            // [x-n][n~y-n]
            // [n~x-n][y-n]
            // [n][n~y-n]
            // [n~x-n][n]

            // but what if the len of x is odd?
            // what if the inner tornado is a single square?
            // end with a condition
            // [n~x-n][n] = [1~(2-1)][1] therefor n == x - n
            // if (n == x - n): stop tornado

            // better thought
            // tornado method V2
            // a tornado method but with only single digits
            // from Case 1
            // 1 -> 3 -> 9 -> 7 -> 1
            // 2 -> 6 -> 8 -> 4
            // does not run 5
            // this is possible with depth as the inner for loop
            // still O(n) but should be much more memory efficient
            for (int depth=0; depth < Math.ceil((float)matrix[0].length / 2); depth++) {
                for (int i=depth; i<matrix[0].length - depth - 1; i++) {

                    int put = matrix[depth][i];
                    int save = matrix[i][matrix.length-depth-1];
                    matrix[i][matrix.length-depth-1] = put;

                    put = save;
                    save = matrix[matrix.length-depth-1][matrix.length-1-i];
                    matrix[matrix.length-depth-1][matrix.length-1-i] = put;

                    put = save;
                    save = matrix[matrix.length-1-i][depth];
                    matrix[matrix.length-1-i][depth] = put;

                    matrix[depth][i] = save;
                }
            }
        }
    }
}
