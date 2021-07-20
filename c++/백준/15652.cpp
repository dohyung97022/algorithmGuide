// 풀이
// function에 depth를 주며 재귀적으로 호출한다.
// depth가 자릿수를 넘을 경우 끝낸다.
// 그런데 그렇다면 depth에서 앞자리 수들은 어떻게 print할 생각?
// global의 deque로 지정하여 print 하자.

// #include <iostream>
// #include <deque>
// using namespace std;

// deque<int> deq;
// int nodeCount;
// int depthLimit;

// void recursive(int depth, int num)
// {
//     if (depth > depthLimit)
//         return;

//     for (auto const &val : deq)
//         cout << val << " ";
//     cout << num;
//     cout << "\n";
// }

// int main()
// {
//     cin >> nodeCount >> depthLimit;
// }

// 문제 이해 완료...
// 쉬운 문제였는데 왜 틀렸을까
// 조건을 잘 생각해보자.
// func 안에 들어간 cnt가 어쩔때 print를 해야하는지
// 어떤 때에 for loop의 조건이 어떻게 형성되는지.
// 다시 보고 다시 이해하자.

#include <iostream>
using namespace std;
const int MAX = 8 + 1;
int N, M;
int arr[MAX];
void func(int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = (cnt == 0) ? 1 : arr[cnt - 1]; i <= N; i++)
    {
        arr[cnt] = i;
        func(cnt + 1);
    }
}
int main(void)
{
    cin >> N >> M;
    func(0);
    return 0;
}