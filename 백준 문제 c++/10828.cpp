#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int testCase;
    cin >> testCase;
    stack<int> stk;
    while (testCase--)
    {
        string command;
        int var;
        cin >> command;
        if (command == "push")
        {
            cin >> var;
            stk.push(var);
        }
        if (command == "pop")
        {
            if (stk.size() != 0)
            {
                cout << stk.top() << "\n";
                stk.pop();
            }
            else
            {
                cout << "-1\n";
            }
        }
        if (command == "size")
        {
            cout << stk.size() << "\n";
        }
        if (command == "empty")
        {
            cout << stk.empty() << "\n";
        }
        if (command == "top")
        {
            if (stk.size() != 0)
            {
                cout << stk.top() << "\n";
            }
            else
            {
                cout << "-1\n";
            }
        }
    }
}