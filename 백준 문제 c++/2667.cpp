#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
int lenAndHeight, houseCount, dangiCount = 0;
bool graph[26][26];
bool visited[26][26];
queue<pair<int, int>> que;
deque<int> houseCountDeque;
void bfs(int fromX, int fromY)
{
    houseCount++;
    visited[fromX][fromY] = true;
    //y 상
    if ((fromY - 1) > 0 && graph[fromX][fromY - 1] && !visited[fromX][fromY - 1])
    {
        visited[fromX][fromY - 1] = true;
        que.push(pair<int, int>{fromX, fromY - 1});
    }
    //y 하
    if ((fromY + 1) < 26 && graph[fromX][fromY + 1] && !visited[fromX][fromY + 1])
    {
        visited[fromX][fromY + 1] = true;
        que.push(pair<int, int>{fromX, fromY + 1});
    }
    //x 좌
    if ((fromX - 1) > 0 && graph[fromX - 1][fromY] && !visited[fromX - 1][fromY])
    {
        visited[fromX - 1][fromY] = true;
        que.push(pair<int, int>{fromX - 1, fromY});
    }
    //x 우
    if ((fromX + 1) < 26 && graph[fromX + 1][fromY] && !visited[fromX + 1][fromY])
    {
        visited[fromX + 1][fromY] = true;
        que.push(pair<int, int>{fromX + 1, fromY});
    }

    if (que.size() != 0)
    {
        pair<int, int> tmpPair = que.front();
        que.pop();
        bfs(tmpPair.first, tmpPair.second);
    }
}
int main()
{
    cin >> lenAndHeight;
    for (int y = 1; y <= lenAndHeight; y++)
    {
        string tmpStr;
        cin >> tmpStr;
        for (int x = 1; x <= lenAndHeight; x++)
        {
            if (tmpStr[x - 1] == '1')
            {
                graph[x][y] = true;
            }
        }
    }
    for (int x = 1; x <= lenAndHeight; x++)
    {
        for (int y = 1; y <= lenAndHeight; y++)
        {
            if (!visited[x][y] && graph[x][y])
            {
                dangiCount++;
                houseCount = 0;
                bfs(x, y);
                houseCountDeque.push_back(houseCount);
            }
        }
    }
    sort(houseCountDeque.begin(), houseCountDeque.end());
    cout << dangiCount << "\n";
    for (auto const &val : houseCountDeque)
    {
        cout << val << "\n";
    }
}