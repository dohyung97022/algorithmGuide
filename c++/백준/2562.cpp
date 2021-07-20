#include<iostream>;
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int inInt=1, maxInt=0, i=1, maxIntPlace=1;
    while (cin>>inInt){
        if (inInt>maxInt){
            maxInt = inInt;
            maxIntPlace = i;
        }
        i++;
    }
    cout<<maxInt<<"\n";
    cout<<maxIntPlace<<"\n";
}
