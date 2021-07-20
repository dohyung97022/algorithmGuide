// 1 2 3 4 5 5 7 8 9

// 가정 1
// s이상이 되도록 b를 오른쪽으로 옮긴다.
// s를 넘긴다면 t을 오른쪽으로 옮겨서 가장 가까운 수를 만든다.

// 부분합이 너무 작으면 b를 오른쪽으로
// 부분합이 너무 크다면 t를 오른쪽으로

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> partialSumArray;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arrayLen, targetNum;
    cin >> arrayLen >> targetNum;
    while (arrayLen--)
    {
        int input;
        cin >> input;
        partialSumArray.push_back(input);
    }

    int t = 0, b = 0, minLen = 100001;
    int sum = partialSumArray[t];
    for (int t = 0; t < partialSumArray.size() && t <= b; t++)
    {
        while (sum < targetNum && b < partialSumArray.size() - 1)
        {
            b++;
            sum = sum + partialSumArray[b];
        }
        if (sum >= targetNum && b - t + 1 < minLen)
            minLen = b - t + 1;

        sum = sum - partialSumArray[t];
    }
    if (minLen == 100001)
        cout << 0;
    else
        cout << minLen;
}

// 반례
// 10 100
// 98 1 1 1 50 50 1 1 1 98