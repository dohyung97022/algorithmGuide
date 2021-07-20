// 정말 깔끔한 노드의 구현이다....
// 안보고 기억하며 적자.
// insert가 조금 부족하다.
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;
};

Node *insert(Node *node, int data)
{
    if (node == NULL)
    {
        node = new Node();
        node->data = data;
    }
    else if (data <= node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}

void postOrder(Node *node)
{
    if (node->left != NULL)
        postOrder(node->left);
    else if (node->right != NULL)
        postOrder(node->right);
    cout << node->data << "\n";
}

int main()
{
    int input;
    Node *node = NULL;
    while (cin >> input)
    {
        if (input == EOF)
            break;
        node = insert(node, input);
    }
    postOrder(node);
}

// #include <iostream>
// using namespace std;

// struct Node
// {
//     int data;
//     Node *left;
//     Node *right;
// };

// Node *insert(Node *node, int data)
// {
//     if (node == NULL)
//     {
//         node = new Node();
//         node->data = data;
//         node->left = node->right = NULL;
//     }
//     else if (data <= node->data)
//         node->left = insert(node->left, data);
//     else
//         node->right = insert(node->right, data);
//     return node;
// }

// void postorder(Node *node)
// {
//     if (node->left != NULL)
//         postorder(node->left);
//     if (node->right != NULL)
//         postorder(node->right);
//     cout << node->data << '\n';
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     Node *root = NULL;
//     int val;
//     while (cin >> val)
//     {
//         if (val == EOF)
//             break;
//         root = insert(root, val);
//     }
//     postorder(root);
//     return 0;
// }