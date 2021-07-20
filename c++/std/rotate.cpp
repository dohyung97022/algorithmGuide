#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    rotate(v.begin(), v.begin() + 3, v.end());
    for (auto const &val : v)
    {
        cout << val << "; ";
    }
    cout << endl;
    vector<int> copyV(9);
    rotate_copy(v.begin(), v.begin() + 3, v.end(), copyV.begin());
    for (auto const &val : copyV)
    {
        cout << val << "; ";
    }
}