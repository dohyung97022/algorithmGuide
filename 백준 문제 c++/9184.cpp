//1. 삼차원 함수를 2개 만든다. 1개는 int값의 저장, 1개는 bool값의 저장
//2. call이 될 때만다 삼차원 함수 bool이 false라면 값을 저장 후 bool을 true로 한 후 리턴한다.
//3. call이 될 때마다 bool이 true라면 그 int값을 리턴한다.

#include <iostream>
using namespace std;
//-50은 0, 0은 50, 50은 100,
//-이든 +이든 모두 50을 더한다.
//-50 0 -49 1 -48 2 -47 3 -46 4 -45 5 -44 6 -43 7 -42 8 -41 9 -40 10
int a, b, c;
int savedValue[101][101][101];
bool wasSaved[101][101][101];

int dynamicRecursion(int a, int b, int c)
{
    int idxA = a + 50;
    int idxB = b + 50;
    int idxC = c + 50;

    // 저장된 적이 있다면 저장된 값을 불러온다.
    if (wasSaved[idxA][idxB][idxC])
    {
        return savedValue[idxA][idxB][idxC];
    }
    else
    {
        if (a <= 0 || b <= 0 || c <= 0)
            savedValue[idxA][idxB][idxC] = 1;

        else if (a > 20 || b > 20 || c > 20)
            savedValue[idxA][idxB][idxC] = dynamicRecursion(20, 20, 20);

        else if (a < b && b < c)
            savedValue[idxA][idxB][idxC] = dynamicRecursion(a, b, c - 1) + dynamicRecursion(a, b - 1, c - 1) - dynamicRecursion(a, b - 1, c);

        else
            savedValue[idxA][idxB][idxC] = dynamicRecursion(a - 1, b, c) + dynamicRecursion(a - 1, b - 1, c) + dynamicRecursion(a - 1, b, c - 1) - dynamicRecursion(a - 1, b - 1, c - 1);

        wasSaved[idxA][idxB][idxC] = true;
        return savedValue[idxA][idxB][idxC];
    }
}

int main()
{
    while (true)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
        {
            break;
        }
        else
            cout << "w(" << a << ", " << b << ", " << c << ") = " << dynamicRecursion(a, b, c) << "\n";
    }
}