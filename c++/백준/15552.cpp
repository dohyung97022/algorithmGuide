#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testCase;
    cin>>testCase;
    for (int i=1; i<=testCase; i++){
    int a;
    int b;
    cin>>a>>b;
    cout<<a+b<<"\n";       
    }
}