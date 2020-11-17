#include <iostream>
#include <string>
using namespace std;
int main()
{
    int testCase, countGroupWord = 0;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        string word;
        cin >> word;
        string usedAlph = "";
        char currentAlph;
        bool isGroupWord = true;
        for (int i2 = 0; i2 < word.length(); i2++)
        {
            if (i2 == 0)
            {
                currentAlph = word[i2];
            }
            if (word[i2] != currentAlph)
            {
                for (int i3 = 0; i3 < usedAlph.length(); i3++)
                {
                    if (word[i2] == usedAlph[i3])
                    {
                        //단어가 이미 사용된 적이 있다 => 그룹 단어가 아니다.
                        isGroupWord = false;
                        goto breakOut;
                    }
                }
                usedAlph.push_back(currentAlph);
                currentAlph = word[i2];
            }
        }
    breakOut:
        if (isGroupWord)
        {
            countGroupWord++;
        }
    }
    cout << countGroupWord;
}