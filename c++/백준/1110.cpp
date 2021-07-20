#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i1,r,cnt;
    cin>>i1;
    while(i1!=r){
        int a,b;
        if (i1<10){
            a=i1;
            b=0;
        } else {
            a=i1%10;
            b=(i1/10)%10;
        }
        r = a+(a+b)%10;
        cnt++;
    }
}