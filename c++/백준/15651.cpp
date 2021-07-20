// 이 문제도 방금 전 문제 15651처럼 재귀적으로 저장하며 bfs하는 식으로 하자.
// 그냥 for loop로 풀 수도 있겠지만
// 전의 기억을 되살리고 생각의 방향성을 위해 전의 방식을 비슷하게 모방해보자.

#include <iostream>
#define MAX 7
using namespace std;

int N, M;
int array[MAX];

void bfs(int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << array[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        array[cnt] = i;
        bfs(cnt + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> N >> M;
    bfs(0);
}