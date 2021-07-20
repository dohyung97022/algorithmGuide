// dynamic
// 10000001
// 1을 제외한 모든 수는 0보다 큰 횟수가 걸린다.
// 도달하는 연산을 계산하면서 걸린 횟수를 저장한다.

// 풀이
// 모든 경우의 수!
// 3으로 나누는 것을 구한다.
// 2로 나누는 것을 구한다.
// 1을 빼는 것을 구한다.
// 모두 구한 다음에 인덱스에 저장된 값이 0이거나 구한 값보다 작다면 저장한다.

// given의 숫자에서부터 음의 방향으로 for loop을 만든다.
// 각 케이스를 저장하면서 진행한다.
// 나눠질 수 있는지 확인한다.

// 4의 경우
// /2 /2
// -1 /3

// 7의 경우
// -1 /3 /2
// -1 /2 /3

// 10의 경우
// /2 -1 /2 /2
// -1 /3 /3

#include <iostream>
using namespace std;
int leastStep[10000001], given, nextStep;
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> given;

    for (int i = given; i > 1; i--)
    {
        nextStep = leastStep[i] + 1;
        // 3으로 나눠질 수 있다면 && 넣을 인덱스의 step이 0 또는 넣을 step보다 크다면
        if ((i % 3 == 0) && (leastStep[i / 3] == 0 || leastStep[i / 3] > nextStep))
            leastStep[i / 3] = nextStep;
        // 2로 나눠질 수 있다면 && 넣을 인덱스의 step이 0 또는 넣을 step보다 크다면
        if ((i % 2 == 0) && (leastStep[i / 2] == 0 || leastStep[i / 2] > nextStep))
            leastStep[i / 2] = nextStep;
        // 2까지 iteration되기 때문에 -1의 값의 범위초과는 생각할 필요 없다.
        // 넣을 인덱스의 step이 0 또는 넣을 step보다 크다면
        if ((leastStep[i - 1] == 0 || leastStep[i - 1] > nextStep))
            leastStep[i - 1] = nextStep;
    }
    cout << leastStep[1];
}

// edge case
// 1
//