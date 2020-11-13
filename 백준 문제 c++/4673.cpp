#include <iostream>
using namespace std;

//도대체 왜 이건 안되는거지? 왜 다른거지?
//10의 배수에서 다르게 나온다.
//확인 10%10=0 이여서 10의 자리수의 1을 더하지 않는다.
//틀린 정답이 맞다.
int d2(int n){
    int res = n;
    while (n%10!=0){
        res += n%10;
        n= n/10;
    }
    return res;
}

int d(int n){
    int res = n;
    do {
        res += n %10;
    } while ((n/= 10)!= 0);
    return res;
}

int main(){
    // for (int i=1; i<21; i++){
    //     cout<<d(i)<<endl;
    //     cout<<d2(i)<<endl;
    // }
    char checkList[100001];
    int di = 0;
    for (int i=1; i<10000; i++){
        di = d(i);
        if (di<=10000){
            checkList[di] = 'X';
        }
    }
    for (int i=1; i<10000; i++){
        if (checkList[i] != 'X'){
            cout<<i<<endl;
        }
    }
}