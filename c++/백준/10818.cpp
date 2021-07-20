#include<iostream>
#include<cmath>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    int l;
    cin>>l;
    double iArry[l];
    for (int i=0; i<l; i++){
        cin>>iArry[i];
    }
    double min = 1000000,max = -1000000;
    for (int i=0; i<l; i++){
        min = fmin(min,iArry[i]);
        max = fmax(max,iArry[i]);
    }
    cout<<fixed;
    cout.precision(0);
    cout<<min<<" "<<max;
}

/* elegant code.....
#include <iostream>
using namespace std;
int main(void){
   int num, count,min = 1000001, max = -1000001;
   cin>>count;
    while(cin>>num){
        max = num > max ? num : max;
        min = num < min ? num : min;
    }
    cout << min << " " << max;
}
*/