#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int mapCase, answerLen, tmpInt = 0;
    string tmpStr;
    map<string, int> pokeMap;
    map<int, string> revPokeMap;
    cin >> mapCase >> answerLen;

    while (mapCase--)
    {
        tmpInt++;
        cin >> tmpStr;
        pokeMap[tmpStr] = tmpInt;
        revPokeMap[tmpInt] = tmpStr;
    }
    while (answerLen--)
    {
        cin >> tmpStr;
        tmpInt = atoi(&tmpStr[0]);
        if (tmpInt)
        {
            //숫자
            cout << revPokeMap[tmpInt] << "\n";
        }
        else
        {
            cout << pokeMap[tmpStr] << "\n";
        }
    }
}