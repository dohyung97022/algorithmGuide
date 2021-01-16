// #include <iostream>
// #include <queue>
// #include <map>
// #include <tuple>
// using namespace std;

// pair<int, int> directions[4]{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
// //A = 1
// int alphMap[21][21];
// int count = 0;
// // pair<현제 y, 현제 x, 방문 횟수, map<방문 알파벳, 방문 여부>>
// queue<tuple<int, int, int, map<int, bool>>> bfsQue;

// int height, width;

// void bfs()
// {
//     while (bfsQue.size())
//     {
//         int cy = get<0>(bfsQue.front());
//         int cx = get<1>(bfsQue.front());
//         int stepCount = get<2>(bfsQue.front());
//         map<int, bool> cMap = get<3>(bfsQue.front());

//         if (count < stepCount)
//             count = stepCount;

//         bfsQue.pop();
//         for (int i = 0; i < 4; i++)
//         {
//             int ny = directions[i].first + cy;
//             int nx = directions[i].second + cx;
//             int nAlph = alphMap[ny][nx];
//             if (ny >= 0 && nx >= 0 && ny < height && nx < width && cMap[nAlph] == false)
//             {
//                 cMap[nAlph] = true;
//                 bfsQue.push(make_tuple(ny, nx, stepCount + 1, cMap));
//                 cMap[nAlph] = false;
//             }
//         }
//     }
// }

// int main()
// {

//     cin >> height >> width;
//     for (int y = 0; y < height; y++)
//     {
//         string input;
//         cin >> input;
//         for (int x = 0; x < width; x++)
//         {
//             alphMap[y][x] = input[x] - 64;
//         }
//     }
//     map<int, bool> newMap;
//     newMap[alphMap[0][0]] = true;
//     bfsQue.push(make_tuple(0, 0, 1, newMap));
//     bfs();
//     cout << count;
// }

// 실패... memory loss

// 이제 메모리 loss 가 흔해졌다.
// 어떻게 해야 더 적은 변수들로 할 수 있는지 공간 복잡도를 더 고려하자.

// |= 이게 뭐지???
// 찾을 수가 없다...

// bitwise operator
// https://www.youtube.com/watch?v=xXKL9YBWgCY
// https://www.youtube.com/watch?v=yHBYeguDR0A
// 여기가 맞는 것 같은데...
// https://www.youtube.com/watch?v=FmY-PjukO8I

// xor 연산, a^b 둘중 하나만 true일 경우
// shift 연산자
// 밀어내는 개념이다.
// 1 << (board[y][x] - 'A')
// 1 << 4 = 이진수 10000 = 16 라는 뜻이다.

#include <iostream>

#include <string>

#include <algorithm>

using namespace std;

const int MAX = 20;

typedef struct

{

    int y, x;

} Dir;

Dir moveDir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int R, C;

int result;

string board[MAX];

void DFS(int y, int x, long long alphabet, int cnt)

{

    alphabet |= (1 << (board[y][x] - 'A')); //이미 밟은 알파벳 표시

    for (int i = 0; i < 4; i++)

    {

        int nextY = y + moveDir[i].y;

        int nextX = x + moveDir[i].x;

        if (0 <= nextY && nextY < R && 0 <= nextX && nextX < C) //범위 내에 있고

            if (!(alphabet & (1 << (board[nextY][nextX] - 'A')))) //새로운 알파벳일 경우에만

                DFS(nextY, nextX, alphabet, cnt + 1); //DFS
    }

    result = max(result, cnt);
}

int main(void)

{

    cin >> R >> C;

    for (int i = 0; i < R; i++)

        cin >> board[i];

    result = -1;

    DFS(0, 0, (long long)1 << 26, 1); //알파벳 A(0) ~ Z(25)

    cout << result << endl;

    return 0;
}