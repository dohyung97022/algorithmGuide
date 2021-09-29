# algorithmGuide

## 공부계획

1일 2 문제 유명한 알고리즘 readme 기록

### 재귀함수

  <details>
  <summary>
  하노이 탑
  </summary>
  <br>

하노이 탑은 4가지만 기억하자.

탑의 높이가 n일 경우

1. 1개면 그냥 옮긴다.
2. n-1개를 중간으로 옮긴다.
3. 바닥 판을 끝으로 옮긴다.
4. 중간의 n-1 개를 끝으로 옮긴다.

-끝-

간단한게 최고다.
  </details>
  <br>

### 정렬

  <details>
  <summary>
  삽입 정렬
  </summary>
  <br>

원리

![](img/inserting-sort-gif.gif)

삽입 정렬을 구현할 때에는

  ```java
  for(int i=0;i< 10;i++){
        checkInt=list[i];
        for(int j=i-1;0=<j &&checkInt<list[j];j--){
        ...
        }
        }
  ```

같은 큰 틀에서 구현해봅시다.   
for loop 을 역방향으로도 이동시킬 수 있다는 생각을 할 수 있어야 합니다.   
순방향으로 1개씩 뽑고, 역방향으로 1개씩 체크하는 구조입니다.

시간복잡도   
Best : O(n)   
Avg : O(n^2)   
Worse : O(n^2)
  </details>
  <br>

  <details>
  <summary>
  선택 정렬
  </summary>
  <br>

원리

![](img/selection-sort-gif.gif)

선택 정렬을 구현할 때에는

  ```java
  for(int i=0;i< 10;i++){
        for(int j=i;j< 10;j++){

        }
        }
  ```

와 같이 내부 for loop 안에 외부 for loop 의 인자가 들어갑니다.     
앞에서부터 쌓아나가는 자료구조입니다.

시간복잡도   
Best : O(n^2)   
Avg : O(n^2)   
Worse : O(n^2)
  </details>
  <br>

  <details>
  <summary>
  버블 정렬
  </summary>
  <br>

원리

![](img/bubble-sort-gif.gif)   
![](img/bubble-sort-fromback.png)

마치 버블이 위로 올라가는 것을 연상시켜서 버블 정렬이라는 이름을 갖고 있습니다.   
선택 정렬과 달리 뒤에서부터 쌓아나가는 구조입니다.

시간복잡도   
Best : O(n^2)   
Avg : O(n^2)   
Worse : O(n^2)
  </details>
  <br>

  <details>
  <summary>
  퀵 정렬
  </summary>
  <br>

원리

![](img/quick-sort-gif.gif)

1. pivot 을 정하여 pivot 을 기준으로 좌측에 더 작은 수, 우측에 더 큰 수를 배치한다.
2. 분할정복으로 반복한다.

low 와 high 를 순차적으로 중앙을 향해 이동합니다.   
분할정복을 활용하고 있습니다.

Arrays.sort() 에 dual-pivot 형태로 사용되고 있다.

시간복잡도   
Best : O(n^2)   
Avg : O(n^2)   
Worse : O(n^2)
  </details>
  <br>

  <details>
  <summary>
  병합 정렬
  </summary>
  <br>

원리

![](img/merge-sort.png)
병합정렬은 분할과 병합으로 이루어져 있습니다.   
병합정렬의 경우 병합 단계에서 정렬을 합니다.   
분할정복을 활용하고 있습니다.

시간복잡도   
Best : O(log₂n)   
Avg : O(log₂n)   
Worse : O(log₂n)
  </details>
  <br>

  <details>
  <summary>
  팀 정렬
  </summary>
  <br>

합병정렬의 최악의 경우(O(log₂n)) 삽입정렬의 최선의 경우(O(n))가 결합된 알고리즘    
파이선, 자바의 소트에 널리 사용되고 있다.   
Collections.sort() 에 사용되는 알고리즘

Best : O(n)   
Avg : O(log₂n)   
Worse : O(log₂n)
  </details>
  <br>

### DP

  <details>
  <summary>
  Sub problem, Reoccurring problem
  </summary>
  <br>

막대기 자르기 문제

|분류| | | | | | | | | |
  |:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|길이 (i)|0|1|2|3|4|5|6|7|8|9|10|
|가격 (Pi)|0|1|5|8|9|10|17|17|20|24|30|

