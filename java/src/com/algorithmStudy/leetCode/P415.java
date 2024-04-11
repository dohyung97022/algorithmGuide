package com.algorithmStudy.leetCode;

public class P415 {
    public static void main(String[] strings) {
        for (int i=0; i<10000; i++) {
            if (i%35==30 && i%45==40 && i%55==50) {
                System.out.println(i);
                break;
            }
        }
        return;
    }
}
