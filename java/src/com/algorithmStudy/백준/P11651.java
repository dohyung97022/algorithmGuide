package com.algorithmStudy.백준;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class P11651 {
    public static class Pair implements Comparable<Pair>{
        int x, y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        @Override
        public int compareTo(Pair p) {
            return Comparator
                    .comparing(Pair::getY)
                    .thenComparing(Pair::getX)
                    .compare(this, p);
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Pair> pairs = new ArrayList<>();
        int testCase = scanner.nextInt();
        for (int i = 0; i < testCase; i++) {
            pairs.add(new Pair(scanner.nextInt(), scanner.nextInt()));
        }
        StringBuilder sb = new StringBuilder();
        pairs.stream().sorted().forEach(pair -> sb.append(pair.x).append(" ").append(pair.y).append("\n"));
        System.out.println(sb);
    }
}