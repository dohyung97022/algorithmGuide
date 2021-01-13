// 연결 요소에 대한 설명 정의는 여기 https://www.youtube.com/watch?v=q6pKCP1W0dk

// 각각 점들을 bfs를 통하여 이동하며 연결된 모든 점들을 방문한다.?
// 방문이 안된 점이 있다면 그 점도 방문하되 connected components를 ++한다.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int nodeConunt, lineCount, connectedCount = 0;
vector<int> connection[1001];
bool visited[1001];
queue<int> bfsQue;

void bfs()
{
    for (int j = 1; j <= nodeConunt; j++)
    {
        if (!visited[j])
        {
            connectedCount++;
            bfsQue.push(j);
            while (bfsQue.size())
            {
                int curNode = bfsQue.front();
                bfsQue.pop();
                for (int i = 0; i < connection[curNode].size(); i++)
                {
                    int nextNode = connection[curNode][i];
                    if (!visited[nextNode])
                    {
                        bfsQue.push(nextNode);
                        visited[nextNode] = true;
                    }
                }
            }
        }
    }
}

int main()
{

    cin >> nodeConunt >> lineCount;

    for (int i = 0; i < lineCount; i++)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        connection[nodeA].push_back(nodeB);
        connection[nodeB].push_back(nodeA);
    }
    bfs();
    cout << connectedCount;
}