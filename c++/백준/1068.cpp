//방향이 아래로만 흘러가는 트리를 만든다.
//그 트리에서 없애는 노드의 visited array의 bool을 true로 바꾼다.
//0에서 bfs를 재귀적으로 하여 bfs가 끝나는 곳에서 count int를 +1하면 리프 노드의 갯수를 구할 수 있다.

//예상 반례
//노드 0이 지워질 때 0이 나오는가? 해결
//노드 0만 남았을 때 리프노드의 수는 0인가? 1개인가? 의문
//루트 노드는 반드시 0이 아닐 수도 있다.

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50;
// 단방향, tree[부모] = vector<자식들>
vector<int> tree[MAX];
bool visited[MAX];
int rootNode;
int leafCount = 0;

void bfs(int currentNode)
{
    // if (!tree[currentNode].size())
    //     leafCount++;
    //리프가 되어나가는 경우는
    //1. visited가 true인 경우?
    //2. 더 연결된 노드가 없는 경우, vector의 사이즈가 없는 경우,
    //3. 또는 연결이 1개 있는데 그 노드가 visited인 경우
    if (!visited[currentNode])
    {
        visited[currentNode] = true;

        if (!tree[currentNode].size())
            leafCount++;
        else if (tree[currentNode].size() == 1 && visited[tree[currentNode].front()])
            leafCount++;

        for (auto const &childNode : tree[currentNode])
        {
            bfs(childNode);
        }
    }
}

int main()
{
    int nodeCount;
    cin >> nodeCount;
    for (int node = 0; node < nodeCount; node++)
    {
        int connectedNode;
        cin >> connectedNode;
        if (connectedNode == -1)
            rootNode = node;
        else
            tree[connectedNode].push_back(node);
    }
    int removeNode;
    cin >> removeNode;
    visited[removeNode] = true;
    bfs(rootNode);
    cout << leafCount;
}