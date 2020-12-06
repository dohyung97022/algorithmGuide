#include <iostream>
#include <map>
#include <deque>
using namespace std;

int nodeLen, edgeLen, startPoint;
map<int, deque<int>> graph;
bool visited[1001] = {
    false,
};

void dfs(int start)
{
    visited[start] = true;
    for (int i = 0; i < graph[start].size(); i++)
    {
        int val = graph[start][i];
        if (visited[val] == false)
        {
            cout << val << " ";
            dfs(val);
        }
    }
}

int main()
{
    cin >> nodeLen >> edgeLen >> startPoint;
    for (int i = 0; i < edgeLen; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }
    cout << startPoint << " ";
    dfs(startPoint);
}