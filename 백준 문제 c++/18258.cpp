// queue의 pop은 값을 주지 않으니까 front을 사용하자.
// 다음에는 que.size == 0 보다 que.empty를 사용하자.
#include <iostream>
#include <queue>
using namespace std;
void push(queue<int> &que, int value)
{
    que.push(value);
}
void pop(queue<int> &que)
{
    if (que.size() == 0)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << que.front() << "\n";
        que.pop();
    }
}
void size(queue<int> &que)
{
    cout << que.size() << "\n";
}
void empty(queue<int> &que)
{
    if (que.size() == 0)
    {
        cout << 1 << "\n";
    }
    else
    {
        cout << 0 << "\n";
    }
}
void front(queue<int> &que)
{
    if (que.size() == 0)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << que.front() << "\n";
    }
}
void back(queue<int> &que)
{
    if (que.size() == 0)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << que.back() << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    queue<int> que;
    int testCase;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        string command;
        cin >> command;
        if (command == "push")
        {
            int value;
            cin >> value;
            push(que, value);
        }
        if (command == "pop")
        {
            pop(que);
        }
        if (command == "size")
        {
            size(que);
        }
        if (command == "empty")
        {
            empty(que);
        }
        if (command == "front")
        {
            front(que);
        }
        if (command == "back")
        {
            back(que);
        }
    }
}