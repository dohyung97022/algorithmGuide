#include <unordered_map>
#include <iostream>
using namespace std;
int main()
{
    int testCase, clothesLen, tmpInt;
    string tmpStr;
    cin >> testCase;
    while (testCase--)
    {
        cin >> clothesLen;
        unordered_map<string, int> clothesMap;
        while (clothesLen--)
        {
            cin >> tmpStr;
            cin >> tmpStr;
            clothesMap[tmpStr]++;
        }
        tmpInt = 1;
        for (auto const &val : clothesMap)
        {
            tmpInt *= val.second + 1;
        }
        tmpInt--;
        cout << tmpInt << "\n";
    }
}