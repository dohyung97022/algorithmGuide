#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool sortXY(pair<int, int> &pairA, pair<int, int> &pairB)
{
    if (pairA.second != pairB.second)
        return pairA.second < pairB.second;
    else
        return pairA.first < pairB.first;
}
int main()
{
    int nodeLen;
    cin >> nodeLen;
    vector<pair<int, int>> nodes;
    while (nodeLen--)
    {
        int x, y;
        cin >> x >> y;
        nodes.push_back(make_pair(x, y));
    }
    sort(nodes.begin(), nodes.end(), sortXY);
    for (auto const &val : nodes)
    {
        cout << val.first << " " << val.second << "\n";
    }
}