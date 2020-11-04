#include <iostream>
using namespace std;
int main(){
    int i1,i2;
    cin>>i1>>i2;
    if (i1>i2){
        cout<<">";
    } else if (i1<i2){
        cout<<"<";
    } else if (i1=i2){
        cout<<"==";
    }
}