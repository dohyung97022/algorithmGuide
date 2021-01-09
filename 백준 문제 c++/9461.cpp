#include <iostream>
using namespace std;

long long padoban[101]{0, 1, 1, 1, 2, 2};

long long padobanSolve(int idx)
{
    //값이 지정된 적이 없다면
    if (padoban[idx] == 0)
        padoban[idx] = padobanSolve(idx - 3) + padobanSolve(idx - 2);
    return padoban[idx];
}

int main()
{
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int test;
        cin >> test;
        cout << padobanSolve(test) << "\n";
    }
}