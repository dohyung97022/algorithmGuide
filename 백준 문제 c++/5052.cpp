
// 시간초과...
// 이 사람과 나와 다른점
// 1. 소멸자를 알고 있다. ~Trie

// 2. Trie의 구조를 알고 있다. trie란 문자열 정렬의
// tree로 이어지는 문자를 각 단어마다 노드로 할당하며
// 그 노드와 bool로 구성된 struct로 이뤄져 있다.
// 해당 문제는 단어의 tree의 끝에 bool 이 finished인지를 확인하면 된다.

// 3. delete문과 fill 문을 정확히 활용한다.

// 4. 79번째 줄에 string으로 받지 않고 char의 array에 번호를 받았다.
// 그냥 cin으로 실험해본 결과 받아지지 않는다. char tel[11]; scanf("%s", tel);를 활용하자.

// 5. 소멸자를 활용하여 메모리를 줄인다.

// 6. struct의 함수를 매우 잘 활용한다. 함수 호출은 root->insert()와 같이 한다.

// https://mapocodingpark.blogspot.com/2020/02/BOJ-5052.html
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int GO_MAX = 10; // 트라이 노드마다 포인터 개수

struct Trie
{
    Trie *go[GO_MAX]; // 다음 노드를 가리키는 포인터 배열
    bool output;      // 이 노드에서 끝나는 전화번호가 있는가?
    bool goexist;     // 이 노드의 자식이 있는가?
    // 생성자
    Trie()
    {
        fill(go, go + GO_MAX, nullptr);
        output = goexist = false;
    }
    // 소멸자
    ~Trie()
    {
        for (int i = 0; i < GO_MAX; i++)
            if (go[i])
                delete go[i];
    }
    // 문자열 key를 현재 노드부터 삽입
    void insert(const char *key)
    {
        // 문자열이 끝남
        if (*key == '\0')
            output = true;
        // 아닐 경우
        else
        {
            int next = *key - '0';
            // 해당 노드가 없으면 새로 동적 할당해서 만듬
            if (!go[next])
                go[next] = new Trie;
            goexist = true;
            // 자식 노드에서 이어서 삽입
            go[next]->insert(key + 1);
        }
    }
    // 이 노드가 일관성이 있는가?
    bool consistent()
    {
        // 자식도 있으면서 여기서 끝나는 전화번호도 있다면 일관성 없음
        if (goexist && output)
            return false;
        // 자식들 중 하나라도 일관성이 없으면 이 노드도 일관성이 없음
        for (int i = 0; i < GO_MAX; i++)
            if (go[i] && !go[i]->consistent())
                return false;
        // 일관성이 있음
        return true;
    }
};
int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        int N;
        scanf("%d", &N);
        Trie *root = new Trie; // 루트 노드 만들기
        for (int i = 0; i < N; i++)
        {
            char tel[11];
            scanf("%s", tel);
            root->insert(tel);
        }
        puts(root->consistent() ? "YES" : "NO");
        // 소멸자를 호출하여 동적 할당 해제를 하지 않으면 힙 메모리가 부족할 수 있음
        delete root;
    }
    return 0;
}
