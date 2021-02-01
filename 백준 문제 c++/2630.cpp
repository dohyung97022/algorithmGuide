// 가정 1.
// 2차 배열 안에 넣는다.
// 어떠한 요소를 어떻게 확인해야 빠르게 전체적으로 1인지 0인지 확인할 수 있을까?
// 일단 forloop으로 확인, 확인에 대한 알고리즘은 다시 나중에 고려
// 재귀적 호출 함수의 변수(pair<int>startPoint  pair<int>endPoint)
// 만약 모든 숫자가 일치하면 글로벌 변수 ++;

// 반례 추정, startPoint와 endPoint가 같을 경우?

#include <iostream>
#include <cmath>
#define MAX 128
using namespace std;

// 모든 pair = pair<y,x>
// array[y][x]
bool array[MAX][MAX];
int trueCount = 0, falseCount = 0;
int maxLen;

bool checkFullColor(pair<int, int> startPoint, pair<int, int> endPoint)
{
    int startX = startPoint.second, startY = startPoint.first;
    int endX = endPoint.second, endY = endPoint.first;
    int firstCol = array[startY][startX];
    for (int y = startY; y <= endY; y++)
        for (int x = startX; x <= endX; x++)
            if (array[y][x] != firstCol)
                return false;
    if (firstCol)
        trueCount++;
    else
        falseCount++;
    return true;
}

void dAndC(pair<int, int> startPoint, pair<int, int> endPoint)
{
    if (checkFullColor(startPoint, endPoint))
    {
        return;
    }
    int startX = startPoint.second, startY = startPoint.first;
    int endX = endPoint.second, endY = endPoint.first;
    int floorMidX = floor((startX + endX) / 2), floorMidY = floor((startY + endY) / 2);
    int ceilMidX = ceil(double(startX + endX) / 2), ceilMidY = ceil(double(startY + endY) / 2);

    dAndC(make_pair(startY, startX), make_pair(floorMidY, floorMidX));
    dAndC(make_pair(startY, ceilMidX), make_pair(floorMidY, endX));
    dAndC(make_pair(ceilMidY, startX), make_pair(endY, floorMidX));
    dAndC(make_pair(ceilMidY, ceilMidX), make_pair(endY, endX));
}

int main()
{
    cin >> maxLen;
    for (int y = 0; y < maxLen; y++)
        for (int x = 0; x < maxLen; x++)
            cin >> array[y][x];
    dAndC(make_pair(0, 0), make_pair(maxLen - 1, maxLen - 1));
    cout << falseCount << "\n"
         << trueCount;
}