#include<iostream>
using namespace std;
int main(){
    int i1,i2;
    cin>>i1>>i2;
    int x1 = i2%10;
    int x2 = (i2/10)%10;
    int x3 = (i2/10/10)%10;
    cout<<i1*x1<<endl;
    cout<<i1*x2<<endl;
    cout<<i1*x3<<endl;
    cout<<i1*i2<<endl;
}