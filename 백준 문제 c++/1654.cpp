#include <bits/stdc++.h>
using namespace std;
int main()
{
    int myStrings, needStrings;
    cin >> myStrings >> needStrings;
    vector<long long> myStringsVector;
    for (int i = 0; i < myStrings; i++)
    {
        long long x;
        cin >> x;
        myStringsVector.push_back(x);
    }
    long long end = *max_element(myStringsVector.begin(), myStringsVector.end());
    long long start = 1;
    while (end >= start)
    {
        long long mid = (end + start) / 2;
        int devidedCount = 0;
        for (auto const &val : myStringsVector)
        {
            devidedCount += val / mid;
        }
        if (devidedCount < needStrings)
        {
            end = mid - 1;
        }
        else
        //  if (devidedCount < needStrings - myStrings)
        {
            start = mid + 1;
        }
    }
    cout << (end + start) / 2;
}