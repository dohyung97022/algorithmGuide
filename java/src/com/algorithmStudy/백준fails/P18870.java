package com.algorithmStudy.백준fails;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class P18870 {
    public static void main(String[] args) throws IOException {
        // sort 를 진행한다.
        // Scanner scanner = new Scanner(System.in);
        // List<Integer> originalNumbers = new ArrayList<>();
        // Set<Integer> numbers = new LinkedHashSet<>();
        // int testCase = scanner.nextInt();
        // for (int i = 0; i < testCase; i++) {
        //     int number = scanner.nextInt();
        //     originalNumbers.add(number);
        //     numbers.add(number);
        // }
        // List<Integer> sortedNumbers = numbers.stream().sorted().collect(Collectors.toList());
        // StringBuilder stringBuilder = new StringBuilder();
        // originalNumbers
        //         .forEach(i -> stringBuilder
        //                 .append(sortedNumbers.indexOf(i))
        //                 .append(" ")
        //         );
        // System.out.println(stringBuilder);

        // 실패의 원인
        // List.indexOf 는 루프를 돌면서 몇번째 인덱스인지 확인한다
        // 차라리 count++ 를 하면서 몇번째인지 저장하는 것이 더 빠르다

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int num = Integer.parseInt(br.readLine());

        String[] arr = br.readLine().split(" ");
        int[] an = new int[num];
        int cnt = 0;

        for(int i = 0 ; i < arr.length ; i ++)
            an[i] = Integer.parseInt(arr[i]);

        int[] temp = an.clone();

        Arrays.sort(an);

        HashMap<Integer, Integer> hmap = new HashMap<>();
        for(int i = 0 ; i < an.length ; i++) {
            if(!hmap.containsKey(an[i]))
                // count 가 ++ 되어있기에 이전의 값들이 얼마나 많은지 확인된다.
                hmap.put(an[i], cnt++);
        }

        for(int i = 0; i < num ; i++) {
            sb.append(hmap.get(temp[i])).append(" ");
        }

        System.out.println(sb);
    }
}