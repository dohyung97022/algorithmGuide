//실제로는 전혀 몰라서 틀린 문제.
//재귀함수 생각보다 햇갈린다.

#include <iostream>
using namespace std;

int getFibo(int a)
{
    if (a == 0)
        return 0;
    if (a == 1)
        return 1;
    return getFibo(a - 2) + getFibo(a - 1);
}
int main()
{
    int a;
    cin >> a;
    cout << getFibo(a);
}