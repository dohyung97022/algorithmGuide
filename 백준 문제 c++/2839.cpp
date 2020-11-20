#include <iostream>
using namespace std;
int main(){
    int A,B,C,N=0;
    cin>>A>>B>>C;
    if (B>=C){
        cout<<-1;
        return 0;
    }
    cout<<A/(C-B)+1;
}

// A>=N*(C-B)

// b는 반드시 c보다 커야한다. 같아도 안된다.
// b>c조건


// A/(C-B)>=N

// A/(C-B)+1


//WOW.
//부등호가 나올 경우 =으로 생각하여 식으로 바꿀 수 있다!
