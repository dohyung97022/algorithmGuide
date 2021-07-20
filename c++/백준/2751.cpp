#include <bits/stdc++.h>
using namespace std;
bool byLesser(int x, int y)
{
    return x < y;
}
int main()
{
    int testCase;
    cin >> testCase;
    vector<int> vec;
    for (int i = 0; i < testCase; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end(), byLesser);
    for (auto const &val : vec)
    {
        cout << val << "\n";
    }
}