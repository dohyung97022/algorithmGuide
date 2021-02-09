#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 2100000000;

// pair<거리, 노드> a[출발노드]
vector<pair<int, int>> a[7];
// 최소 거리
int d[7];

void dijkstra(int start)
{
    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty())
    {
        int distance = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        if (d[current] < distance)
            continue;
        for (int i = 0; i < a[current].size(); i++)
        {
            int next = a[current][i].second;
            int nextDistance = distance + a[current][i].first;
            if (nextDistance < d[next])
            {
                d[next] = nextDistance;
                pq.push(make_pair(next, -nextDistance));
            }
        }
    }
}

int main(void)
{
    // vector pair에 노드의 연결관계를 정의하고
    // d array에 INF로 초기화한다.
    // 변동된 d array가 모든 노드들로 가는 최소 비용으로 정의된다.
    memset(d, INF, 7);
}