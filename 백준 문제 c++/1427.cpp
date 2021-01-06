#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int input, placeNumber;
    vector<int> sortVec;
    cin >> input;
    while (input / 10 != 0 || input % 10 != 0)
    {
        placeNumber = input % 10;
        sortVec.push_back(placeNumber);
        input = input / 10;
    }
    sort(sortVec.begin(), sortVec.end(), greater<int>());
    for (auto const &val : sortVec)
    {
        cout << val;
    }
}