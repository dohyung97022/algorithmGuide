/*
C-(A-B)/A-B
이것으로 나눈 값에다가 
나머지가 존재하면 +1, 나며지가 0이면 아무것도 안한다.
걸과
*/
#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int A,B,C;
    cin>>A>>B>>C;
    if ((C-B)%(A-B) != 0){
        cout<<(C-B)/(A-B)+1;
        return 0;
    }
    cout<<(C-B)/(A-B);
}
//반례 13 7 19
//정말 햇갈리는 문제네....
