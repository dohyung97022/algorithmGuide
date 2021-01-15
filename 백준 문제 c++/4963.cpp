#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
// y, x
pair<int, int> direction[8] = {{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}};
int width, height, islandCount;
bool map[51][51];
queue<pair<int, int>> bfsQue;

void getIslandCountBfs()
{
    while (bfsQue.size())
    {
        int y = bfsQue.front().first;
        int x = bfsQue.front().second;
        bfsQue.pop();
        for (int i = 0; i < 8; i++)
        {
            int ny = direction[i].first + y;
            int nx = direction[i].second + x;

            if (0 <= ny && 0 <= nx && ny < height && nx < width && map[ny][nx])
            {
                map[ny][nx] = false;
                bfsQue.push(make_pair(ny, nx));
            }
        }
    }
}

int main()
{
    while (1)
    {
        cin >> width >> height;
        if (width == 0 && height == 0)
            break;
        for (int y = 0; y < height; y++)
            for (int x = 0; x < width; x++)
                cin >> map[y][x];
        islandCount = 0;
        for (int y = 0; y < height; y++)
            for (int x = 0; x < width; x++)
                if (map[y][x])
                {
                    map[y][x] = false;
                    bfsQue.push(make_pair(y, x));
                    getIslandCountBfs();
                    islandCount++;
                }
        cout << islandCount << "\n";

        for (int i = 0; i < 51; i++)
            memset(map[i], 0, 51);
    }
}
