#include<iostream>
using namespace std;
int main(){
    int i1;
    cin>>i1;
    int sum = 0;
    for (int i=1; i<=i1; i++){
        sum = sum+i;
    }
    cout<<sum;
}