package com.algorithmStudy.백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class P1427 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<Integer> list = new ArrayList<>();
        for (char c : br.readLine().toCharArray()) {
            list.add(Character.getNumericValue(c));
        }
        list.sort(Comparator.reverseOrder());
        StringBuilder stringBuilder = new StringBuilder();
        list.forEach(stringBuilder::append);
        System.out.println(stringBuilder);
    }
}
