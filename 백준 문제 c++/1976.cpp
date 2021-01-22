#include <iostream>
using namespace std;

const int MAX_CITY = 201;

int root[MAX_CITY];

int find(int a)
{
    if (root[a] == a)
        return a;
    else
        return root[a] = find(root[a]);
}

void unionn(int a, int b)
{
    int ra = find(a);
    int rb = find(b);
    // 이부분이 무한 루프의 원인!
    // 노드의 연결을 노드의 숫자 순서대로도 할 수 있다.
    if (ra > rb)
        root[ra] = rb;
    else
        root[rb] = ra;
}

int main()
{
    int cityCount, planVisitCount;
    cin >> cityCount >> planVisitCount;

    for (int i = 1; i <= cityCount; i++)
        root[i] = i;

    for (int i = 1; i <= cityCount; i++)
    {
        for (int j = 1; j <= cityCount; j++)
        {
            bool input;
            cin >> input;
            if (input)
                unionn(i, j);
        }
    }
    bool possible = true;
    int rootCheck;
    cin >> rootCheck;
    rootCheck = find(rootCheck);
    for (int i = 1; i < planVisitCount; i++)
    {
        int countryRootCheck;
        cin >> countryRootCheck;
        if (find(countryRootCheck) != rootCheck)
        {
            possible = false;
            break;
        }
    }
    if (possible)
        cout << "YES";
    else
        cout << "NO";
}