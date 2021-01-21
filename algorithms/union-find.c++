//https://www.youtube.com/watch?v=0jNmHPfA_yE
//https://gmlwjd9405.github.io/2018/08/31/algorithm-union-find.html

#include <iostream>
using namespace std;

const int MAX_SIZE = 100001;
int root[MAX_SIZE];
int parent[MAX_SIZE];
int length[MAX_SIZE];

int find(int x)
{
    if (root[x] == x)
        return x;
    else
        return find(root[x]);
    // 경로 압축을 하고 싶다면
    // return root[x] = find(root[x]);
}

void unionn(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    // 사이즈가 더 작은 집합을 더 큰 집합에 넣기도 한다.
    // 무조건적으로 따라지지는 않는 것 같다.
    if (length[x] < length[y])
        root[x] = y;
    else
        root[y] = x;
    if (length[x] == length[y])
        length[x]++;
}

int main()
{
    // 처음 초기화함
    // youtube에서는 map의 형태로 저장하라는 것 같기도 하지만 마음대로 해도 된다.
    // index mapping을 하기 위해서 이렇게 한 것.
    for (int i = 0; i < MAX_SIZE; i++)
        parent[i] = i;
}