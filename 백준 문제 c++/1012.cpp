//bfs

#include <iostream>
#include <deque>
using namespace std;
int testCase, farmXLen, farmYLen, plantLen, wormAmount;
bool graph[50][50];
bool visited[50][50];
pair<int, int> directions[4] =
    {pair<int, int>{0, 1}, pair<int, int>{0, -1}, pair<int, int>{1, 0}, pair<int, int>{-1, 0}};
deque<pair<int, int>> bfsDeque;
void bfs(int x, int y)
{
    visited[x][y] = true;

    for (auto const &dir : directions)
    {
        int newX = x + dir.first, newY = y + dir.second;
        if (newX >= 0 && newY >= 0 && newX < farmXLen && newY < farmYLen && !visited[newX][newY] && graph[newX][newY])
        {
            visited[newX][newY] = true;
            bfsDeque.push_back(pair<int, int>{newX, newY});
        }
    }
    if (bfsDeque.size())
    {
        pair<int, int> tmpPair = bfsDeque.front();
        bfsDeque.pop_front();
        bfs(tmpPair.first, tmpPair.second);
    }
}
int main()
{
    cin >> testCase;
    while (testCase--)
    {
        cin >> farmXLen >> farmYLen >> plantLen;
        while (plantLen--)
        {
            int x, y;
            cin >> x >> y;
            graph[x][y] = true;
        }
        wormAmount = 0;
        for (int x = 0; x < farmXLen; x++)
        {
            for (int y = 0; y < farmYLen; y++)
            {
                if (graph[x][y] && !visited[x][y])
                {
                    bfs(x, y);
                    wormAmount++;
                }
            }
        }
        cout << wormAmount << "\n";
        //초기화!
        for (int i = 0; i < 50; i++)
        {
            fill_n(graph[i], 50, 0);
            fill_n(visited[i], 50, 0);
        }
    }
}