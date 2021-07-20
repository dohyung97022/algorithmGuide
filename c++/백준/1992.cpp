// 가정 1.
// 전체가 1또는 0인지 확인한다.
// 4등분한다.
// 재귀 호출한다.

#include <iostream>
#include <cmath>
#define MAX 64
using namespace std;

// pair, [][], 모두 x,y
bool img[MAX][MAX];
int imgLen;

bool isSingleColor(pair<int, int> start, pair<int, int> end)
{
    int startX = start.first, startY = start.second;
    int endX = end.first, endY = end.second;
    bool firstCol = img[startX][startY];
    for (int y = startY; y <= endY; y++)
        for (int x = startX; x <= endX; x++)
            if (firstCol != img[x][y])
                return false;
    cout << firstCol;
    return true;
}

void dAndC(pair<int, int> start, pair<int, int> end)
{

    if (isSingleColor(start, end))
        return;

    cout << '(';

    int startX = start.first, startY = start.second;
    int endX = end.first, endY = end.second;
    int midFloorX = floor(double(startX + endX) / 2), midFloorY = floor(double(startY + endY) / 2);
    int midCeilX = ceil(double(startX + endX) / 2), midCeilY = ceil(double(startY + endY) / 2);

    dAndC(start, make_pair(midFloorX, midFloorY));
    dAndC(make_pair(midCeilX, startY), make_pair(endX, midFloorY));
    dAndC(make_pair(startX, midCeilY), make_pair(midFloorX, endY));
    dAndC(make_pair(midCeilX, midCeilY), make_pair(endX, endY));

    cout << ')';
}

int main()
{
    cin >> imgLen;
    for (int y = 0; y < imgLen; y++)
    {
        string input;
        cin >> input;
        for (int x = 0; x < imgLen; x++)
        {
            if (input[x] == '0')
                img[x][y] = false;
            else
                img[x][y] = true;
        }
    }

    dAndC(make_pair(0, 0), make_pair(imgLen - 1, imgLen - 1));
}