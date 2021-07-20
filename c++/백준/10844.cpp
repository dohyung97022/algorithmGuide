// 1~9
// 0으로 시작하는 수는 없다? %10의 값이 0 일 수 없다?
// 12 21 23 32 34 43 45 54 56 65 67 76 78 87 89 98
// 하나의 큰 int로 보기보다
// 각 자릿수를 int로 보는 것이 낳지 않을까?

// 101
// 101 112

// 풀이
// 자릿수를 구한다.
// 제한은 첫 자리의 숫자와 마지막 자리의 숫자만 0이 되면 되지 않는다.
// 또한 각 자리의 시작과 끝은 1~9 부터 시작한다.
// 각 자리의 숫자를 돌아가면서 +1 또는 -1을 하면 되지 않을까?
// 0일 경우 -1이 불가능하다.

// dynamic 저장 방법
// 자릿수의 값 array
// +1 -1이 분할되면 무조건 다른 숫자가 나오는가?
// 무조건 다른 숫자가 나온다.

// #include <iostream>
// using namespace std;

// int tenthNum, count = 0;

// void recursion(int currentNum, int currentTenth)
// {
//     if (currentTenth == tenthNum)
//         count++;
//     for (int i = currentTenth; i < tenthNum; i++)
//     {
//         if (currentNum + 1 <= 9)
//             recursion(currentNum + 1, currentTenth + 1);
//         if (currentNum - 1 >= 0)
//             recursion(currentNum - 1, currentTenth + 1);
//     }
// }

// int main()
// {
//     cin >> tenthNum;
//     for (int j = 1; j <= 9; j++)
//     {
//         recursion(j, 1);
//     }
//     cout << count % 1000000000;
// }

// time out...

// 유셩장님
// 와... 천재이시옵나이까?
// 점화식
// 0의 경우 1만 가능하고 9 인 경우 8만 가능하니까
// 나머지 2~8까지의 숫자는 다 2가지의 경우가 있다.
// 그럼으로 식으로 표현하면 t를 N-1의 0과 9의 갯수라고 할 때, dp[n] = (dp[n-1] - t) * 2 + t
// 나도 이렇게 생각하고 싶다....
// 다음에는 점화식으로도 생각해보자...

#include <cstdio>
using namespace std;

#define MOD 1000000000

int main()
{

    int n, i, j;
    int dp[101][11] = {
        0,
    };
    int sum = 0;

    scanf("%d", &n);

    for (i = 0; i <= 9; i++)
        dp[1][i] = 1;

    for (i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][1];
        dp[i][10] = 0;
        for (j = 0; j <= 9; j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
    }

    for (i = 1; i <= 9; i++)
        sum = (sum + dp[n][i]) % MOD;
    printf("%d\n", sum);

    return 0;
}