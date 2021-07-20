//dfs
// #include <iostream>
// using namespace std;
// int nodeNum, edgeNum, count = 0;
// bool graph[101][101];
// bool visited[101];

// void dfs(int from)
// {
//     visited[from] = true;
//     for (int i = 1; i <= nodeNum; i++)
//     {
//         if (graph[from][i] == true && visited[i] == false)
//         {
//             count++;
//             dfs(i);
//         }
//     }
// }
// int main()
// {
//     cin >> nodeNum >> edgeNum;
//     for (int i = 0; i < edgeNum; i++)
//     {
//         int from, to;
//         cin >> from >> to;
//         graph[from][to] = graph[to][from] = true;
//     }
//     dfs(1);
//     cout << count;
// }

//bfs
#include <iostream>
#include <queue>
using namespace std;

int nodeCount, edgeCount, groupCount = 0;
bool graph[101][101];
bool visited[101];
queue<int> que;
void bfs(int from)
{
    visited[from] = true;

    for (int i = 1; i <= nodeCount; i++)
    {
        if (graph[from][i] == true && visited[i] == false)
        {
            groupCount++;
            visited[i] = true;
            que.push(i);
        }
    }
    if (que.size() != 0)
    {
        int tmp;
        tmp = que.front();
        que.pop();
        bfs(tmp);
    }
}

int main()
{
    cin >> nodeCount >> edgeCount;
    while (edgeCount--)
    {
        int from, to;
        cin >> from >> to;
        graph[from][to] = graph[to][from] = true;
    }
    bfs(1);
    cout << groupCount;
}