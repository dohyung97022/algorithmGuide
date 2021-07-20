// rgbmap을 정의하고
// bfs를 하고
//

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
// y x
pair<int, int> direction[4]{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
int mapSize;
string rgbMap[101];
bool visited[101][101];
bool greenRedIll = false;
int counter = 0;

void bfs(int y, int x, char *col)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + direction[i].first;
        int nx = x + direction[i].second;
        if (ny >= 0 && nx >= 0 && mapSize > ny && mapSize > nx && !visited[ny][nx])
        {
            if ((greenRedIll && ((*col == 'R' || *col == 'G') && (rgbMap[ny][nx] == 'R' || rgbMap[ny][nx] == 'G'))) || (rgbMap[ny][nx] == *col))
            {
                visited[ny][nx] = true;
                bfs(ny, nx, col);
            }
        }
    }
}

int main()
{
    // 입력
    cin >> mapSize;
    for (int i = 0; i < mapSize; i++)
        cin >> rgbMap[i];
    // // 일반인
    for (int y = 0; y < mapSize; y++)
        for (int x = 0; x < mapSize; x++)
        {
            if (!visited[y][x])
            {
                counter++;
                visited[y][x] = true;
                bfs(y, x, &rgbMap[y][x]);
            }
        }
    cout << counter << " ";
    // // 초기화
    counter = 0;
    for (auto &val : visited)
        memset(val, false, 101);
    // 초빨병
    greenRedIll = true;
    for (int y = 0; y < mapSize; y++)
        for (int x = 0; x < mapSize; x++)
        {
            if (!visited[y][x])
            {
                counter++;
                visited[y][x] = true;
                bfs(y, x, &rgbMap[y][x]);
            }
        }
    cout << counter << "\n";
}