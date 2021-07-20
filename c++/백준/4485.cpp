// 배열의 다익스트라 알고리즘

// map의 저장
// djk에서 시작 위치를 받는다.
// 시작 위치에서 상하좌우를 확인한다.
// 지금까지 잃은 루피와 이동하여 잃을 루피의 값의 합이 위치 배열에 저장된 루피의 값보다
// 작다면 그 값으로 갱신하고 우선순위 큐에 입력한다.
// 상하좌우에서 가장 최소의 루피가 감소하는 칸을 우선으로 loop를 돌도록 한다.

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

// 모든 map은 0,0을 포함하도록 한다.
// map[x][y]
int map[126][126];
int minLost[126][126];
int caveLen;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void djk()
{
    // tuple< lostRupy, x, y >
    priority_queue<tuple<int, int, int>> pk;
    pk.push({-map[0][0], 0, 0});
    while (pk.size())
    {
        int curLostRupy = -get<0>(pk.top());
        int curX = get<1>(pk.top());
        int curY = get<2>(pk.top());
        pk.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = curX + dx[i];
            int y = curY + dy[i];
            // xy가 범위에서 벗어나지 않는다면
            if (x >= 0 && y >= 0 && x < caveLen && y < caveLen)
                if (curLostRupy + map[x][y] < minLost[x][y])
                {
                    minLost[x][y] = curLostRupy + map[x][y];
                    pk.push({-minLost[x][y], x, y});
                }
        }
    }
}

int main()
{
    int problemCount = 1;
    while (cin >> caveLen)
    {
        if (!caveLen)
            break;
        for (int y = 0; y < caveLen; y++)
            for (int x = 0; x < caveLen; x++)
            {
                cin >> map[x][y];
                minLost[x][y] = 2100000000;
            }
        minLost[0][0] = 0;
        djk();
        cout << "Problem " << problemCount << ": " << minLost[caveLen - 1][caveLen - 1] << "\n";
        problemCount++;
    }
}

// 반례 시작위치, 0으로 시작하게 만들면 문제 없다. v
// 동굴의 크기가 125일 경우 v
// 동굴의 크기가 2인 경우 v