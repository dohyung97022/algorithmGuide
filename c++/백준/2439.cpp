#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t1;
    cin>>t1;
    for (int i1=1; i1<=t1; i1++){
        for (int i2=1; i2<=t1-i1; i2++){
            cout<<" ";
        }
        for (int i3=1; i3<=i1; i3++){
            cout<<"*";
        }
        cout<<"\n";
    }
}