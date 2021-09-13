package com.algorithmStudy.백준;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class P10814 {
    public static class User implements Comparable<User>{
        int age;
        String name;

        public User(int age, String name) {
            this.age = age;
            this.name = name;
        }

        public int getAge() {
            return age;
        }

        @Override
        public int compareTo(User o) {
            return Comparator
                    .comparing(User::getAge)
                    .compare(this, o);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCase = Integer.parseInt(scanner.nextLine());
        List<User> users = new ArrayList<>();
        for (int i = 0; i < testCase; i++) {
            users.add(new User(scanner.nextInt(), scanner.next()));
        }
        StringBuilder stringBuilder = new StringBuilder();
        users.stream().sorted().forEach(
                user -> stringBuilder
                        .append(user.age)
                        .append(" ")
                        .append(user.name)
                        .append("\n")
        );
        System.out.print(stringBuilder);
    }
}