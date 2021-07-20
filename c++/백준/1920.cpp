#include <bits/stdc++.h>
using namespace std;

vector<int> getVector()
{
    int a;
    vector<int> av;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int x;
        cin >> x;
        av.push_back(x);
    }
    return av;
}

int binarySearch(vector<int> &vec, int target)
{
    int start = 0;
    int end = vec.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (vec[mid] == target)
        {
            return 1;
        }
        else if (vec[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return 0;
}

int main()
{
    vector<int> av = getVector();
    //이분탐색을 하려고 한다면 탐색을 하는 벡터는 정렬되어 있어야 한다.
    sort(av.begin(), av.end());
    vector<int> bv = getVector();
    for (auto const &val : bv)
    {
        cout << binarySearch(av, val) << "\n";
    }
}