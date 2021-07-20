//1+2+3+4+5
/*
대각선의 row를 지정한다.
몇번째 대각선에 주어진 x가 존재하는지 알아내기 위해서 
rowAdder에 row를 계속해서 더한다.
1+2+3+4+5+6+7+8+9...
X보다 rowAdder가 처음으로 클거나 같을 경우 그 row에서 x가 존재한다.
row가 짝수이면 rowAdder위치의 수는 row/1
row가 홀수이면 rowAdder위치의 수는 1/row
rowAdder가 실제 주어진 값과 차이나는 수만큼 roAdder에서 변동, 짝수인지 홀수인지에 따라..

짝수의 경우
1칸당 -1/+1
홀수의 경우
1칸당 +1/-1
*/

#include<iostream>
using namespace std;
int main(){
    int row=0,rowAdder=0,input,son,mom;
    cin>>input;
    while(input>rowAdder){
        row++;
        rowAdder+=row;
    }
    //짝
    int distance = rowAdder-input;
    if (row%2==0){
        son=row;
        mom=1;
        son = son - distance;
        mom = mom + distance;
    //홀
    } else {
        son=1;
        mom=row;
        son = son + distance;
        mom = mom - distance;
    }
    cout<<son<<"/"<<mom;
}