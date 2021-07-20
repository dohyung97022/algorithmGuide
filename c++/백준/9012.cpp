#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        stack<bool> stk;
        string arryStr;
        cin >> arryStr;
        while (arryStr.size() != 0)
        {
            if (arryStr.back() == ')')
            {
                stk.push(true);
                arryStr.pop_back();
            }
            else if (arryStr.back() == '(')
            {
                if (stk.size() != 0)
                {
                    stk.pop();
                    arryStr.pop_back();
                }
                else
                {

                    goto end;
                }
            }
        }
        if (stk.size() != 0)
        {
        end:
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
}