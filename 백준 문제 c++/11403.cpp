// map을 edge를 저장하는 형태로 만들어서
// 각 노드에서 bfs를 한 이후 나오는 모든 다른 노드들을 저장하여
// 있는 경우 1, 없는 경우 0을 출력한다.

// 단 방향성 그래프이다.

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

vector<int> map[101];
bool visited[101];
queue<int> nodeQue;

void bfs()
{
    while (nodeQue.size())
    {
        int curNode = nodeQue.front();
        nodeQue.pop();
        // 그 노드와 연결된 모든 숫자.
        for (int i = 0; i < map[curNode].size(); i++)
        {
            int nextNode = map[curNode][i];
            // 방문한 적이 없다면
            if (!visited[nextNode])
            {
                // 방문하도록 합니다.
                visited[nextNode] = true;
                nodeQue.push(nextNode);
            }
        }
    }
}

int main()
{
    int nodeCount;
    cin >> nodeCount;
    for (int i = 0; i < nodeCount; i++)
    {
        for (int j = 0; j < nodeCount; j++)
        {
            int connected;
            cin >> connected;
            if (connected)
                map[i].push_back(j);
        }
    }
    for (int i = 0; i < nodeCount; i++)
    {
        memset(visited, false, 101);
        nodeQue.push(i);
        bfs();
        for (int j = 0; j < nodeCount; j++)
            cout << visited[j] << " ";

        cout << endl;
    }
}

// 반례
// 정점의 개수가 1인 경우, 100인 경우