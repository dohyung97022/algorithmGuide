//1 N=1   
//2~7 N=2 개수 6개 (전의 끝 숫자)+1 ~ (전의 끝 숫자)+((N-1)*6)
//8~19 N=3 개수 12개 (전의 끝 숫자)+1 ~ (전의 끝 숫자)+((N-1)*6)
//20~37 N=4 개수 18개 (전의 끝 숫자)+1 ~ (전의 끝 숫자)+((N-1)*6)

//input = 13
//(전의 끝 숫자)+1 <= input <= (전의 끝 숫자)+((N-1)*6) != true {N++;}
//출력은 N

#include<iostream>
using namespace std;
int main(){
    int input, beforeNumber=1, N=1;
    cin>>input;
    if (input==1) {cout<<1;}

    while(beforeNumber+(N-1)*6 < input){
        N++;
        beforeNumber=beforeNumber+(N-1)*6;
    }
    cout<<N;
}


//second try

// mutiplier = mutiplier + multiAdder
// multiAdder 는 매 회마다 ++
// //6*0 0  + 1
// 1
// //6*1 6  + 1
// 2
// //6*3 18  + 1
// 3
// //6*6 36  + 1
// 4
// //6*10 60  + 1

// input이 결과값보다 크면 다음 단계로 (같을 경우 다음 단계로 넘어가지 않는다)

#include <iostream>
using namespace std;
int main(){
    int input, mutiplier=0, multiAdder=0, stepCount=1;
    cin>>input;
    while((6*mutiplier)+1<input){
        multiAdder++;
        mutiplier = mutiplier+multiAdder;
        stepCount++;
    }
    cout<<stepCount;
}