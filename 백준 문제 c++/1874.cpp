#include <iostream>
#include <deque>
#include <stack>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int aryLen, tmp;
    cin >> aryLen;
    deque<int> giveAry;
    deque<int> answerAry;
    stack<int> stk;
    string ansStr;
    while (aryLen--)
    {
        giveAry.push_front(aryLen + 1);
        cin >> tmp;
        answerAry.push_back(tmp);
    }
    while (answerAry.size() != 0)
    {
        if (stk.size() != 0 && stk.top() == answerAry.front())
        {
            ansStr.push_back('-');
            stk.pop();
            answerAry.pop_front();
        }
        else
        {
            if (giveAry.size() == 0 || giveAry.front() > answerAry.front())
            {
                goto no;
            }
            //give ary가 사이즈가 0일 수 있다.
            tmp = giveAry.front();
            giveAry.pop_front();
            stk.push(tmp);
            ansStr.push_back('+');
        }
    }
    for (tmp = 0; tmp < ansStr.size(); tmp++)
    {
        cout << ansStr[tmp] << "\n";
    }
    if (false)
    {
    no:
        cout << "NO";
    }
}