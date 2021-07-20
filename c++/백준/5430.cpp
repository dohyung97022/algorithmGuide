//무슨 천재들인듯?
// deque는 reverse가 느리니까 그냥 역방향으로 생각을 해버리네 ㅋㅋ
// holy moly...
#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        string command, arrayStr, arrStrBuffer;
        int queLen;
        deque<int> deq;
        cin >> command >> queLen;
        cin >> arrayStr;
        arrayStr = arrayStr.substr(1, arrayStr.size() - 2);
        istringstream stringStream(arrayStr);
        while (getline(stringStream, arrStrBuffer, ','))
        {
            deq.push_back(stoi(arrStrBuffer));
        }
        bool order = true;
        for (int i = 0; i < command.size(); i++)
        {
            if (command[i] == 'R')
            {
                order = (!order);
            }
            if (command[i] == 'D')
            {
                if (deq.size() != 0)
                {
                    if (order)
                        deq.pop_front();
                    else
                        deq.pop_back();
                }
                else
                {
                    cout << "error\n";
                    goto errEnd;
                }
            }
        }
        cout << "[";
        if (order)
        {
            for (int i = 0; i < deq.size(); i++)
            {
                cout << deq[i];
                if (i != deq.size() - 1)
                {
                    cout << ",";
                }
            }
        }
        else
        {
            for (int i = deq.size() - 1; i >= 0; i--)
            {
                cout << deq[i];
                if (i > 0)
                {
                    cout << ",";
                }
            }
        }
        cout << "]\n";
    errEnd:
        continue;
    }
}