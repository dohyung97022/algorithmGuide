#include <iostream>
using namespace std;
int main()
{
    int nTh, tmpNumber, sixCount, number = 665;
    cin >> nTh;
    while (nTh)
    {
        number++;
        tmpNumber = number;
        // for int i 0~2
        // 처음은 확인하고
        // 그 다음은 tmpNumber를 10으로 나누고 다시 확인
        // 자릿수를 벗어나면 break
        sixCount = 0;
        while (tmpNumber / 10 != 0 || tmpNumber % 10 != 0)
        {
            //현재 자릿수가 존재한다.
            //6이 나올때마나 sixCount를 더한다.
            //나오지 않는다면 sixCount=0을 한다.
            //sixCount가 3일 경우에 종말의 숫자이다.
            if (tmpNumber % 10 == 6)
                sixCount++;
            else
                sixCount = 0;
            if (sixCount == 3)
            {
                nTh--;
            }
            tmpNumber = tmpNumber / 10;
        }
    }
    cout << number;
}