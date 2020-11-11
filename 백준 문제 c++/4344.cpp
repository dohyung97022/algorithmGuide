#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int C, N;
    cin>>C;
    for (int i=0; i<C; i++){
        cin>>N;
        int scores[N];
        for (int i2=0; i2<N; i2++){
            cin>>scores[i2];
        }
        int avr=0;
        for (int i2=0; i2<N; i2++){
            avr = avr + scores[i2];
        }
        avr = avr/N;
        float overAvrCount=0;
        for (int i2=0; i2<N; i2++){
            if (scores[i2]>avr){
                overAvrCount++;
            }
        }
        float res = overAvrCount/N*100;
        cout<<fixed;
        cout.precision(3);
        cout<<res<<"%\n";
    }
}