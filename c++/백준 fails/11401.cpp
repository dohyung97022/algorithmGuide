// 문제를 이해하는데 실패
// 페르마의 소정리에 대한 이해가 부족하다.
// https://www.youtube.com/watch?v=pMA-dD-KCWM

// 엄청난 큰 제곱수를 특정한 다른 수로 나눌 때 나머지를 구하는데 사용하는 정리

// a^(p-1) % p = 1

// p는 소수, a는 정수, a는 p의 배수가 아니다.

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    int z = pow(x, (y - 1));
    cout << z % y;
}
