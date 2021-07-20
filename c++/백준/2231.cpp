// 1. 입력의 자릿수를 /10 %10으로 구한다.
// 2. 가장 큰 자릿수부터 for loop을 돌면서 1~9까지의 숫자를 10, 100, 1000의 자릿수에 곱하여 더한다.
// 3. 자릿수도 더한다.
// 4. 분해합을 넘어가면 break한다.
// 5. 마지막에 분해합과 일치하면 그 숫자가 최솟값(1부터 for loop을 시작함으로...)이다.

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int wanted;
    cin >> wanted;

    // 1의 자리부터 생각해보자...(여기는 참고함...) wow... 이런 간단한 방법이...
    for (int i = 1; i < wanted; i++)
    {
        // 자릿수를 구해보자
        int devided = i, tenth = 0, sum = 0;
        while (devided)
        {
            tenth++;
            devided = devided / 10;
        }
        // x + x*자릿수 를 더한다.
        while (tenth--)
        {
            int tenthNum = round(pow(10, tenth));
            int placeNum = i / tenthNum % 10;
            sum += placeNum + tenthNum * placeNum;
        }
        if (sum == wanted)
        {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}

// 간단하게 생각해보자. 복잡한 것은 좋지 않다.