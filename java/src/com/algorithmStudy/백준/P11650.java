package com.algorithmStudy.백준;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

// 나에게 부족한 내용 : 클래스 안에서 comparable<Pair> 를 넣지 않았다.
// comparator 가 1, 0, -1 로 구분되는지, 그 순서가 어떻게 되는지 몰랐다.

//public class Main {
//    public static class Pair {
//        public int x, y;
//
//        public Pair(int x, int y) {
//            this.x = x;
//            this.y = y;
//        }
//    }
//
//    public static void main(String[] args) throws IOException {
//        Scanner scanner = new Scanner(System.in);
//        int testCase = scanner.nextInt();
//        List<Pair> pairs = new ArrayList<>();
//        for (int i = 0; i < testCase; i++) {
//            pairs.add(new Pair(scanner.nextInt(), scanner.nextInt()));
//        }
//
//        StringBuilder sb = new StringBuilder();
//        pairs.stream().sorted((o1, o2) -> {
//            if (o1.x > o2.x)
//                return 1;
//            else if (o1.x == o2.x)
//                if (o1.y > o2.y)
//                    return 1;
//                else if (o1.y == o2.y)
//                    return 0;
//            return -1;
//        }).forEach(pair -> sb.append(pair.x).append(" ").append(pair.y).append("\n"));
//
//        System.out.println(sb);
//    }
//}

public class P11650 {
    public static class Pair implements Comparable<Pair>{
        public int x, y;

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
        public int compareTo(Pair o) {
            return Comparator
                    .comparing(Pair::getX)
                    .thenComparing(Pair::getY)
                    .compare(this, o);
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int testCase = scanner.nextInt();
        List<Pair> pairs = new ArrayList<>();
        for (int i = 0; i < testCase; i++) {
            pairs.add(new Pair(scanner.nextInt(), scanner.nextInt()));
        }
        StringBuilder sb = new StringBuilder();
        pairs.stream().sorted().forEach(pair -> sb.append(pair.x).append(" ").append(pair.y).append("\n"));
        System.out.println(sb);
    }
}