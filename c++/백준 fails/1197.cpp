// // 크루스갈 알고리즘
// // 아무런 시작 지점을 고른다.
// // 시작 지점의 간선들을 저장한다.
// // 간선들 중 가장 weight가 적은 간선을 고른다.
// // 고른 간선을 이동하고 저장에서 삭제한다.
// // 이동한 노드에 연결된 간선을 저장한다.
// // 반복
// // 모든 노드를 저장하며 이동을 완료했다면 종료한다.
// // 이동하면서 weight의 가중치 또한 저장한다.

// #include <iostream>
// #include <tuple>
// #include <vector>
// #include <deque>
// using namespace std;

// // tuple<노드 b, 가중치> tree[노드a]
// vector<pair<int, int>> tree[100001];

// // 목적지 노드, 가중치
// deque<pair<int, int>> cruthQue;

// // 방문한 적이 있는가?
// bool visited[100001];

// // weight의 누적
// long long weightCount = 0;

// void cruthugal()
// {
//     while (cruthQue.size())
//     {
//         // 가중치가 가장 적으며, 방문한 적이 없는 노드를 방문한다.
//         int leastWeight = 0;
//         int leastWeightIndex = 0;
//         for (int i = 0; i < cruthQue.size(); i++)
//         {
//             if (!visited[cruthQue[i].first])
//             {
//                 if (leastWeight == 0 || cruthQue[i].second < leastWeight)
//                 {
//                     leastWeight = cruthQue[i].second;
//                     leastWeightIndex = i;
//                 }
//             }
//         }
//         }
// }

// int main()
// {
//     // 입력을 받는다.
//     int nodeCount, edgeCount;
//     cin >> nodeCount >> edgeCount;
//     for (int i = 0; i < edgeCount; i++)
//     {
//         int a, b, weight;
//         cin >> a >> b >> weight;
//         tree[a].push_back(make_pair(b, weight));
//     }
//     //1번 노드에 연결된 모든 엣지를 저장한다.
//     for (int i = 0; i < tree[1].size(); i++)
//         cruthQue.push_back(make_pair(tree[1][i].first, tree[1][i].second));

//     cruthugal();
// }

// 시간초과
// https://www.youtube.com/watch?v=LQ3JHknGy8c
// 각 간선을 오름차순으로 정리하는 것이 나와 다르다.
// 나는 for loop으로 하였지만 sort를 하도록 하자.

// 해석
// findParent는 재귀적으로 노드의 부모를 부르는 function으로 결국 부모에 다다르게 된다.
// merge는 각 노드의 값에 findparent를 불러 합치는데 findParent의 루트를 비교하는 이유는
// 같은 집합에 포함되는지의 여부를 확인하기 위해서이다. 그 이후 크기가 더 작은 집합을
// 큰 집합에 합치고, 노드를 잇는다. 기능이 다 구현됬다면 각 노드의 입력을 받으면서
// 엣지의 struct로 저장하며 가중치를 기준으로 오름차순 정렬하고 각 엗지의 좌, 우의 루트 노드가
// 일치하지 않는다면, (같은 집합의 노드가 아니라면) 길이를 더하고 노드를 병합한다.

// 나의 코드와의 차이
// struct를 사용
// bool operator<Edge const &e>
// 크루스갈 알고리즘 암기하자.
// 그리고 그 이전 union find 알고리즘에 대하여 배우도록 하자.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 10000 + 1;
int parent[MAX], setSize[MAX];
// 루트를 찾는 함수
int findParent(int node)
{
    // 현제 노드가 집합의 루트라면
    // 자신이 속한 집합을 찾았으므로 node 반환
    if (node == parent[node])
        return node;
    // 현제 노드가 집합의 루트가 아니라면
    // 노드의 루트에 대해 재귀 호출하면서 parent[node] 업데이트
    return parent[node] = findParent(parent[node]);
}

// 집합을 합치는 함수
void merge(int node1, int node2)
{
    node1 = findParent(node1);
    node2 = findParent(node2);
    //같은 집합이 아닐 경우에만 합친다
    if (node1 != node2)
    {
        //크기가 더 큰 집합으로 작은 집합이 들어감
        if (setSize[node1] < setSize[node2])
            swap(node1, node2);
        parent[node2] = node1;            //node2 집합이 node1에 합쳐짐
        setSize[node1] += setSize[node2]; //node1의 집합 크기가 커짐
        setSize[node2] = 0;               //node2가 node1에 흡수되므로
    }
}

//간선을 표현하는 구조체
struct Edge
{
    int u, v, weight; //u, v는 정점
    //weight는 가중치
    //정렬을 위해 오버로딩
    bool operator<(Edge const &e)
    {
        return weight < e.weight;
    }
};

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int V, E;
    cin >> V >> E;
    vector<Edge> edge;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
    //간선의 가중치를 기준으로 오름차순 정렬
    sort(edge.begin(), edge.end());
    //초기화
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        setSize[i] = 1;
    }
    long long result = 0;
    for (int i = 0; i < edge.size(); i++)
    {
        Edge e = edge[i];
        //같은 집합이 아닐 때만 추가
        if (findParent(e.u) != findParent(e.v))
        {
            result += e.weight;
            merge(e.u, e.v);
        }
    }
    cout << result << "\n";
    return 0;
}