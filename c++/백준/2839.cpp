#include <iostream>
using namespace std;
int main(){
    int sugar,fiveMultiplier=0,bagCount=0;
    cin>>sugar;
    while (sugar>=fiveMultiplier*5){
        fiveMultiplier++;
    }
    fiveMultiplier--;
    while (fiveMultiplier > 0 && (sugar-fiveMultiplier*5)%3 != 0 ){
        fiveMultiplier--;
    }
    if ((sugar-fiveMultiplier*5)%3 != 0){
        cout<<-1;
        return 0;
    }
    cout<<fiveMultiplier+(sugar-fiveMultiplier*5)/3;
}

//5의 배수인 경우