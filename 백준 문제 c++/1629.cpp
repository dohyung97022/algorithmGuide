// unthinkable
// 보고 해석하고 기억해서 다시 작성한다.
// 문제의 해석.
// 제곱수를 점차 곱해나아가는데
// 높은 제곱수에서부터 시작해서
// 점점 내려간다.
// 이때 2의 배수의 제곱수가 나오면
// 그 제곱수의 반절을 나눠서
// 각 제곱수를 곱하여 구하고자 했던 본 제곱수를 구하는 방식이다.
// c로 각 값을 나누는 이유는 어짜피 c의 배수가 되어버리면
// 먼저 나누든 나중에 나누든 상관이 없기 때문이다.

// ex ) 10^11 = 10^10*10 = 10^5*10^5*10 = 10^4*10^4*10*10*10 = 10^2*10^2*10^2*10^2*10^3

#include <iostream>
using namespace std;
int a, b, c;
long long pow(int n, int sqr)
{
    if (sqr == 0)
        return 1;
    else if (sqr == 1)
        return n;
    else if (sqr % 2 > 0)
        return pow(n, sqr - 1) * n;
    else
    {
        long long half = pow(n, sqr / 2) % c;
        return half * half % c;
    }
}

int main()
{
    cin >> a >> b >> c;
    cout << pow(a, b) % c;
}