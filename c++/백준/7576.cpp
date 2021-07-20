//7576 백준 왜 틀릴까

#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int xLen, yLen, bfsRes;

int map[1001][1001]{
    0,
};
int countMap[1001][1001]{
    0,
};

queue<pair<int, int>> givenOnes;

queue<pair<int, int>> bfsQue;

int bfs()
{
    int x, y;
    while (bfsQue.size())
    {
        x = bfsQue.front().first;
        y = bfsQue.front().second;

        bfsQue.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx >= 0 && ny >= 0 && nx <= xLen - 1 && ny <= yLen - 1 && map[nx][ny] == 0)
            {
                bfsQue.push(make_pair(nx, ny));
                countMap[nx][ny] = countMap[x][y] + 1;
                map[nx][ny] = 1;
            }
        }
    }
    return countMap[x][y];
}
int main()
{
    cin >> xLen >> yLen;
    for (int y = 0; y < yLen; y++)
    {
        for (int x = 0; x < xLen; x++)
        {
            int input;
            cin >> input;
            map[x][y] = input;
            if (input == 1)
            {
                givenOnes.push(make_pair(x, y));
            }
        }
    }
    while (givenOnes.size())
    {
        bfsQue.push(make_pair(givenOnes.front().first, givenOnes.front().second));
        givenOnes.pop();
    }
    //1이 처음부터 아예 주어지지 않았을 경우 반례
    if (bfsQue.size() != 0)
    {
        bfsRes = bfs();
    }
    else
    {
        cout << "-1" << endl;
        return 0;
    }
    for (int y = 0; y < yLen; y++)
    {
        for (int x = 0; x < xLen; x++)
        {
            if (countMap[x][y] == 0 && map[x][y] != -1 && map[x][y] != 1)
            {
                cout << "-1" << endl;
                return 0;
            }
        }
    }
    cout << bfsRes;
}

// 반례
// 2 2
// 0 0
// 0 0

// 4 3
// 0 0 0 1
// 1 1 0 0
//-1 -1 0 1