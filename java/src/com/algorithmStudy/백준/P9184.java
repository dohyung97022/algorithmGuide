package com.algorithmStudy.백준;

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.Scanner;

public class P9184 {
    public static class Tuple {
        int x, y, z;

        public Tuple(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Tuple tuple = (Tuple) o;
            return x == tuple.x && y == tuple.y && z == tuple.z;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y, z);
        }
    }

    static Map<Tuple, Integer> savedW = new HashMap<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StringBuilder stringBuilder = new StringBuilder();

        int a, b, c;
        while (true) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            c = scanner.nextInt();
            if (a == -1 && b == -1 && c == -1) {
                System.out.println(stringBuilder);
                return;
            }
            stringBuilder.append("w(").append(a).append(", ").append(b).append(", ").append(c).append(") = ").append(w(a, b, c)).append("\n");
        }
    }

    public static int w(int a, int b, int c) {
        int res;
        Tuple tuple = new Tuple(a, b, c);

        if (savedW.get(tuple) != null) {
            return savedW.get(tuple);
        } else if (a <= 0 || b <= 0 || c <= 0)
            res = 1;

        else if (a > 20 || b > 20 || c > 20)
            res = w(20, 20, 20);

        else if (a < b && b < c)
            res = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

        else
            res = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

        savedW.put(tuple, res);
        return res;
    }
}