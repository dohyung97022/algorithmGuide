#include <iostream>
#include <cmath>
#define MAX 2187
using namespace std;

int paper[MAX][MAX];
int paperLen;
int minusCount = 0, zeroCount = 0, oneCount = 0;

bool isSingleColor(pair<int, int> start, pair<int, int> end)
{
    int startX = start.first, startY = start.second;
    int endX = end.first, endY = end.second;
    int startColor = paper[startX][startY];
    for (int y = startY; y <= endY; y++)
        for (int x = startX; x <= endX; x++)
            if (paper[x][y] != startColor)
                return false;
    if (startColor == -1)
        minusCount++;
    else if (startColor == 0)
        zeroCount++;
    else
        oneCount++;
    return true;
}

void dAndC(pair<int, int> start, pair<int, int> end)
{
    if (isSingleColor(start, end))
        return;

    int innerFloorMidX = floor(double(start.first + end.first) / 3);
    int innerCeilMidX = ceil(double(start.first + end.first) / 3);
    int outerFloorMidX = floor(double(start.first + end.first) * 2 / 3);
    int outerCeilMidX = ceil(double(start.first + end.first) * 2 / 3);
    int innerFloorMidY = floor(double(start.second + end.second) / 3);
    int innerCeilMidY = ceil(double(start.second + end.second) / 3);
    int outerFloorMidY = floor(double(start.second + end.second) * 2 / 3);
    int outerCeilMidY = ceil(double(start.second + end.second) * 2 / 3);

    dAndC(start, make_pair(innerFloorMidX, innerFloorMidY));
    dAndC(make_pair(innerCeilMidX, start.second), make_pair(outerFloorMidX, innerFloorMidY));
    dAndC(make_pair(outerCeilMidX, start.second), make_pair(end.first, innerFloorMidY));
    dAndC(make_pair(start.first, innerCeilMidY), make_pair(innerFloorMidX, outerFloorMidY));
    dAndC(make_pair(innerCeilMidX, innerCeilMidY), make_pair(outerFloorMidX, outerFloorMidY));
    dAndC(make_pair(outerCeilMidX, innerCeilMidY), make_pair(end.first, outerFloorMidY));
    dAndC(make_pair(start.first, outerCeilMidY), make_pair(innerFloorMidX, end.second));
    dAndC(make_pair(innerCeilMidX, outerCeilMidY), make_pair(outerFloorMidX, end.second));
    dAndC(make_pair(outerCeilMidX, outerCeilMidY), end);
}

int main()
{
    cin >> paperLen;
    for (int y = 0; y < paperLen; y++)
        for (int x = 0; x < paperLen; x++)
            cin >> paper[x][y];
    dAndC(make_pair(0, 0), make_pair(paperLen - 1, paperLen - 1));
    cout << minusCount << "\n"
         << zeroCount << "\n"
         << oneCount;
}