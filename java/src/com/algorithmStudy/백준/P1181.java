package com.algorithmStudy.백준;

import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class P1181 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCase = Integer.parseInt(scanner.nextLine());
        Set<String> words = new HashSet<>();
        for (int i = 0; i < testCase; i++) {
            words.add(scanner.nextLine());
        }
        StringBuilder stringBuilder = new StringBuilder();
        words.stream().sorted(
                Comparator
                        .comparing(String::length)
                        .thenComparing(String::compareTo)
        ).forEach(s -> stringBuilder.append(s).append("\n"));
        System.out.println(stringBuilder);
    }
}