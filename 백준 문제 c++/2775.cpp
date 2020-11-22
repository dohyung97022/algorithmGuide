#include <iostream>
using namespace std;
int main(){
    int T;
    cin>>T;
    for (int i=0; i<T; i++){
        int K,N,adder;
        cin>>K>>N;
        int calcFloorAry[N];

        for (int i2=0; i2<N; i2++){
            calcFloorAry[i2]=1;
        }
        
        for (int i3=0; i3<=K; i3++){
            adder=0;
            for (int i4=0; i4<N; i4++){
                adder += calcFloorAry[i4];
                calcFloorAry[i4] = adder;
            }
        }
        cout<<adder<<endl;
    }
}