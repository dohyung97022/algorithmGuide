// 에스토스테네스의 체 만들어보기

#include <iostream>
#include <deque>
#include <cmath>
#include <string.h>

using namespace std;

const int MAX = 4000001;
bool estostenesCheck[MAX];
deque<int> estostenes;

int main()
{
    //에스토스테네스
    memset(estostenesCheck, true, MAX);

    for (int i = 2; i < sqrt(MAX); i++)
        for (int j = 2; j * i < MAX; j++)
            estostenesCheck[j * i] = false;

    for (int i = 0; i < MAX; i++)
        if (estostenesCheck[i] == 1)
            estostenes.push_back(i);

    int wantedSum;
    cin >> wantedSum;

    //투 포인터
    //1. s 와 n을 포인터로 둔다.
    //2. s 가 체를 for loop 하면서
    //   n 이 while문을 돌게끔 한다.
    //3. s+n이 지정된 수보다 작거나 같으며
    //   n이 MAX의 범위 안에 있다면 n++한다.
    //   합이 지정된 수보다 크다면 s++한다.
    int counter = 0;
    int n = 2;
    for (int s = 2; s < estostenes.size(); s++)
    {
        int partialSum = 0;
        while (partialSum <= wantedSum && n < estostenes.size() && estostenes[s] <= wantedSum)
        {
            partialSum = 0;
            for (int i = s; i <= n; i++)
                partialSum += estostenes[i];

            if (partialSum == wantedSum)
                counter++;
            if (partialSum <= wantedSum)
                n++;
        }
    }
    cout << counter;
}