// 영 팩토리얼은 1이다....

#include <iostream>
using namespace std;
int factorial(int in)
{
    if (in == 1 || in == 0)
    {
        return 1;
    }
    return in * factorial(in - 1);
}

int main()
{
    int input;
    cin >> input;
    cout << factorial(input);
}
