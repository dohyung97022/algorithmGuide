#include <bits/stdc++.h>
using namespace std;
//set difference는 back_inserter를 사용한다는 것을 기억하자.
//차칩합
void setDif()
{
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 10, 12};
    vector<int> v2{5, 10, 12, 3, 4, 125, 623};
    vector<int> v3;
    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
    for (auto const &val : v3)
    {
        cout << val << "; ";
    }
}
//합집합, 겹칠 수 있다. 한번 겹치는 것은 제외하지만 두번째로 원소가 반복되면 없애지 않는다.
void setUni()
{
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 10, 12};
    vector<int> v2{5, 10, 5, 12, 3, 4, 125, 623};
    vector<int> v3;
    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
    for (auto const &val : v3)
    {
        cout << val << "; ";
    }
}
//교집합, 겹치는 원소는 없다.
void setIntersection()
{
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 10, 12};
    vector<int> v2{5, 10, 12, 5, 3, 4, 125, 623};
    vector<int> v3;
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
    for (auto const &val : v3)
    {
        cout << val << "; ";
    }
}
//교집합 제외 합집합, 다반 겹치는 원소가 있을 경우 그 원소를 2번 이상 빼지 않는다.
void setSymmetricDifference()
{
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 10, 12};
    vector<int> v2{5, 10, 12, 5, 3, 4, 125, 623};
    vector<int> v3;
    set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
    for (auto const &val : v3)
    {
        cout << val << "; ";
    }
}
// 겹치는 것 전혀 신경 쓰지 않고 그냥 합한다. 다만 순서는 유지되지 않는다.
void mrg()
{
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 10, 12};
    vector<int> v2{5, 10, 12, 5, 3, 4, 125, 623};
    vector<int> v3;
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
    for (auto const &val : v3)
    {
        cout << val << "; ";
    }
}
int main()
{
    mrg();
}
