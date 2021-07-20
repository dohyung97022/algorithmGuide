#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testCount;
    float bestScore, averageScore=0;
    cin>>testCount;
    float testScore[testCount];
    bestScore = 0;
    for (int i=0; i<testCount; i++){
        cin>>testScore[i];
        if (bestScore<testScore[i]) {
            bestScore = testScore[i];
        }
    }
    for (int i=0; i<testCount; i++){
        averageScore = averageScore + testScore[i]/bestScore*100;
    }
    cout<<averageScore/testCount;
}