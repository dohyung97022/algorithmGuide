#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    queue<int> que;
    int cardTotal;
    cin >> cardTotal;
    for (int i = 1; i <= cardTotal; i++)
    {
        que.push(i);
    }
    if (que.size() != 1)
    {
        que.pop();
    }
    while (que.size() != 1)
    {
        // 앞의 카드를 뒤에 놓는다.
        int v = que.front();
        que.pop();
        que.push(v);
        // 앞의 카드를 뺀다. 카드의 수가 변경됨으로 while의 조건을 확인한다.
        que.pop();
    }
    cout << que.front();
}