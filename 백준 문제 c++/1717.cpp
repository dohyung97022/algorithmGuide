// union find
#include <iostream>
using namespace std;

const int MAX_NODES = 1000001;

int root[MAX_NODES];

int find(int a)
{
    if (a == root[a])
        return a;
    else
        return root[a] = find(root[a]);
}
void unionn(int a, int b)
{
    int ar = find(a);
    int br = find(b);
    // 루트가 같지 않다면
    if (ar != br)
        // 연결한다.
        root[ar] = br;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int nodeCount, testCase;
    cin >> nodeCount >> testCase;

    // 모든 노드들의 루트를 자기 자신으로 지정한다.
    for (int i = 1; i <= nodeCount; i++)
        root[i] = i;

    // 입력을 받아 연산한다.
    while (testCase--)
    {
        int input1, input2, input3;
        cin >> input1 >> input2 >> input3;
        if (input1 == 0)
            unionn(input2, input3);
        else if (find(input2) == find(input3))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}