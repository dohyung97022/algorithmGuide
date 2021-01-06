#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> pointsVec;

bool sortPointsRule(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
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
        int x, y;
        cin >> x >> y;
        pointsVec.push_back(make_pair(x, y));
    }
    sort(pointsVec.begin(), pointsVec.end(), sortPointsRule);
    for (auto const &val : pointsVec)
    {
        cout << val.first << " " << val.second << "\n";
    }
}

// endl은 최대한 그냥 쓰지 말자...
// sort(vec.begin(), vec.end(), mySortFunc);
// 여기에서 function이 들어가는 방식은 ()가 없어서
// function 자체의 type으로 들어가는 것이다.

// pair를 function의 인자로 넣고 싶다면
// pair<int,int> 같이 pair에 들어가는 것을 정의하도록 한다.