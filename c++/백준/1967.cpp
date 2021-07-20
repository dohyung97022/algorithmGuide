//트리의 지름을 구하는 방식은 전에 본 적이 있다.
//루트에서부터 가장 거리가 먼 노드를 구하고
//그 노드에서부터 가장 거리가 먼 노드까지의 길이를 구하는 방법이다.

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXSIZE = 10001;

// tree[부모노드] = pair<자식노드, 길이>
vector<pair<int, int>> tree[MAXSIZE];
bool visited[MAXSIZE];

int longestLen = 0;
int longestNode = 1;

void bfs(int node, int stackedLen)
{
    visited[node] = true;
    for (auto const &childAndLen : tree[node])
    {
        int nextNode = childAndLen.first;
        if (!visited[nextNode])
        {
            int newLength = stackedLen + childAndLen.second;
            if (longestLen < newLength)
            {
                longestLen = newLength;
                longestNode = nextNode;
            }
            bfs(nextNode, newLength);
        }
    }
}

int main()
{
    int nodeCount;
    cin >> nodeCount;
    for (int i = 1; i < nodeCount; i++)
    {
        int parentNode, childNode, nodeWeight;
        cin >> parentNode >> childNode >> nodeWeight;
        tree[parentNode].push_back(make_pair(childNode, nodeWeight));
        tree[childNode].push_back(make_pair(parentNode, nodeWeight));
    }
    bfs(1, 0);
    memset(visited, 0, MAXSIZE);
    bfs(longestNode, 0);
    cout << longestLen;
}