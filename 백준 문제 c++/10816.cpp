//std binary search, upper_bound, lower_bound
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a;
    vector<int> aVec;
    for (int i = 0; i < a; i++)
    {
        int x;
        cin >> x;
        aVec.push_back(x);
    }
    cin >> b;
    vector<int> bVec;
    for (int i = 0; i < b; i++)
    {
        int x;
        cin >> x;
        bVec.push_back(x);
    }
    sort(aVec.begin(), aVec.end());
    for (auto const &val : bVec)
    {
        cout << upper_bound(aVec.begin(), aVec.end(), val) - lower_bound(aVec.begin(), aVec.end(), val) << " ";
    }
}