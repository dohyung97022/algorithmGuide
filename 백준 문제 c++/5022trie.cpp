// tire 연습
#include <iostream>
using namespace std;

const int ALPHABET_LEN = 26;

struct TrieNode
{
    TrieNode *childrenAry[ALPHABET_LEN];
    bool lastOfWord;
    //new
    TrieNode()
    {
        for (int i = 0; i < ALPHABET_LEN; i++)
            childrenAry[i] = NULL;
    }

    //delete
    ~TrieNode()
    {
        for (int i = 0; i < ALPHABET_LEN; i++)
            if (childrenAry[i] != NULL)
                delete childrenAry[i];
    }
    void insert(char *key)
    {
        // 이거는 그저 문자열이 끝나는 입력이다.
        if (*key == 0)
        {
            lastOfWord = true;
            return;
        }
        //알파벳을 0~25까지
        int next = *key - 'A';
        if (childrenAry[next] == NULL)
            childrenAry[next] = new TrieNode();
        childrenAry[next]->insert(key + 1);
    }

    // last of word 가 일치함에 따라 전화번호부 문제와 같이
    // 필요에 따라 추가하거나 사용할 수 있는 oop함수를 만들도록 한다.
};

int main()
{
}