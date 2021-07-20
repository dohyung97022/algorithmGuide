#include <iostream>
#include <queue>
#include <deque>
using namespace std;

// front, back, push, pop, empty, size

// pop은 값을 리턴하지 않는다.
// front와 back은 값을 리턴한다.
// 일반 큐는 인덱스가 불가능 하다. 하지만 deque는 인덱스가 가능하다.
// deque와 벡터와 다른 점이라고 한다면 벡터는 뒤에서 push pop을 하는데
// deque는 앞과 뒤에서 push pop이 가능하다.

//벡터의 확장은 해당 값의 2배의 빈 벡터를 만드는데,
//deque는 훨씬 싼 값으로 확장이 가능하다.

//전방과 후방에 넣고 빼는데에는 0(N)의 수가 걸리는데
// 중간에 넣거나 빼는데 필요한 시간은 선형시간이 걸린다.
int que()
{
    queue<int> que;
    que.push(3);
    int v = que.back();
    cout << v;
}

// double ended que
int de()
{
    queue<int> que;
    que.push(3);
    int v = que.back();
    cout << v;
}
int main()
{
    deque<int> que;
    que.push_back(3);
    cout << que[0];
}