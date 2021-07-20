#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int testCase, tmp;
    stack<int> stk;
    cin >> testCase;
    while (testCase--)
    {
        cin >> tmp;
        if (tmp == 0 && stk.size() != 0)
        {
            stk.pop();
        }
        else
        {
            stk.push(tmp);
        }
    }
    tmp = 0;
    while (stk.size() != 0)
    {
        tmp += stk.top();
        stk.pop();
    }
    cout << tmp;
}