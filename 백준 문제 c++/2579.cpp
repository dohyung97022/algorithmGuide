/* 
풀이
그 계단에 들어가는데 1 step 또는 2 step의 경우에 나눠서 최댓값을 저장한다.
1 step 인 경우 다시 1 step을 할 수 없다.

마지막 계단?
그냥 구하던 데로 마지막 계단을 구한다.
why? 각 계단의 값들도 1 step 또는 2 step을 한 경우들의 최댓값을 나타낸 것이기 때문에
그저 마지막 인덱스의 값의 1 step 과 2 step 값 중 더 큰 값을 고르면 되는 것이기 때문이다.
*/

#include <iostream>
using namespace std;

int stairsLen, stairPoint, twoFromOne, twoFromTwo, answer;
int oneStep[301];
int twoStep[301];

int main()
{
    cin >> stairsLen;
    for (int i = 0; i < 2 && i < stairsLen; i++)
    {
        cin >> stairPoint;
        if (i == 0)
            twoStep[i] = stairPoint;
        if (i == 1)
        {
            twoStep[i] = stairPoint;
            oneStep[i] = twoStep[i - 1] + stairPoint;
        }
    }
    for (int i = 2; i < stairsLen; i++)
    {
        cin >> stairPoint;

        twoFromOne = oneStep[i - 2] + stairPoint;

        oneStep[i] = twoStep[i - 1] + stairPoint;
        twoFromTwo = twoStep[i - 2] + stairPoint;

        twoStep[i] = twoFromOne > twoFromTwo ? twoFromOne : twoFromTwo;
    }
    answer = (oneStep[stairsLen - 1] > twoStep[stairsLen - 1]) ? oneStep[stairsLen - 1] : twoStep[stairsLen - 1];
    cout << answer;
}

// edge case
// 계단의 갯수가 1인 경우
// 2인 경우
// 3인 경우
