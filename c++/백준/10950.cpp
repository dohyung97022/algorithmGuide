#include<iostream>
using namespace std;
int main(){
    int loop;
    cin>>loop;
    int a[loop];
    int b[loop];
    for (int i=0; i<loop; i++){
        cin>>a[i]>>b[i];
    }
     for (int i=0; i<loop; i++){
        cout<<a[i]+b[i]<<endl;
     }
}