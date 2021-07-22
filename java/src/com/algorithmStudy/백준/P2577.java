package com.algorithmStudy.백준;

import java.util.Scanner;

public class P2577 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int res = 1, leftOver;
        int[] counter = new int[10];
        for (int i = 0; i < 3; i++)
            res = res * scanner.nextInt();

        while (res != 0){
            leftOver = res % 10;
            counter[leftOver]++;
            res = res / 10;
        }
        for (int count : counter)
            System.out.println(count);
    }
}
