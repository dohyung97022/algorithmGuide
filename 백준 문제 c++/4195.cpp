// #include <iostream>
// #include <map>
// using namespace std;

// // union find
// // map<String has the root of pair<String, and the size of Int>>
// map<string, pair<string, int>> rootMap;

// string find(string friendA)
// {
//     if (rootMap[friendA].first == "")
//     {
//         rootMap[friendA].first = friendA;
//         rootMap[friendA].second = 1;
//     }
//     if (rootMap[friendA].first == friendA)
//     {
//         return friendA;
//     }
//     else
//         return find(rootMap[friendA].first);
// }

// void unionn(string friendA, string friendB)
// {
//     friendA = find(friendA);
//     friendB = find(friendB);
//     if (friendA != friendB)
//     {
//         rootMap[friendA].first = friendB;
//         rootMap[friendA].second += rootMap[friendB].second;
//         rootMap[friendB].second = rootMap[friendA].second;
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int testCase;
//     cin >> testCase;
//     while (testCase--)
//     {
//         int relationCount;
//         cin >> relationCount;
//         while (relationCount--)
//         {
//             string friendA, friendB;
//             cin >> friendA >> friendB;
//             unionn(friendA, friendB);
//             cout << rootMap[friendA].second << "\n";
//         }
//         rootMap.clear();
//     }
// }

// 시간초과

// string map의 경우 string을 index 처리하여 사용하자.
// 있는 것에서 수정하자.

#include <iostream>
#include <map>
using namespace std;

// union find
// map<Int has the root of pair<Int, and the size of Int>>
map<int, pair<int, int>> rootMap;

int find(int friendA)
{
    if (rootMap[friendA].second == 0)
    {
        rootMap[friendA].first = friendA;
        rootMap[friendA].second = 1;
    }
    if (rootMap[friendA].first == friendA)
        return friendA;
    else
        return find(rootMap[friendA].first);
}

void unionn(int friendA, int friendB)
{
    friendA = find(friendA);
    friendB = find(friendB);
    if (friendA != friendB)
    {
        rootMap[friendA].first = friendB;
        rootMap[friendA].second += rootMap[friendB].second;
        rootMap[friendB].second = rootMap[friendA].second;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int relationCount, idxCount = 0;
        cin >> relationCount;
        map<string, int> nameIdx;
        while (relationCount--)
        {
            string friendA, friendB;
            cin >> friendA >> friendB;
            if (nameIdx[friendA] == 0)
                nameIdx[friendA] = idxCount++;
            if (nameIdx[friendB] == 0)
                nameIdx[friendB] = idxCount++;
            unionn(nameIdx[friendA], nameIdx[friendB]);
            cout << rootMap[nameIdx[friendA]].second << "\n";
        }
        rootMap.clear();
    }
}