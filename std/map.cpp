//map
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int main()
{
    map<int, string> intStrMap;

    intStrMap[0] = "kim";

    intStrMap[1] = "jun";

    for (auto &val : intStrMap)
    {
        cout << val.first << " " << val.second << " ";
    }

    unordered_map<int, string> unorderIntStrMap;
    unorderIntStrMap[0] = "kim";
    unorderIntStrMap[1] = "jun";

    for (auto &val : unorderIntStrMap)
    {
        cout << val.first << " " << val.second << " ";
    }
}