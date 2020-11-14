#include <iostream>
using namespace std;
int main()
{
    int a, sum = 0;
    cin >> a;
    char b[a];
    cin >> b;
    for (int i = 0; i < a; i++)
    {
        sum += (int)b[i] - 48;
    }
    cout << sum;
}