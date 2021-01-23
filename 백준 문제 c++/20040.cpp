#include <iostream>
#include <string.h>
using namespace std;

const int MAX = 500001;
int rootMap[MAX];

int find(int a)
{
    if (rootMap[a] == a)
        return a;
    else
        return rootMap[a] = find(rootMap[a]);
}

bool unionn(int a, int b)
{
    int fa = find(a);
    int fb = find(b);
    if (fa == fb)
        return true;
    if (fa < fb)
        rootMap[fb] = fa;
    else
        rootMap[fa] = fb;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int pointCount, lineCount;
    cin >> pointCount >> lineCount;

    for (int i = 0; i <= pointCount; i++)
        rootMap[i] = i;

    bool possible = false;
    for (int i = 1; i <= lineCount; i++)
    {
        int a, b;
        cin >> a >> b;
        if (unionn(a, b))
        {
            cout << i;
            possible = true;
            break;
        }
    }
    if (!possible)
        cout << 0;
}