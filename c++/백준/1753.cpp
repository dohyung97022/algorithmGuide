// #include <iostream>
// #include <queue>
// using namespace std;

// int nodeCount, lineCount, startNode;
// // 메모리 초과....
// // vector를 사용해야 한다.
// int nodeMap[20001][20001];
// int shortest[20001];
// // 이동 노드, 누적 거리
// queue<pair<int, int>> bfsQue;

// void bfs()
// {
//     while (bfsQue.size())
//     {
//         int curNode = bfsQue.front().first;
//         int accumLen = bfsQue.front().second;

//         bfsQue.pop();
//         for (int i = 1; i <= nodeCount; i++)
//         {
//             // 선이 존재한다.
//             if (nodeMap[curNode][i])
//             {
//                 int lineLen = accumLen + nodeMap[curNode][i];
//                 // 그 노드로 이동하는 최단 거리이다.
//                 if (shortest[i] == 0 || shortest[i] > lineLen)
//                 {
//                     shortest[i] = lineLen;
//                     bfsQue.push(make_pair(i, lineLen));
//                 }
//             }
//         }
//     }
// }

// int main()
// {
//     cin >> nodeCount >> lineCount;
//     cin >> startNode;
//     for (int i = 0; i < lineCount; i++)
//     {
//         int fromNode, toNode, lineWeight;
//         cin >> fromNode >> toNode >> lineWeight;

//         if (nodeMap[fromNode][toNode] == 0 || nodeMap[fromNode][toNode] > lineWeight)
//             nodeMap[fromNode][toNode] = lineWeight;
//     }
//     bfsQue.push(make_pair(startNode, 0));
//     bfs();
//     cout << "0\n";
//     for (int i = 2; i <= nodeCount; i++)
//     {
//         if (shortest[i])
//             cout << shortest[i] << "\n";
//         else
//             cout << "INF\n";
//     }
// }

// 메모리 초과
// 알고보니 다익스트라 알고리즘을 사용하는 방법이였다...
// 다익스트라 알고리즘을 공부하고
// 1시간이 초과하였기에 여기까지.

#include <iostream>
#include <queue>
#include <vector>

#define endl "\n"
#define MAX 20010
#define INF 987654321
using namespace std;

int V, E, Start;
int Dist[MAX];
vector<pair<int, int>> Vertex[MAX];

void Input()
{
    cin >> V >> E >> Start;
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Vertex[a].push_back(make_pair(b, c));
    }
    for (int i = 1; i <= V; i++)
        Dist[i] = INF;
}

void Solution()
{
    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, Start));
    Dist[Start] = 0;

    while (PQ.empty() == 0)
    {
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();

        for (int i = 0; i < Vertex[Cur].size(); i++)
        {
            int Next = Vertex[Cur][i].first;
            int nCost = Vertex[Cur][i].second;

            if (Dist[Next] > Cost + nCost)
            {
                Dist[Next] = Cost + nCost;
                PQ.push(make_pair(-Dist[Next], Next));
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (Dist[i] == INF)
            cout << "INF" << endl;
        else
            cout << Dist[i] << endl;
    }
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}