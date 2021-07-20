#include <iostream>
using namespace std;

int zeroCountSave[41];
int oneCountSave[41];

pair<int, int> fibonacci(int n)
{
    // 그 값이 존재하지 않는다면
    if (zeroCountSave[n] == 0)
    {
        if (n == 0)
        {
            zeroCountSave[n] = 1;
            oneCountSave[n] = 0;
        }
        else if (n == 1)
        {
            zeroCountSave[n] = 0;
            oneCountSave[n] = 1;
        }
        else
        {
            pair<int, int> fibMinusOne = fibonacci(n - 1);
            pair<int, int> fibMinusTwo = fibonacci(n - 2);
            zeroCountSave[n] = fibMinusOne.first + fibMinusTwo.first;
            oneCountSave[n] = fibMinusOne.second + fibMinusTwo.second;
        }
    }
    return make_pair(zeroCountSave[n], oneCountSave[n]);
}

int main()
{
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int input;
        cin >> input;
        pair<int, int> fiboPair = fibonacci(input);
        cout << fiboPair.first << ' ' << fiboPair.second << '\n';
    }
}

// 가정
// 피보나치 3은 피보나치 1과 2의 zeroCount와 oneCount의 합을 zeroCount와 oneCount의 값으로 갖는다.
// fib 0 = 1,0
// fib 1 = 0,1
//
// 동적 할당 좀 고민한 문제
