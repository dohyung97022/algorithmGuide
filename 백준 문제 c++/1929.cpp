//time out ㅜㅜ
//이 사람의 코드에서 내가 배울 수 있는 것.

//에라토스테네스의 체
//소수가 나오면 소수의 배수를 버린다.

// new bool[b + 1]; 나는 bool의 array를 많이 사용하지 않았다. 다음번에 꼭 사용해보기...
// (int)pow(i, 2); pow 제곱 앞에 type를 줄 수 있다?

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

// 1<= a <= b <= 1,000,000
int main(void)
{
    int a, b;

    scanf("%d %d", &a, &b);

    //최대치 크기만큼 동적할당을 합니다
    bool *arr = new bool[b + 1];

    //배열을 true로 초기화합니다
    for (int i = 0; i < b + 1; i++)
    {
        arr[i] = true;
    }

    int j; //제곱의 수를 받을 변수

    for (int i = 2; i < b + 1; i++)
    {

        if (arr[i])
        { //true이면

            if ((unsigned int)pow(i, 2) > 1000001)
            {
                //제곱이 범위를 넘으면 for 문을 나옵니다
                break;
            }
            else
            {
                //이미 있는 소수들의 배수들을 지워줍니다.
                for (j = (int)pow(i, 2); j < b + 1;)
                {
                    arr[j] = false; //소수가 아닌 수들을 false로 바꿔줌
                    j = j + i;
                }
            }
        }
    }

    //1인경우를 제외해야하므로 a가 1이 들어왔을때, 2로 만들어줍니다
    if (a == 1)
        a++;

    //true이면서, a보다 큰 값들을 출력!
    for (int i = a; i < b + 1; i++)
    {
        if (arr[i] && i >= a)
            printf("%d\n", i);
    }

    delete[] arr; // 동적할당 해제
    return 0;
}