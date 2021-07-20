// 나의 실패한 코드...

// #include <iostream>
// #include <queue>
// #include <tuple>
// using namespace std;
// int N, M, x, y, drillBool, tmpInt, nx, ny, stepCount;
// string input;
// int dx[4]{0, 0, 1, -1};
// int dy[4]{1, -1, 0, 0};
// // tuple < x, y, 벽 뚥기 가능?, 걸음걸이 횟수 >
// queue<tuple<int, int, int, int>> bfsQue;
// // 0 뚤림 1 벽
// int map[1001][1001]{
//     0,
// };
// int bfs()
// {
//     while (bfsQue.size())
//     {
//         x = get<0>(bfsQue.front());
//         y = get<1>(bfsQue.front());
//         drillBool = get<2>(bfsQue.front());
//         stepCount = get<3>(bfsQue.front());
//         if (x == N - 1 && y == M - 1)
//         {
//             return stepCount;
//         }
//         bfsQue.pop();
//         for (tmpInt = 0; tmpInt < 4; tmpInt++)
//         {
//             nx = x + dx[tmpInt];
//             ny = y + dy[tmpInt];
//             // 기본조건
//             if (nx >= 0 && ny >= 0 && nx < N && ny < M)
//             {
//                 // 벽이 있으며 드릴이 가능한 경우
//                 if (map[nx][ny] == 1 && drillBool == 1)
//                 {
//                     drillBool = 0;
//                     goto goAble;
//                 }
//                 // 벽이 없는 경우
//                 else if (map[nx][ny] == 0)
//                 {
//                 goAble:
//                     // cout << "going to " << ny << " " << nx << " " << drillBool << endl;
//                     bfsQue.push(make_tuple(nx, ny, drillBool, stepCount++));
//                 }
//             }
//         }
//     }
//     return -1;
// }

// //결정을 내려야 한다...
// //

// int main()
// {
//     cin >> N >> M;
//     for (x = 0; x < N; x++)
//     {
//         cin >> input;
//         for (y = 0; y < M; y++)
//         {
//             map[x][y] = (int)input[y] - 48;
//         }
//     }
//     bfsQue.push(make_tuple(0, 0, 1, 1));
//     cout << bfs();
// }

// 반례예상
// 불가능한 경우
//맵이 1,2일 경우

// https://kscodebase.tistory.com/66
//이사람 설명이 좋고 풀이방식이 창의적이다.
// 벽을 부순 세계와 안부순 세계로 나눴다.
// 안타깝게도 시간이 없지만 코드는 다 확인하였고 이해하였으니 다음번에는 맞아보자.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[1001][1001];
int visited[1001][1001][2];
// bool로 만드는 게 데이터 효율이 높긴 하겠지만, 여기다가 ++연산을 해서 이동 횟수를 기록할 생각이다.
// map에다가 기록해버리면 1이 되는 순간 벽으로 취급될 테니 꼬인다.

int xMove[4] = {0, 0, -1, 1};
int yMove[4] = {1, -1, 0, 0};
// 항상 느끼지만, yMove를 입력할 때 나는 상하좌우라고 생각하며 입력하는데,
// 실제 지도는 왼쪽 위가 0,0 또는 1,1로 기준 잡히기 때문에 상하가 뒤집힌다.
// 지금까지 모든 문제를 그리 풀었고 문제 없었지만 인간을 기준으로 한 게 아니라 헷갈리겠다.

typedef struct pos
{
    int y;
    int x;
    int breakingWall;
    // 만약 0라면 벽을 1번 부술 수 있는 기회가 있고, 아니면 없다.
    // 생각해보니 이거 백트래킹으로 풀어도 될 거 같은 느낌이 든다. (간질간질)
    // 코드 짤 때 주석달면서 문제를 푸니까, 논리적 흐름이 다 기록되서 훨씬 잘 되는 거 같고,
    // 그리고 마치 대화하는 기분이라 코딩이 재밌다.
    // 이거 완전히 히키코모리, 아싸 새끼 아닐까.
} pos;

