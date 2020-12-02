#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    int a[10] = {4, 2, 10, 15, 2, 6, 10, 0, 8, 12};
    sort(a, a + 10);
    for (auto const &var : a)
    {
        cout << var << "; ";
    }
    cout << endl;
    sort(a, a + 10, compare);
    for (auto const &var : a)
    {
        cout << var << "; ";
    }
    cout << endl;
    sort(a, a + 10, greater<int>());
    for (auto const &var : a)
    {
        cout << var << "; ";
    }
    cout << endl;
    sort(a, a + 10, less<int>());
    for (auto const &var : a)
    {
        cout << var << "; ";
    }
    cout << endl;
    partial_sort(a, a + 5, a + 10, greater<int>());
    for (auto const &var : a)
    {
        cout << var << "; ";
    }
    cout << endl;
    vector<int> vec{5, 4, 1, 2, 12, 5, 2};
    partial_sort(vec.begin(), vec.begin() + 3, vec.end());
    for (auto const &var : vec)
    {
        cout << var << "; ";
    }
}