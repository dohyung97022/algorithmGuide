#include <iostream>
#include <queue>
#include <deque>
using namespace std;
int map[100001]{
    0,
};
int countMap[100001]{
    0,
};
queue<int> bfsQue;
int N, K, nx, x;

int bfs()
{
    while (bfsQue.size())
    {
        x = bfsQue.front();
        bfsQue.pop();
        deque<int> stepsDeq{x + 1, x - 1, x * 2};
        for (auto const &nx : stepsDeq)
        {
            // 다음 step
            if (nx >= 0 && nx <= 100000 && map[nx] == 0)
            {
                //queue에 푸쉬
                bfsQue.push(nx);
                //count에 이전 step에 더하기
                countMap[nx] = countMap[x] + 1;
                //map을 변경
                map[nx] = 1;
            }
            //찾은 경우
            else if (nx == K)
            {
                return countMap[x] + 1;
            }
        }
    }
}

int main()
{
    cin >> N >> K;
    if (N == K)
    {
        cout << 0;
        return 0;
    }
    map[N] = 1;
    map[K] = 2;
    bfsQue.push(N);
    cout << bfs();
    return 0;
}