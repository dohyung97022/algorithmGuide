// 3273
// 이 문제는 쌍의 개수를 출력하는 문제임으로
// 계산의 순서가 어떻게 되든 전혀 상관이 없다.
// 그럼으로 내림차순으로 정리를 한 이후
// 투 포인터로 해결하면 된다.

// 그런데

// s
// 1 2 3 5 7 9 10 11 12
//   n

// s + n = 8

// 1. s와 n을 인덱스 0과 1로 지정한다. v
// 2. 합이 x보다 작으면 n을 1 이동시킨다. v
// 3. 합이 x와 같으면 카운터를 증가시킨다. v
// 4. 합이 x와 같거나 크면 s를 이동시키고 n을 s+1로 한다. v
// 5. 제한조건은 s를 배열 -1까지 for loop로 하고 v
// 6. n을 배열 끝까지로 한다.

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// vector<int> sumArray;

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int arrLen, x, tmp, n, count = 0;
//     cin >> arrLen;
//     while (arrLen--)
//     {
//         cin >> tmp;
//         sumArray.push_back(tmp);
//     }
//     cin >> x;

//     sort(sumArray.begin(), sumArray.end(), less<int>());

//     for (int s = 0; s < sumArray.size() - 1; s++)
//     {
//         n = s + 1;
//         while (sumArray[s] + sumArray[n] <= x && n < sumArray.size())
//         {
//             if (sumArray[s] + sumArray[n] == x)
//                 count++;
//             n++;
//         }
//     }
//     cout << count;
// }

/// 시간초과...
// 와... 구한값을 반으로 나누는 것이였어?!?
// 쌍을 구하는 문제...
// 분할정복도 사용했네요...

#include <iostream>

#include <algorithm>

using namespace std;

const int MAX = 100000;

int arr[MAX];

int main(void)

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    int N, X;

    cin >> N;

    for (int i = 0; i < N; i++)

        cin >> arr[i];

    cin >> X;

    sort(arr, arr + N);

    int result = 0;

    for (int i = 0; i < N; i++)

    {

        int low = 0, high = N - 1;

        while (low <= high)

        {

            int mid = (low + high) / 2;

            if (arr[mid] == X - arr[i])

            {

                result++;

                break;
            }

            else if (arr[mid] < X - arr[i])

                low = mid + 1;

            else

                high = mid - 1;
        }
    }

    //이 부분이 핵심

    cout << result / 2 << "\n";

    return 0;
}