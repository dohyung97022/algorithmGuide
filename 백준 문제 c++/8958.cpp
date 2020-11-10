#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testCase=0, comboCounter=0, score=0;
    cin>>testCase;
    string quizAry[testCase];
    for (int i=0; i<testCase; i++){
        cin>>quizAry[i];
        score = 0;
        comboCounter = 0;
        for (int i2=0; i2<quizAry[i].length(); i2++){
            if (quizAry[i][i2] == 'O'){
                comboCounter++;
                score = score + comboCounter;
            } else {
                comboCounter = 0;
            }
        }
        cout<<score<<"\n";
    }
}