// 에스토스테네스의 체
// 값이 소수라면
// 모든 소수의 배수는 소수가 아니다.

#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 4000000;
bool primeNumber[MAX];

int main()
{
    for (int i = 0; i < MAX; i++)
        primeNumber[i] = i;

    int sqrtMax = sqrt(MAX);

    for (int i = 2; i * 2 < sqrtMax; i++)
    {
        if (primeNumber[i] == 0)
            continue;
        for (int w = i, j = i; w * j < MAX; j++)
            primeNumber[w * j] = 0;
    }

    for (int i = 0; i < MAX; ++i)
        if (primeNumber[i] != 0)
            cout << i << " ";
}