#include<iostream>;
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b,c;
    int count[10];
    cin>>a>>b>>c;
    int abc = a*b*c;
    for (int i=0; i<10; i++){
        int abcMemory = abc;
        int iCount = 0;
        count[i] = 0;
        while (abcMemory/10 != 0){
            if (abcMemory%10 == i) {
                count[i]++;
            }
            abcMemory = abcMemory/10;
        }
        if (abcMemory%10 == i) {
            count[i]++;
        }
    }
    for (int i=0; i<10; i++){
        cout<<count[i]<<"\n";
    }
}