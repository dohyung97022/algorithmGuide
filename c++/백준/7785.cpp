#include <iostream>
#include <map>
using namespace std;
int main()
{
    int testCase;
    string tmpStr, tmpStr2;
    map<string, int, greater<>> log;
    cin >> testCase;
    while (testCase--)
    {
        cin >> tmpStr >> tmpStr2;
        if (tmpStr2 == "enter")
        {
            log[tmpStr]++;
        }
        else
        {
            log[tmpStr]--;
        }
    }

    for (const auto &val : log)
    {
        if (val.second == 1)
        {
            cout << val.first << "\n";
        }
    }
}