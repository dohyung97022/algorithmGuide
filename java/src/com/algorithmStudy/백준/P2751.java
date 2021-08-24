package com.algorithmStudy.백준;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class P2751 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();

        int caseSize = scanner.nextInt();
        List<Integer> array = new ArrayList<>();
        for (int i = 0; i < caseSize; i++) {
            array.add(scanner.nextInt());
        }
        Collections.sort(array);

        array.forEach(i -> sb.append(i).append("\n"));
        System.out.println(sb);
    }
}
