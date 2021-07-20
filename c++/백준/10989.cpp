//어레이에 값의 결과가 그 인덱스의 수의 갯수가 되게 할 수 있다.
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int testCase;
    cin >> testCase;
    int arry[100001] = {
        0,
    };
    for (int i = 0; i < testCase; i++)
    {
        int x;
        cin >> x;
        arry[x]++;
    }
    for (int i = 0; i <= 100000; i++)
    {
        for (int j = 0; j < arry[i]; j++)
        {
            cout << i << "\n";
        }
    }
}