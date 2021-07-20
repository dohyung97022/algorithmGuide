#include <iostream>
using namespace std;
#include <stack>
#include <string>
// Help( I[m being held prisoner in a fortune cookie factory)].
int main()
{
    string input;
    while (getline(cin, input))
    {
        if (input == ".")
        {
            break;
        }
        // ] true
        // ) false
        //true 이여야지만 [가 가능하고
        //false 이여야지만 (가 가능해진다.
        stack<bool> gwalHo;
        while (input.size() != 0)
        {
            if (input.back() == ']')
            {
                gwalHo.push(true);
            }
            else if (input.back() == '[')
            {
                if (gwalHo.size() != 0 && gwalHo.top() == true)
                {
                    gwalHo.pop();
                }
                else
                {
                    goto no;
                }
            }
            else if (input.back() == ')')
            {
                gwalHo.push(false);
            }
            else if (input.back() == '(')
            {
                if (gwalHo.size() != 0 && gwalHo.top() == false)
                {
                    gwalHo.pop();
                }
                else
                {
                    goto no;
                }
            }
            input.pop_back();
        }
        //check if stack is empty
        if (gwalHo.size() == 0)
        {
            //yes
            cout << "yes\n";
        }
        else
        {
        no:
            //no
            cout << "no\n";
        }
    }
}