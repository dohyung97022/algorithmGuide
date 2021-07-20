//1.min=-1, adder=0
//2.for loop으로 m과 n까지의 숫자를 돈다.
//3.if min==-1{
//      소수가 나올 경우 첫 소수를 min으로 지정
//}

//소수가 나올 경우 계속해서 adder에 합한다.

//if min==-1{ print min and return }
//else cout<<adder<<endl;
//cout<<min;

#include <iostream>
using namespace std;
int main()
{
    int min = -1, adder = 0, M, N;
    cin >> M >> N;
    for (int i = M; i <= N; i++)
    {
        bool isSosu = true;
        //소수 판단
        if (i == 1)
        {
            isSosu = false;
            goto brk;
        }
        for (int i2 = 2; i2 <= i / 2; i2++)
        {
            if (i % i2 == 0)
            {
                isSosu = false;
                goto brk;
            }
        }
    brk:
        if (isSosu)
        {
            if (min == -1)
            {
                min = i;
            }
            adder += i;
        }
    }
    if (min == -1)
    {
        cout << min;
        return 0;
    }
    cout << adder << endl;
    cout << min;
}