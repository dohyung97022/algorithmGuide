// 백준에서 기초적인 비트마스킹 문제를 찾기 어려워
// hackerrank로 이동

// 문제해석
// 가장 높은 자릿수

#include <bits/stdc++.h>

using namespace std;

// Complete the maximizingXor function below.
int maximizingXor(int l, int r)
{
    int tmp, max = 0;
    for (int i = l; i <= r; i++)
    {
        for (int j = l; j <= r; j++)
        {
            tmp = i ^ j;
            if (tmp > max)
                max = tmp;
        }
    }
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int l;
    cin >> l;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int r;
    cin >> r;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = maximizingXor(l, r);

    fout << result << "\n";

    fout.close();

    return 0;
}