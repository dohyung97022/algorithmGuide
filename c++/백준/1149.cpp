//탐색법?
//dfs bfs?
// dynamic?

// 풀이
// 크기가 3인 array를 놓는다.
// 해당 array의 값의 뜻은 그 이전까지 같은 색만 아닌 모든 경우의 수 중 가장 작은 케이스를 뜻한다.
// 예제 입력을 예로 들면

// 26 40 83
// 89 86 83
// 96 172 185

// 그렇다면 그 이전 케이스를 dynamic하게 저장할 필요성이 있는가?
// 없다.

// 1. 앞의 자릿수가 없다면 그 숫자 그대로 쓴다. (생각할 필요 없다. 0,0,0)
// 2. r의 경우 g,b의 최솟값을 r의 숫자와 더한다.
// 3. g의 경우 r,b의 최솟값을 g의 숫자와 더한다.
// 4. b의 경우도 마찬가지.
// 5. 앞의 구한 size 3의 array에서 반복한다.

#include <iostream>
using namespace std;

int minRGB[3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int houseLen, r, g, b, nr, ng, nb, res;
    cin >> houseLen;
    while (houseLen--)
    {
        r = (minRGB[1] < minRGB[2]) ? minRGB[1] : minRGB[2];
        g = (minRGB[0] < minRGB[2]) ? minRGB[0] : minRGB[2];
        b = (minRGB[0] < minRGB[1]) ? minRGB[0] : minRGB[1];
        cin >> nr >> ng >> nb;
        minRGB[0] = r + nr;
        minRGB[1] = g + ng;
        minRGB[2] = b + nb;
    }
    cout << min(min(minRGB[0], minRGB[1]), minRGB[2]);
}

// 반례
// 1. overflow? 최악의 케이스 1000을 1000번 더한다.
// 100만
// 21억의 int 범위 안에 들어간다.