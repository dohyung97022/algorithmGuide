package com.algorithmStudy;

//  1개만 옮기면 되는 경우
//  옮긴다

//  2개 옮겨야 하는 경우
//  그 이전 블록들을 중간 칸에 넣는다. -> 바닥을 옮겨야 한다.

// 3개 옮겨야 하는 경우
//


public class P11729 {

    public static void movePiece(Integer from, Integer between, Integer to, int[] tower) {
        System.out.println("tower[1] = " + tower[1]);
        System.out.println("tower[2] = " + tower[2]);
        System.out.println("tower[3] = " + tower[3]);

        // 1개면 그냥 옮긴다.
        if (tower[from] == 1) {
            tower[from] -= 1;
            tower[to] += 1;
            System.out.printf("%i 에서 %i 로 옮깁니다.%n", from, to);
            return;
        }

        // 그 이전 블록들을 중간 칸에 옮긴다.
        movePiece(between, to, from, tower);

        // 바닥을 옮긴다.
        // tower[from] -= 1;
        // tower[to] += 1;
    }

    public static void main(String[] args) {
        int[] tower = new int[4]; // int[존재하는 칸] =존재하는 블럭의 수
        tower[1] = 5;
        movePiece(1,2,3, tower);
    }
}


// 실패의 원인
// 하노의 탑 마지막 단계를 빼먹었다.
// int[] tower 로 문제를 복잡하게 만들었다.