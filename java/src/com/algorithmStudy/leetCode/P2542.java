package com.algorithmStudy.leetCode;

import java.util.*;

public class P2542 {
    public static void main(String[] args) {
        int[] nums1 = new int[]{1, 2, 3};
        int[] nums2 = new int[]{1, 2, 3};
        int k = 3;
        System.out.println(new P2542().maxScore(nums1, nums2, k));
    }

    class Element {
        int num1;
        int num2;

        Element(int num1, int num2) {
            this.num1 = num1;
            this.num2 = num2;
        }
    }

    public long maxScore(int[] nums1, int[] nums2, int k) {
        List<Element> elements = new ArrayList<Element>();
        for (int i = 0; i < nums2.length; i++) {
            elements.add(new Element(nums1[i], nums2[i]));
        }
        Collections.sort(elements, (a, b) -> b.num2 - a.num2);

        int n1Sum = 0;
        PriorityQueue<Integer> minHeap = new PriorityQueue<>(k, (a, b) -> a - b);
        long res = 0;
        for (Element e : elements) {
            n1Sum += e.num1;
            minHeap.add(e.num1);
            if (minHeap.size() > k) {
                n1Sum -= minHeap.poll();
            }
            if (minHeap.size() == k) {
                res = (long) Math.max(res, n1Sum * e.num2);
            }
        }
        return res;
    }
}