int bfs(void)
{
    queue<pos> Q;
    visited[1][1][0] = 1;
    Q.push({1, 1, 0});

    while (!Q.empty())
    {
        pos cur = Q.front();
        Q.pop();

        if (cur.y == n && cur.x == m)
            return visited[cur.y][cur.x][cur.breakingWall];
        // 중간에 벽을 부쉈는지 안 부쉈는지 모르니까 cur.breakingWall이 0인지 1인지는 알 수 없다.

        for (int i = 0; i < 4; i++)
        {
            pos next;
            next.y = cur.y + yMove[i];
            next.x = cur.x + xMove[i];
            next.breakingWall = cur.breakingWall;
            //            필요한 것은 지금까지 벽을 부쉈는지 유무라 next의 값이 필요하지가 않다.
            //            근데 초기화 안하면 실행이 안되니까 그냥 cur의 해당 값을 넣어줬다.

            if (next.y <= 0 || next.y > n || next.x <= 0 || next.x > m)
                continue;
            if (visited[next.y][next.x][cur.breakingWall])
                continue;
            // 벽을 부수고 도달했든 부수지 않고 도달했든 방문한 적이 있으면 continue한다.
            // 이 if문이 매우 매우 매우 중요하다, 노트북에 대고 빨간펜으로 동그라미칠 만큼 중요하다.

            // 나는 이 if문을 잘못 작성하는 바람에, 손으로 하나 하나 다 그리는 고생을 해야 했다.
            // if(visited[][][])의 꼴에서 세번째 [] 구간이 cur.breaking이라는 점.
            // 만약 visited[next.y][next.x][0]을 출력한다면 벽을 뚫고 가지 않은 상태로 출력될 것이고
            // 만약 visited[next.y][next.x][1]을 출력한다면 벽을 뚫고 간 경우의 평행세계가 출력된다.
            // ([1]의 세계는, 0으로부터 영향을 받아서, 그냥 보기엔 이해가 안 갈 수도 있을 것이다.)

            // 우리는 0에서 0으로 가는 경우, 0에서 1로 가는 경우, 1에서 0으로 가는 경우를 고려해야한다.
            // 문제는 1에서 0으로 가는 경우에는, 여전히 [1]의 세계에 있어야 한다는 점이다.
            // [1]의 세계에 있음은, 1에서 0으로 갔어도 벽을 뚫고 갔던 적이 있음을 나타내야 하기 때문이다.

            if (map[next.y][next.x] == 0)
            {
                visited[next.y][next.x][next.breakingWall] = visited[cur.y][cur.x][cur.breakingWall] + 1;
                Q.push({next.y, next.x, cur.breakingWall});
            }
            if (map[next.y][next.x] == 1 && next.breakingWall == 0)
            {
                visited[next.y][next.x][1] = visited[cur.y][cur.x][cur.breakingWall] + 1;
                next.breakingWall = 1;
                // next.breakingWall + 1인 부분이 차이점이다, 만약 +1을 빼버리면
                // 0에 값이 대입이 될 거고, 아래 Q.push에는 1이 대입이 되어 값 전달을 새로 시작해버린다.
                Q.push(next);
            }
            // dfs였다면 cur.breakingWall 이라는 것 대신에 매개변수를 한 개 더 쳐넣었을 것이다.
            // 이 차이 때문에 백트래킹도 가능할 거라고 생각한 것.
            // 백트래킹이 뭐냐고... 묻는다면, 현재의 진행 상황을 매개변수로 가지고 있어서,
            // 이후의 값들을 탐색할 필요가 없을 경우 탐색 가능한 지점으로 돌아가는 알고리즘이다.
        }
    }

    return -1;
    // 이 고생하고도 n, m 지점으로 가지 못했으면 -1을 반환한다, 답이 없다.
}

int main(void)
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            //            cin >> map[i][j];
            scanf("%1d", &map[i][j]);
        }
    }

    cout << bfs();

    /*
    cout << endl << endl;
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << visited[i][j][0] << "  ";
        }
        cout << endl;
    }
 
    cout << endl;
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << visited[i][j][1] << "  ";
        }
        cout << endl;
    }
    */
    // 문제를 찾기 위해서 visited 기록을 모두 출력해봤다.
    // 맞는 코드를, 내 딴에는 고친다고 했던 것이 한 시간을 잡아먹었다.
}
