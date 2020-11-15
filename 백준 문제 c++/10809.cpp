//goto와 out에 대한 이해
#include <iostream>
using namespace std;
int main()
{
    string S, alph = "abcdefghijklmnopqrstuvwxyz";
    cin >> S;
    for (int i = 0; i < alph.length(); i++)
    {
        for (int i2 = 0; i2 < S.length(); i2++)
        {
            if (alph[i] == S[i2])
            {
                cout << i2 << " ";
                goto out;
            }
        }
        cout << -1 << " ";
    out:
        continue;
    }
}