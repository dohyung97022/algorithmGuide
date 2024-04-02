package com.algorithmStudy.leetCode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

// 해당 문제, 다시 풀기.
// potions 는 곱셈이 spell 과 될 때 해당 값이 민약 success 보다 크다면 그보다 높은 값의 경우는 모두 성공한다.
public class P2300 {
    class SpellIndex {
        int spell;
        int index;

        public SpellIndex(int spell, int index) {
            this.spell = spell;
            this.index = index;
        }
    }
    // failed approach
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        // brute force? O(n^2)
        // is there a better way?

        // if a pair is successful from a smaller spell, it is always successful in a larger spell.
        // we could use dp in order to remove some calculations already done in small spells in order to make O(logn)
        // but how would we store the value?
        // by a array of boolean with len of potions?

        // logic
        // sort spells incr
        // for loop spells
        // check bool[] if already success
        // if successful, save in bool[]
        // add the pairCnt to a ans
        // return ans
        List<SpellIndex> spellIndexs = new ArrayList<SpellIndex>();
        for (int i = 0; i < spells.length; i++) { // O(n)
            spellIndexs.add(new SpellIndex(spells[i], i));
        }
        Collections.sort(spellIndexs, (a, b) -> a.spell - b.spell);

        boolean[] dp = new boolean[potions.length];
        int[] ans = new int[spells.length];
        for (int i = 0; i < spellIndexs.size(); i++) {
            int sum = 0;
            for (int j = 0; j < potions.length; j++) {
                if (dp[j]) { // found in dp
                    sum++;
                    continue;
                }

                if ((long) spellIndexs.get(i).spell * (long) potions[j] >= success) {
                    sum++;
                    dp[j] = true;
                }
            }
            ans[spellIndexs.get(i).index] = sum;
        }
        return ans;
    }

    public int[] successfulPairsV2(int[] spells, int[] potions, long success) {
        // potions 는 곱셈이 spell 과 될 때 해당 값이 민약 success 보다 크다면 그보다 높은 값의 경우는 모두 성공한다.
        // potions 를 asc sort 한다.
        // spells 를 forloop 한다.
        // potions 를 forloop 한다.
        // 곱이 success 를 넘길 경우 cnt++ 하며 ans 의 int[] 에 append 한다.
        // reutrn ans

        // O(nlogn)
        Arrays.sort(potions);
        int[] answer = new int[spells.length];
        for (int i=0; i<spells.length; i++) { // O(n)
            int cnt = 0;
            int start = 0;
            int end = potions.length - 1;
            int mid = 0;
            boolean fin = false;
            while (!fin) { // O(logn) binary search
                mid = start + (int)(Math.ceil((end - start) / 2));
                if (mid == start) {
                    fin = true;
                }
                if ((long)spells[i] * (long)potions[mid] >= success) {
                    end = mid;
                } else {
                    start = mid;
                }
            }
            if (mid + 1 == end) {
                mid = end;
            }
            if ((long)spells[i] * (long)potions[mid] >= success) {
                answer[i] = potions.length - mid;
            } else {
                answer[i] = 0;
            }
        }
        return answer;
    }
}
