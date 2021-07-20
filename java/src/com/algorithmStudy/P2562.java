package com.algorithmStudy;

import java.util.Scanner;

public class P2562 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int max = 0, maxIdx = 0;
        for (int i =1; i<=9; i++){
            int input = scanner.nextInt();
            if (max < input) {
                max = input;
                maxIdx = i;
            }
        }
        System.out.println(max);
        System.out.println(maxIdx);
    }
}
