#include <iostream>
using namespace std;
#include <deque>
void pushF(deque<int> &deq, int x)
{
    deq.push_front(x);
}

void pushB(deque<int> &deq, int x)
{
    deq.push_back(x);
}

void popF(deque<int> &deq)
{
    if (!deq.empty())
    {
        cout << deq.front() << "\n";
        deq.pop_front();
    }
    else
    {
        cout << "-1\n";
    }
}
void popB(deque<int> &deq)
{
    if (!deq.empty())
    {
        cout << deq.back() << "\n";
        deq.pop_back();
    }
    else
    {
        cout << "-1\n";
    }
}
void size(deque<int> &deq)
{
    cout << deq.size() << "\n";
}
void empty(deque<int> &deq)
{
    if (deq.empty())
    {
        cout << "1\n";
    }
    else
    {
        cout << "0\n";
    }
}
void front(deque<int> &deq)
{
    if (!deq.empty())
    {
        cout << deq.front() << "\n";
    }
    else
    {
        cout << "-1\n";
    }
}
void back(deque<int> &deq)
{
    if (!deq.empty())
    {
        cout << deq.back() << "\n";
    }
    else
    {
        cout << "-1\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    deque<int> deq;
    int testNumber;
    cin >> testNumber;
    for (int i = 0; i < testNumber; i++)
    {
        string command;
        int val;
        cin >> command;
        if (command == "push_front")
        {
            cin >> val;
            pushF(deq, val);
        }
        else if (command == "push_back")
        {
            cin >> val;
            pushB(deq, val);
        }
        else if (command == "pop_front")
        {
            popF(deq);
        }
        else if (command == "pop_back")
        {
            popB(deq);
        }
        else if (command == "size")
        {
            size(deq);
        }
        else if (command == "empty")
        {
            empty(deq);
        }
        else if (command == "front")
        {
            front(deq);
        }
        else if (command == "back")
        {
            back(deq);
        }
    }
}