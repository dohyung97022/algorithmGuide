#include <iostream>
#include <queue>
using namespace std;

// front, back, push, pop, empty, size

// pop은 값을 리턴하지 않는다.
// front와 back은 값을 리턴한다.
int que()
{
    queue<int> que;
    que.push(3);
    int v = que.back();
    cout << v;
}

// double ended que
int deque()
{
    queue<int> que;
    que.push(3);
    int v = que.back();
    cout << v;
}
