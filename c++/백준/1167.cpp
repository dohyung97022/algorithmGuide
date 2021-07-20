// 내가 짠 코드

// #include <iostream>
// #include <queue>
// #include <deque>
// using namespace std;

// // tree[a노드는] <b노드와, w만큼의 거리>
// deque<pair<int, int>> tree[100001];
// // queue<node, lengthcount>
// queue<pair<int, int>> bfsQue;
// deque<int> singleConnectedNodes;

// int bfs()
// {
//     int maxLen = 0;
//     while (bfsQue.size())
//     {
//         int node = bfsQue.front().first;
//         int lengthCount = bfsQue.front().second;
//         if (maxLen < lengthCount)
//             maxLen = lengthCount;
//         for (int i = 0; i < tree[node].size(); i++)
//         {
//                 }
//     }
// }

// int main()
// {
//     int nodeNum;
//     cin >> nodeNum;
//     for (int i = 0; i < nodeNum; i++)
//     {
//         int nodeInput, weightInput, currentNode, connectCount = 0;
//         cin >> currentNode;
//         while (true)
//         {
//             cin >> nodeInput;
//             if (nodeInput == -1)
//                 goto nextNodeBreak;
//             cin >> weightInput;
//             connectCount++;
//             tree[currentNode].push_back(make_pair(nodeInput, weightInput));
//         }
//     nextNodeBreak:
//         if (connectCount == 1)
//             singleConnectedNodes.push_back(currentNode);
//     }
//     int maxLen = 0;
//     for (auto const &val : singleConnectedNodes)
//     {
//         bfsQue.push(make_pair(val, 0));
//         int bfsRes = bfs();
//         if (maxLen < bfsRes)
//             maxLen = bfsRes;
//     }
//     cout << maxLen;
// }

//나와 다른 점은

// root노드를 1로 이해했다는 점
// -지문의 이해가 부족했다.

// memset을 알고 있다는 점
// -memset은 어떤 변수의 특정한 지점에서 어디까지 모두 특정한 값으로 지정하는 방법이다.

// 트리에서 가장 긴 지름을 찾는 방법을 알고 있다는 점
// -루트에서 가장 먼 정점 찾고 해당 정점에서 가장 먼 정점까지의 거리가 트리 지름이다.

// 재귀함수를 사용했다는 점
// -이것은 그냥 preference

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> //memset
using namespace std;

const int MAX = 100000 + 1;
int V;
bool visited[MAX];
vector<pair<int, int>> graph[MAX];
int diameter = 0;
int farthestNode = 0;
void DFS(int node, int cost)
{
    //기저 사례: 이미 방문한 곳
    if (visited[node])
        return;
    visited[node] = true;
    //지름 업데이트
    if (diameter < cost)
    {
        diameter = cost;
        farthestNode = node;
    }
    for (int i = 0; i < graph[node].size(); i++)
        DFS(graph[node][i].first, cost + graph[node][i].second);
}
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상
    cin >> V;
    for (int i = 0; i < V; i++)
    {
        int node;
        cin >> node;
        while (1)
        {
            int node2, cost;
            cin >> node2;
            if (node2 == -1)
                break;
            cin >> cost;
            graph[node].push_back({node2, cost});
        }
    }
    memset(visited, false, sizeof(visited));
    //루트에서 가장 먼 정점 찾고
    DFS(1, 0);
    //해당 정점에서 가장 먼 정점까지의 거리가 트리 지름의 정해
    memset(visited, false, sizeof(visited));
    diameter = 0;
    DFS(farthestNode, 0);
    cout << diameter << "\n";
    return 0;
}