특정 길이의 막대기가 주어질 때 막대기를 적절하게 잘라서 가장 높은 가격을 받아야 합니다.

i : 길이   
Pi : i 길이에 해당하는 가격   
Ri : i 길이에 받을 수 있는 최대 가격

이 경우   
R0 = P0 = 0   
R1 = max(P1 + R0)   
R2 = max(P1 + R1, P2 + R0)   
R3 = max(P1 + R2, P2 + R1, P3 + R0)   
R4 = max(P1 + R3, P2 + R2, P3 + R1, P4 + R0)

가 된다는 것을 알 수 있습니다.

다시 설명드리면 다음과 같습니다.

길이 3의 최대 가격 = max(   
길이 1의 가격 + 길이 2의 최대 가격,   
길이 2의 가격 + 길이 1의 최대 가격,   
길이 3의 가격 + 길이 0의 최대 가격)    
<br>

이 문제는 2가지 특징이 있습니다.

Sub problem : 큰 문제를 작은 문제로 나눌 수 있다.   
R4 = max(P1 + R3, P2 + R2, P3 + R1, P4 + R0)    
R4 를 구하기 위해 (P1 + R3), (P2 + R2), (P3 + R1), (P4 + R0) 같이 4개의 문제로 나눌 수 있습니다.

Reoccurring problem : 작은 문제에서 구한 정답이 큰 문제에서 반복적으로 사용된다.   
R3 을 구하기 위해 (P1 + R2), (P2 + R1), (P3 + R0)      
R4 를 구하기 위해 (P1 + R3), (P2 + R2), (P3 + R1), (P4 + R0)   
가 필요하다면 작은 문제(R0, R1, R2)는 큰 문제(R3, R4) 안에 반복적으로 사용됩니다.

  <br>
  반복적으로 사용되는 작은 문제 Ri 를 배열로 따로 저장하는 것을 우리는 DP 이라고 합니다.    
  </details>
  <br>

### BackTracking

  <details>
  <summary>
  답이 안나오면 되돌아가는 방법
  </summary>
  <br>

  [Nth Queen 문제](https://www.acmicpc.net/problem/9663)
  
  문제   
  N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
  
  출력   
  첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.   
  <br>
  
  이 문제는 백트레킹의 대표적인 문제로 거론됩니다.   
  <br>
  
  풀이   
  첫 퀸을 가능한 곳을 찾아 놓으면서, 다음 퀸을 놓을 경우 재귀함수 안으로 들어갑니다.   
  재귀함수 안에서도 가능한 곳을 지속적으로 찾습니다.   
  모든 퀸을 놓을 경우 cnt 를 +1 해줍니다.   
  모든 퀸을 놓지 못할 경우 return 하여 재귀함수 전으로 돌아갑니다.   
  return 되면 이전의 퀸을 놓은 곳의 다음 가능한 곳을 찾아 놓습니다.
  
  이 문제는 다음과 같은 특징이 있습니다.
  
  * 문제가 해결되지 않는 경우 이전 경우의 수로 돌아간다.
  
  제가 위에서 생각한 풀이 방법에서는 `재귀함수`를 통해 이전 함수로 돌아갈 수 있습니다.   
  무조건 재귀함수만으로 작성할 수 있는 것은 아니며 `stack` 을 통해서도 이전 방법으로 돌아갈 수 있습니다.
  
  그림으로 설명
  
  | | | | |
  |:---:|:---:|:---:|:---:|
  | | | | |
  |Q| | | |
  
  | | | | |
  |:---:|:---:|:---:|:---:|
  | | |Q| |
  |Q| | | |
  
  추가적 경우의 수 없음   
  (이전 Q 의 다음 케이스들을 생각함)   
  
  | | | | |
  |:---:|:---:|:---:|:---:|
  | | | |Q|
  |Q| | | |
  
  | |Q| | |
  |:---:|:---:|:---:|:---:|
  | | | |Q|
  |Q| | | |

  이런 식으로 진행되며 Q 를 모두 사용한 경우에 cnt ++   
  더 이상의 경우의 수가 없다면 이전 Q 를 옮깁니다.   

  [저의 풀이](java/src/com/algorithmStudy/백준/P9663.java)   
  1차 배열로 풀어야지만 메모리 초과가 안나옵니다.   
  저의 경우 Point 라는 클래스를 만들어 사용하였습니다.   
  </details>
  <br>