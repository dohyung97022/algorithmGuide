#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int xd[6] = {0, 0, 1, -1, 0, 0};
int yd[6] = {1, -1, 0, 0, 0, 0};
int zd[6] = {0, 0, 0, 0, 1, -1};

// map z x y
int map[101][101][101]{
    0,
};
int check_map[101][101][101]{
    0,
};
queue<tuple<int, int, int>> bfsQue;

int M, N, H, tmpInt, x, y, z, nz, nx, ny;

int bfs()
{
    while (bfsQue.size())
    {
        z = get<0>(bfsQue.front());
        x = get<1>(bfsQue.front());
        y = get<2>(bfsQue.front());
        bfsQue.pop();
        for (tmpInt = 0; tmpInt < 6; tmpInt++)
        {
            nz = z + zd[tmpInt];
            nx = x + xd[tmpInt];
            ny = y + yd[tmpInt];
            //모든 다음 xyz가 0<=xyz<=MNH 이며 map에서의 그 좌표가 0일 경우
            if (0 <= nz && 0 <= nx && 0 <= ny && nz < H && ny < N && nx < M && map[nz][nx][ny] == 0)
            {
                //해당 좌표를 1로 변환시키고
                map[nz][nx][ny] = 1;

                //check map에서 경과한 숫자를 적는다.
                check_map[nz][nx][ny] = check_map[z][x][y] + 1;

                // queue에 넣는다.
                bfsQue.push(make_tuple(nz, nx, ny));
            }
        }
    }
    return check_map[z][x][y];
}
int main()
{
    cin >> M >> N >> H;
    for (z = 0; z < H; z++) // z
    {
        for (y = 0; y < N; y++) // y
        {
            for (x = 0; x < M; x++) // x
            {
                cin >> tmpInt;
                if (tmpInt == 1)
                {
                    bfsQue.push(make_tuple(z, x, y));
                }
                map[z][x][y] = tmpInt;
            }
        }
    }
    tmpInt = bfs();
    for (z = 0; z < H; z++) // z
    {
        for (y = 0; y < N; y++) // y
        {
            for (x = 0; x < M; x++) // x
            {
                if (map[z][x][y] == 0)
                {
                    // not all filled
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << tmpInt;
    return 0;
}