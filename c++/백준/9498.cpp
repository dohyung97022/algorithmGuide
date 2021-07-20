#include <iostream>
using namespace std;
int main(){
    int i1;
    cin>>i1;
    if (i1>=90){
        cout<<'A';
    } else if (i1>=80){
        cout<<'B';
    } else if (i1>=70){
        cout<<'C';
    } else if (i1>=60){
        cout<<'D';
    } else {
        cout<<'F';
    }
}