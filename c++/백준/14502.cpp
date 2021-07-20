// // 풀이 옵션
// // 1. 모든 빈 공간 중 3곳의 조합을 통해 모든 안전지대의 수를 구하여
// // 최대 안전지대 값을 구한다?

// // 근거 : 지도의 크기의 최대학 8*8이라서 너무 많은 경우의 수를 구하지는 않는다.
// // 64P3

// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// int mapXLen, mapYLen;

// int dy[4] = {1, -1, 0, 0};
// int dx[4] = {0, 0, 1, -1};
// vector<pair<int, int>> initialVirusPosition;
// int virusWallCountInit = 3;
// int virusWallCount;
// int virusWallCountLeast = 3;
// int map[8][8];

// int walledMap[8][8];

// queue<pair<int, int>> bfsQue;

// // virusWallCount와 virus가 bfs에서 추가적으로 차지하는 칸을 더하면
// // 0을 제외한 모든 칸이 됨으로
// // map x*y에서 빼서 0의 칸을 구한다.

// void bfs()
// {
//     while (bfsQue.size())
//     {
//         int y = bfsQue.front().first;
//         int x = bfsQue.front().second;
//         bfsQue.pop();
//         // 4방향
//         for (int i = 0; i < 4; i++)
//         {
//             int ny = dy[i] + y;
//             int nx = dx[i] + x;
//             // 범위를 벗어나지 않는다.
//             if (ny >= 0 && mapYLen > ny && nx >= 0 && mapXLen > nx)
//             {
//                 // 벽이나 바이러스를 만나지 않는다.
//                 if (walledMap[ny][nx] != 1 && walledMap[ny][nx] != 2)
//                 {
//                     cout << "virus moving" << endl;
//                     cout << "ny" << ny << endl;
//                     cout << "nx" << nx << endl;
//                     walledMap[ny][nx] = 2;
//                     virusWallCount++;
//                     bfsQue.push(make_pair(ny, nx));
//                 }
//             }
//         }
//     }
// }

// void makeWall(int wallCount)
// {
//     if (wallCount == 3)
//     {
//         for (int i = 0; i < initialVirusPosition.size(); i++)
//             bfsQue.push(make_pair(initialVirusPosition[i].first, initialVirusPosition[i].second));
//         virusWallCount = virusWallCountInit;
//         cout << "bfs  start" << endl;
//         bfs();
//         cout << "bfs  end" << endl;
//         if (virusWallCountLeast > virusWallCount)
//             virusWallCountLeast = virusWallCount;
//         return;
//     }
//     else
//     {
//         for (int y = 0; y < mapYLen; y++)
//         {
//             for (int x = 0; x < mapXLen; x++)
//             {
//                 if (walledMap[y][x] == 0)
//                 {
//                     walledMap[y][x] = 1;
//                     makeWall(wallCount + 1);
//                     walledMap[y][x] = 0;
//                 }
//             }
//         }
//     }
// }

// int main()
// {

//     cin >> mapXLen >> mapYLen;
//     for (int y = 0; y < mapYLen; y++)
//         for (int x = 0; x < mapXLen; x++)
//         {
//             cin >> map[y][x];
//             if (map[y][x] != 0)
//                 virusWallCountInit++;
//             if (map[y][x] == 2)
//                 initialVirusPosition.push_back(make_pair(y, x));
//         }

//     // 지도에 벽을 세운다.
//     for (int y = 0; y < mapYLen; y++)
//     {
//         for (int x = 0; x < mapXLen; x++)
//         {
//             // 기존 지도에 빈 방이 있다면
//             if (map[y][x] == 0)
//             {
//                 // cout << "x " << x << endl;
//                 // cout << "y " << y << endl;
//                 // 맵을 복사한다.
//                 for (int ty = 0; ty < mapYLen; ty++)
//                     for (int tx = 0; tx < mapXLen; tx++)
//                         walledMap[ty][tx] = map[ty][tx];
//                 cout << "walled" << endl;
//                 cout << "x " << x << endl;
//                 cout << "y " << y << endl;
//                 walledMap[y][x] = 1;
//                 makeWall(1);
//                 walledMap[y][x] = 0;
//             }
//         }
//     }
//     // cout << virusWallCountLeast;
// }

// 이번에도 졌다
// 지면서 배우자.

// 모든 조합의 경우의 수를 구하는 방법으로 재귀적으로 호출하는 방법도 있다.
// makeWall()의 재귀적 함수호출
// for y , x loop을 하며
// map의 어떤 칸이 0일 경우 무조건 입력을 하며
// 3이 되면 bfs를 부른다.
// 입력이 되면 0이 아니게 됨으로 모든 경우의 수를 구할 수 있다.

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 8;
typedef struct
{
    int y, x;

} Dir;
Dir moveDir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int N, M;
int lab[MAX][MAX];
int temp[MAX][MAX];
int result;

void BFS(void)
{
    int afterSpread[MAX][MAX];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            afterSpread[i][j] = temp[i][j];
    queue<pair<int, int>> q; //y, x
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (afterSpread[i][j] == 2)  //바이러스라면
                q.push(make_pair(i, j)); //큐에 넣는다
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextY = y + moveDir[i].y;
            int nextX = x + moveDir[i].x;
            if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M) //범위 내
                if (afterSpread[nextY][nextX] == 0)                 //빈칸이라면
                {
                    afterSpread[nextY][nextX] = 2; //바이러스 감염
                    q.push(make_pair(nextY, nextX));
                }
        }
    }

    int empty = 0;
    //빈칸 세기
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (afterSpread[i][j] == 0)
                empty++;
    result = max(result, empty);
}

void makeWall(int cnt)
{
    if (cnt == 3) //벽을 세개 만들었으므로
    {
        BFS();
        return;
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (temp[i][j] == 0)
            {
                temp[i][j] = 1; //마찬가지로 해당칸에 새우고
                makeWall(cnt + 1);
                temp[i][j] = 0; //다시 허문다
            }
}

int main(void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> lab[i][j];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (lab[i][j] == 0) //빈칸 발견 시
            {
                //연구실 상태를 복사한다
                for (int k = 0; k < N; k++)
                    for (int l = 0; l < M; l++)
                        temp[k][l] = lab[k][l];
                temp[i][j] = 1; //해당 칸에 벽을 세운다
                makeWall(1);    //벽을 세운 상태이므로 cnt = 1
                temp[i][j] = 0; //다시 허문다
            }
    cout << result << endl;
    return 0;
}