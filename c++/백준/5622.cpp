#include <iostream>
using namespace std;
int main()
{
    string alph = "ABCDEFGHIJKLMNOQRSTUVWXY";
    string input;
    int minTime = 0;
    cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
        int getI2 = 0;
        for (int i2 = 0; i2 < alph.length(); i2++)
        {
            if (input[i] == 'Z')
            {
                getI2 = 23;
                goto outOfI2;
            }
            if (input[i] == 'P')
            {
                getI2 = 15;
                goto outOfI2;
            }
            if (alph[i2] == input[i])
            {
                getI2 = i2;
                goto outOfI2;
            }
        }
    outOfI2:
        minTime += getI2 / 3 + 3;
    }
    cout << minTime;
}
//반례 pqrs wxyz
//p의 경우
//z의 경우
/*
2, abc = 012
3으로 나누면 0
+3 = 3
3, def = 345
3으로 나누면 1
+3 = 4
4, ghi = 678
3으로 나누면 2
+3 = 5
5, jkl = 9, 10, 11
3으로 나누면 3
+3 = 6
6, mno = 12, 13, 14
3으로 나누면 4
+3 = 7



*/