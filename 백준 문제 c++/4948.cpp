#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int input;
    while (cin >> input)
    {
        if (input == 0)
        {
            break;
        }
        //런타임 에러.
        //array의 length와 실제 loop되는 i의 값 잘 생각하기
        vector<bool> ifSosuArry(input * 2 + 1, true);
        for (int i = 2; i <= input * 2; i++)
        {
            if (ifSosuArry[i] == false)
            {
                continue;
            }

            int multiplier = 2;
            int multiplierSum;
            while (true)
            {
                multiplierSum = i * multiplier;
                if (multiplierSum > input * 2)
                {
                    goto endWhileLoop;
                }
                ifSosuArry[multiplierSum] = false;
                multiplier++;
            }
        endWhileLoop:
            continue;
        }
        int sosuCounter = 0;
        for (int i2 = input + 1; i2 <= input * 2; i2++)
        {
            if (ifSosuArry[i2] == true)
            {
                sosuCounter++;
            }
        }
        cout << sosuCounter << endl;
    }
}
