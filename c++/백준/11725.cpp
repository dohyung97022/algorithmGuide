// DFS로 푸는 문제
// 트리의 구조는 처음이여서 조금 참고하고 코드는 안보며 직접
// 노드의 부모찾기 문제

#include <iostream>
#include <deque>
using namespace std;

int N, tmpInt, tmpInt2;

bool visited[100001];
int parent[100001];
deque<int> tree[100001];

void dfs(int node)
{
    visited[node] = true;
    for (auto const &next : tree[node])
    {
        //visited next의 확인은 안에 있어야 한다.
        //왜? why? parent[next] = node; 가 역으로 들어간다.
        if (visited[next] == false)
        {
            parent[next] = node;
            dfs(next);
        }
    }
}
int main()
{
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        cin >> tmpInt >> tmpInt2;
        tree[tmpInt].push_back(tmpInt2);
        tree[tmpInt2].push_back(tmpInt);
    }
    dfs(1);
    for (int i = 2; i <= N; i++)
    {
        cout << parent[i] << "\n";
    }
}