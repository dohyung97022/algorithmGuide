// 가정 1.
// 다익스트라로 구한다.
// 모든 노드의 경우를 구한다.
// 경우들 중 최대값을 구한다.

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXCITY = 1001;
const int MAXDISTANCE = 100001;

// pair<거리, 도착점> roads[출발점]
vector<pair<int, int>> roads[MAXCITY];
int minDistance[MAXCITY];
int maxDistanceAll = 0;

void djk(int startCity)
{
    // pair<거리, 지점> pk;
    priority_queue<pair<int, int>> pk;
    pk.push({0, startCity});
    while (pk.size())
    {
        int city = pk.top().second;
        int distance = -pk.top().first;
        pk.pop();
        for (int i = 0; i < roads[city].size(); i++)
        {
            int nextDistance = distance + roads[city][i].first;
            int nextCity = roads[city][i].second;
            if (minDistance[nextCity] > nextDistance)
            {
                minDistance[nextCity] = nextDistance;
                pk.push({-nextDistance, nextCity});
            }
        }
    }
}

int main()
{
    // vector에 도로 값들을 넣는다.
    int cityCount, roadCount, toCity;
    cin >> cityCount >> roadCount >> toCity;
    for (int i = 0; i < roadCount; i++)
    {
        int startCity, endCity, roadLen;
        cin >> startCity >> endCity >> roadLen;
        roads[startCity].push_back({roadLen, endCity});
    }

    for (int i = 1; i <= cityCount; i++)
        minDistance[i] = MAXDISTANCE;

    // 파티의 위치에서부터 모든 노드까지의 단방향 거리 저장
    djk(toCity);
    int fromPartyMinDistance[cityCount + 1];
    for (int i = 1; i <= cityCount; i++)
    {
        fromPartyMinDistance[i] = minDistance[i];
        minDistance[i] = MAXDISTANCE;
    }
    // 모든 거리의 길이 중 최댓값 지정
    for (int i = 1; i <= cityCount; i++)
        if (i != toCity)
        {
            djk(i);
            if (maxDistanceAll < minDistance[toCity] + fromPartyMinDistance[i])
                maxDistanceAll = minDistance[toCity] + fromPartyMinDistance[i];
            for (int j = 1; j <= cityCount; j++)
                minDistance[j] = MAXDISTANCE;
        }
    cout << maxDistanceAll;
}

// 반례
// 파티를 하는 사람 자기 자신의 도시의 경우 어떻게 되는가?