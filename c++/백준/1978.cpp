#include<iostream>
using namespace std;
int main(){
        int testCase, sosuCount=0;
        cin>>testCase;
        for (int i=0; i<testCase; i++){
                int checkSosu,checkDevidedBy2;
                bool isSosu=true;
                cin>>checkSosu;
                // cout<<"checkSosu = "<<checkSosu<<endl;
                checkDevidedBy2 = checkSosu/2;
                // cout<<"checkDevidedBy2 = "<<checkDevidedBy2<<endl;
                for (int i2=2; i2<=checkDevidedBy2; i2++){
                     if (checkSosu%i2 == 0){
                        isSosu=false;
                        // cout<<"can be devided by = "<<i2<<endl;
                        goto brk;
                     }   
                }
                brk:
                if (isSosu && checkSosu != 1){
                        sosuCount++;
                }
        }
        cout<<sosuCount;
}