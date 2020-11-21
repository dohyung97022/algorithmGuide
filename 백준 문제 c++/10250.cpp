//h로 나눈 나머지를 방의 앞자리로 둔다. 단 나머지가 0일 경우 h의 값을 방 앞자리로 둔다.

//n을 h로 나눈 값에 +1을 하여 방의 뒷자리로 둔다. 단 나머지가 0일 경우 +1을 하지 않는다.

//0이 중간에 들어가면 어떻게?
//뒷자리 숫자를 10으로 나누었을 때 값이 나오지 않으면 중간에 0을 추가하여 cout

#include <iostream>
using namespace std;
int main(){
    int testCase, height, width, input;
    cin>>testCase;
    for (int i=0; i<testCase; i++){
        int front,back;
        cin>>height>>width>>input;
        if (input%height==0){
            front=height;
            back=input/height;
        } else {
            front=input%height;
            back=input/height+1;
        }
        if (back/10==0){
            cout<<front<<0<<back<<endl;
        } else {
            cout<<front<<back<<endl;
        }
    }
}