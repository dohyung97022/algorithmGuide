#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int inputIntAry[10], leftOverIntBoolAry[42]={0,}, count=0;
    for (int i=0; i<10; i++){
        cin>>inputIntAry[i];
        int leftOver = inputIntAry[i]%42;
        if (leftOverIntBoolAry[leftOver]==0){
            leftOverIntBoolAry[leftOver]=1;
            count++;
        }
    }
    cout<<count;
}