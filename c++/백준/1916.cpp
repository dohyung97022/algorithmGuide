// 다익스트라 연습

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int CITYMAX = 1001;
// 10000의 길이 중 1억이 되는 경우는 1000개의 도시가 있어 경유 가능 경우의 최댓값이
// 10000 X 1000 = 1억이 되는 것이다.
const int COSTMAX = 100000001;

// pair<비용, 도착 노드> map[시작노드];
vector<pair<int, int>> map[CITYMAX];

int minCost[CITYMAX];

void dijk(int startCity)
{
    minCost[startCity] = 0;
    // pair<비용, 도착 노드>
    priority_queue<pair<int, int>> pk;
    pk.push(make_pair(0, startCity));
    while (pk.size())
    {
        int cost = -pk.top().first;
        int city = pk.top().second;
        pk.pop();

        for (int i = 0; i < map[city].size(); i++)
        {
            int nextCost = cost - map[city][i].first;
            int nextCity = map[city][i].second;
            if (nextCost < minCost[nextCity])
            {
                minCost[nextCity] = nextCost;
                // push조차도 한쪽만 하면 된다.
                pk.push(make_pair(-nextCost, nextCity));
            }
        }
    }
}

int main()
{
    int cityLen, busLen;
    cin >> cityLen >> busLen;
    for (int i = 1; i <= cityLen; i++)
        minCost[i] = COSTMAX;
    for (int i = 0; i < busLen; i++)
    {
        int startCity, endCity, cost;
        cin >> startCity >> endCity >> cost;
        map[startCity].push_back({-cost, endCity});
    }
    int fromCity, toCity;
    cin >> fromCity >> toCity;
    dijk(fromCity);
    cout << minCost[toCity];
}