#include <iostream>
using namespace std;
int main()
{
    string someWord;
    int wordCount = 0;
    while (cin >> someWord)
    {
        wordCount++;
    }
    cout << wordCount;
}