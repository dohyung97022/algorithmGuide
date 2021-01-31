// #include <iostream>
// using namespace std;
// int main()
// {
//     int givenArrayLen, wantedLen;
//     cin >> givenArrayLen >> wantedLen;
//     for (int i = 1; i <= givenArrayLen; i++)
//     {
//         for (int j = i + 1; j <= givenArrayLen; j++)
//         {
//             for (int k = j + 1; k <= givenArrayLen; k++)
//             {
//             }
//         }
//     }
// }

// 실패...

// #include <iostream>
// #define MAX 9
// using namespace std;
// int n, m;
// int arr[MAX];
// int visited[MAX];
// void dfs(int untilNum, int cnt)
// {
//     if (cnt == m)
//     {
//         for (int i = 0; i < m; i++)
//             cout << arr[i] << " ";
//         cout << "\n";
//         return;
//     }
//     for (int i = 0; i <= n; i++)
//     {
//         if (!visited[i])
//         {
//             visited[i] = true;
//             arr[cnt] = i;
//             dfs(i + 1, cnt + 1);
//             visited[i] = false;
//         }
//     }
// }
// int main()
// {
//     cin >> n >> m;
//     dfs(1, 0);
// }

// 이해를 완료하고
// 안보고 따라적긴 했지만
// 가령 기억에 나지 않는다면
// 이것을 다시 생각해 낼 수 있을지
// 이러한 코드를 짤 수 있을지 의심이다...

#include <iostream>
using namespace std;

const int MAX = 8;

int n, m;
int array[MAX];
int visited[MAX];

void dfs(int num, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << array[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = num; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            array[cnt] = i;
            dfs(i + 1, cnt + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    dfs(1, 0);
}