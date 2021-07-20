// 가정1.
// 음수와 양수를 구분하여 2개의 priority queue에 넣는다.
// 음수와 양수를 내림차순 오름차순으로 변경하여 절댓값이 작은 순서대로 나오게 한다.
// 절댓값이 같을 경우 음수쪽을 출력하고 pop한다.

// #include <iostream>
// #include <queue>
// using namespace std;

// priority_queue<int> positiveQue;
// priority_queue<int> negativeQue;

// int main()
// {
//     int inputLen, input;
//     cin >> inputLen;
//     while (inputLen--)
//     {
//         cin >> input;
//         if (input == 0)
//         {
//             // 둘다 있을 경우
//             if (positiveQue.size() && negativeQue.size())
//             {
//                 if (positiveQue.top() < -negativeQue.top())
//                 {
//                     cout << positiveQue.top() << "\n";
//                     positiveQue.pop();
//                 }
//                 else
//                 {
//                     cout << negativeQue.top() << "\n";
//                     negativeQue.pop();
//                 }
//             }
//             // 둘 중 하나만 있을 경우
//             else if (positiveQue.size())
//             {
//                 cout << positiveQue.top() << "\n";
//                 positiveQue.pop();
//             }
//             else if (negativeQue.size())
//             {
//                 cout << negativeQue.top() << "\n";
//                 negativeQue.pop();
//             }
//             // 둘 다 없을 경우
//             else
//                 cout << "0\n";
//         }
//         else
//             (input > 0) ? positiveQue.push(input) : negativeQue.push(input);
//     }
// }

// 위처럼 구성해도 좋긴 좋은데
// priority que에서 pair를 넣어 구성할 수도 있다.

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (!num && pq.empty())
            cout << 0 << "\n";
        else if (!num)
        {
            cout << -pq.top().second << "\n";
            pq.pop();
        }
        else
            pq.push({-abs(num), -num});
    }
}