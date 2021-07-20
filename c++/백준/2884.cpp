/*
hour를 minute의 총으로 바꾸고 min과 합한다.
40을 뺀다.
24시간*60분 1440분

1440분 초과의 경우
밤 00:00을 넘길 때
-1440을 한다.

-의 경우
새벽 00:00에서 뒤로 돌아갈때
+1440을 한다.

min이 60을 넘으면 hour로 바꾼다.
*/

#include<iostream>
using namespace std;
int main(){
    int hour, min, total;
    cin>>hour>>min;
    total = hour*60+min - 45;
    if (total>=1440){
        total = total-1440;
    } else if (total<0){
        total = total+1440;
    }
    hour = total/60;
    min = total%60;
    cout<<hour<<" "<<min<<endl;
}