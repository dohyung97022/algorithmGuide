#include<iostream>
using namespace std;
int main(){
    int i1,i2,i3;
    cin>>i1>>i2>>i3;
    cout<<(i1+i2)%i3<<endl;
    cout<<((i1%i3)+(i2%i3))%i3<<endl;
    cout<<(i1*i2)%i3<<endl;
    cout<<((i1%i3)*(i2%i3))%i3<<endl;
}