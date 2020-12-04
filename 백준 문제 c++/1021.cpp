//맨 뒤에서 가까운 것이나, 맨 앞에서 가까운 것을 찾아서 빼버린다.
//이해하였으나 살짝 이해가 안되는데?
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, M, num, cnt = 0;
    vector<int> deque;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        deque.push_back(i);
    }
    while (M--)
    {
        scanf("%d", &num);

        int front = 0, back = 0;
        for (int i = 0; i < N; i++)
        {
            if (deque[i] == num)
            {
                front = 1;
                break;
            }
            else if (deque[N - 1 - i] == num)
            {
                back = 1;
                break;
            }
        }
        if (front)
        {
            while (1)
            {
                int front_num = deque.front();
                deque.erase(deque.begin());
                if (front_num == num)
                    break;
                deque.push_back(front_num);
                cnt++;
            }
        }
        else
        {
            cnt++;
            while (1)
            {
                int back_num = deque.back();
                deque.pop_back();

                if (back_num == num)
                    break;
                deque.insert(deque.begin(), back_num);
                cnt++;
            }
        }
        N--;
    }
    printf("%d\n", cnt);
}

// 10 3
// 2 9 5