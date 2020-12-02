#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> intVec{1, 4, 2, 5, 1, 2, 2, 3, 5};
    reverse(intVec.begin(), intVec.end());
    for (auto const &val : intVec)
    {
        cout << val << "; ";
    }
    cout << endl;
    vector<int> copyIntVec(9);
    reverse_copy(intVec.begin(), intVec.end(), copyIntVec.begin());
    for (auto const &val : copyIntVec)
    {
        cout << val << "; ";
    }
}