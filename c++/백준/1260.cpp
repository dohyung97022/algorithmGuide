#include <iostream>
#include <map>
#include <deque>
#include <queue>
using namespace std;

int nodeLen, edgeLen, startPoint;
bool graph[1001][1001];
bool visited[1001];

void dfs(int start)
{
    cout << start << " ";
    visited[start] = true;
    for (int i = 1; i <= 1000; i++)
    {
        if (visited[i] == false && graph[start][i] == true)
        {
            dfs(i);
        }
    }
}
queue<int> bfsQue;
void bfs(int start)
{
    cout << start << " ";
    visited[start] = true;
    for (int i = 1; i <= 1000; i++)
    {
        bool val = graph[start][i];
        if (visited[i] == false && val == true)
        {
            bfsQue.push(i);
            visited[i] = true;
        }
    }
    if (bfsQue.size() != 0)
    {
        int tmp = bfsQue.front();
        bfsQue.pop();
        bfs(tmp);
    }
}

int main()
{
    cin >> nodeLen >> edgeLen >> startPoint;
    for (int i = 0; i < edgeLen; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from][to] = graph[to][from] = true;
    }

    dfs(startPoint);

    cout << "\n";
    fill_n(visited, 1001, false);

    bfs(startPoint);
}
// 반례
// 4 4 1
// 1 2
// 1 3
// 2 3
// 3 4
// ----
// 1 2 3 4
// 1 2 3 4