#include <bits/stdc++.h>
using namespace std;

void count()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9};
    cout << count(v.begin(), v.end(), 9) << endl;
}

void countIf()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 7, 7, 7};
    auto isOdd = [](auto i) { return i % 2 == 1; };
    cout << count_if(v.begin(), v.end(), isOdd);
}

void accum()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 7, 7, 7};
    cout << accumulate(v.begin(), v.end(), 0);
}
//lower bound returns equal or greater than
//upper bound returns greater than
void lowerb()
{
    int k;
    vector<int> v{4, 42, 1, 65, 2, 4, 8, 5, 14};
    sort(v.begin(), v.end());
    auto lb = lower_bound(v.begin(), v.end(), 50);
    cout << to_string(*lb);
}
//max_element
//min_element
void maxEl()
{
    vector<int> v{4, 42, 1, 65, 2, 4, 8, 5, 14};
    cout << to_string(*max_element(v.begin(), v.end()));
}
int main()
{
    lowerb();
}
