#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool sortDic(string &aStr, string &bStr)
{
    if (aStr.size() != bStr.size())
        return aStr.size() < bStr.size();
    else
    {
        int i = 0;
        while (aStr[i] == bStr[i] && i < bStr.size() - 1)
            i++;
        return aStr[i] < bStr[i];
    }
}
int main()
{
    vector<string> dictionary;
    int wordLen;
    cin >> wordLen;
    while (wordLen--)
    {
        string input;
        cin >> input;
        dictionary.push_back(input);
    }
    sort(dictionary.begin(), dictionary.end(), sortDic);
    string checkDuplicateStr = "";
    for (auto const &val : dictionary)
    {
        if (val != checkDuplicateStr)
        {
            cout << val << "\n";
            checkDuplicateStr = val;
        }
    }
}