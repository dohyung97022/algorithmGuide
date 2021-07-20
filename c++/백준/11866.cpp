#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int numPeople, killNum;
    deque<int> deq;
    cin >> numPeople >> killNum;
    for (int i = 1; i <= numPeople; i++)
    {
        deq.push_back(i);
    }
    cout << "<";
    while (!deq.empty())
    {
        for (int i = 0; i < killNum; i++)
        {
            if (i == killNum - 1)
            {
                cout << deq.front();
                if (deq.size() != 1)
                {
                    cout << ", ";
                }
                deq.pop_front();
            }
            else
            {
                deq.push_back(deq.front());
                deq.pop_front();
            }
        }
    }
    cout << ">";
}