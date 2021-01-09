// dfs bfs
// dynamic
//                 0
//             0       1
//         0       1       2
//     0       1       2       3
// 0       1       2       3       4

// 풀이
// minWeight의 각 인덱스는 그 자리까지 오는데의 최솟값을 뜻한다.
// 각 인덱스는 그 이전에 올 수 있는, 1이 더 작거나 같은 인덱스 중 최대값을 갖게 된다.

#include <iostream>
#include <string.h>
using namespace std;

int minWeight[501];
int minWeightTmp[501];
int maxWeight = 0;

int main()
{
    int triLen;
    cin >> triLen;
    for (int i = 1; i <= triLen; i++)
    {

        for (int j = 0; j < i; j++)
        {
            int input;
            cin >> input;
            if (j == 0)
                // j-1의 인덱스가 0이면 전 인덱스 0의 값을 준다.
                minWeightTmp[j] = minWeight[j] + input;
            else
                // 1이 더 작거나 같은 인덱스 중 최대값
                minWeightTmp[j] = (minWeight[j - 1] > minWeight[j] ? minWeight[j - 1] : minWeight[j]) + input;
        }
        for (int j = 0; j < i; j++)
        {
            minWeight[j] = minWeightTmp[j];
            maxWeight = (maxWeight > minWeightTmp[j] ? maxWeight : minWeightTmp[j]);
        }
    }
    cout << maxWeight;
}

// memset은 메모리의 크기가 마지막 인자이다!
// sizeof()