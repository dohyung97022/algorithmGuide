package com.algorithmStudy.백준;

import java.util.Arrays;
import java.util.Scanner;

public class P2750 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int caseSize = scanner.nextInt();
        int[] array = new int[caseSize];
        for (int i = 0; i < caseSize; i++) {
            array[i] = scanner.nextInt();
        }
        Arrays.stream(array).sorted().forEach(System.out::println);
    }
}
