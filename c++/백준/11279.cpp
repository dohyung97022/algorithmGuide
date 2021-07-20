#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pQue;

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int inputLen, input;
    cin >> inputLen;
    while (inputLen--)
    {
        cin >> input;
        if (input == 0)
        {
            if (pQue.size())
            {
                cout << pQue.top() << "\n";
                pQue.pop();
            }
            else
                cout << "0\n";
        }
        else
            pQue.push(input);
    }
}