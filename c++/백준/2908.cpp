#include <iostream>
using namespace std;
int main()
{
    int a, b;
    int bandeA = 0, bandeB = 0;
    cin >> a >> b;
    for (int i = 0; i < 3; i++)
    {
        int multiplier;
        if (i == 0)
        {
            multiplier = 100;
        }
        if (i == 1)
        {
            multiplier = 10;
        }
        if (i == 2)
        {
            multiplier = 1;
        }
        bandeA += (a % 10) * multiplier;
        bandeB += (b % 10) * multiplier;
        a = a / 10;
        b = b / 10;
    }
    cout << max(bandeA, bandeB);
}