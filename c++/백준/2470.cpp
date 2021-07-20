
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> fluids;

int main()
{
    int fluidsLen;
    cin >> fluidsLen;
    while (fluidsLen--)
    {
        int input;
        cin >> input;
        fluids.push_back(input);
    }
    sort(fluids.begin(), fluids.end(), less<int>());

    int L = 0, R = fluids.size() - 1;
    int sum = fluids[L] + fluids[R];
    int La = L, Ra = R, closest = sum;
    while (L != R - 1 && sum != 0)
    {
        if (sum < 0)
            L++;
        else if (sum > 0)
            R--;
        sum = fluids[L] + fluids[R];
        if (abs(closest) > abs(sum))
        {
            La = L;
            Ra = R;
            closest = sum;
        }
    }
    cout << fluids[La] << " " << fluids[Ra];
}