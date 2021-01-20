// 노드를 중심으로 bfs하면서 비행기의 종류는 누적되게 저장한다.(recursion, que?)
// 다만 이미 방문한 국가를 돌아가는 것은 어떻게 할까?
// 다른 국가를 거쳐가는 것은 어떻게 할까?
// ???

// failed...

// 모든 노드를 방문할 수 있는 경로가 존재한다.
// 간선이 노드-1개인 경우가 항상 최소이다.

// but why?????

// https://www.youtube.com/watch?v=cplfcGZmX7I
// 프림 알고리즘

// 모든 간선의 최소의 길이가 같다면, 또는 간선의 길이의 영향이 없다면
// 최소신장트리의 노드-1개의 엣지를 지나가게 된다.

#include <iostream>
using namespace std;

int main(void)
{
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int country, edges;
        cin >> country >> edges;
        for (int i = 0; i < edges; i++)
        {
            int a, b;
            cin >> a >> b;
        }
        cout << country - 1 << "\n";
    }
}
