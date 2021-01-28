// 투 포인터 연습중

#include <iostream>
#include <deque>
using namespace std;
deque<int> deq;
int main()
{
    int deqLen, findSum, input;
    cin >> deqLen >> findSum;
    while (deqLen--)
    {
        cin >> input;
        deq.push_back(input);
    }
    int n = 0, count = 0, snSum;
    for (int s = 0; s < deq.size(); s++)
    {
        snSum = 0;
        while (n < deq.size() && snSum <= findSum)
        {
            snSum = 0;
            for (int i = s; i <= n; i++)
                snSum += deq[i];
            if (snSum == findSum)
                count++;
            if (snSum <= findSum)
                n++;
        }
    }
    cout << count;
}