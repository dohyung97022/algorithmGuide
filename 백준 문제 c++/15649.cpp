#include <iostream>
using namespace std;

bool visited[9];
int visit[9];
int N, M;

void dfs(int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << visit[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++)
        if (!visited[i])
        {
            visited[i] = true;
            visit[cnt] = i;
            dfs(cnt + 1);
            visited[i] = false;
        }
}

int main()
{
    cin >> N >> M;
    dfs(0);
}