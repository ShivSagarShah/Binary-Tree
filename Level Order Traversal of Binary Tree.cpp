// C++ program for level order traversal of Binary Tree
#include <bits/stdc++.h>
using namespace std;

// Tree node
struct Node
{
    int data;
    Node *left, *right;
};
void levelOrderTraversal(Node *root)
{
    // vector<vector<int>> ans;
    // if(!root) return ans;
    if (!root)
    {
        return;
    }
    // vector<int> result;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        if (p == NULL)
        {
            // ans.push_back(result);
            // result.clear();
            cout << endl;
            if (q.size() > 0)
                q.push(NULL);
        }
        else
        {
            // result.push_back(p->data);
            cout << p->data << " ";
            if (p->left)
            {
                q.push(p->left);
            }
            if (p->right)
            {
                q.push(p->right);
            }
        }
    }
    // return ans;
}
// Utility method to create a new node
Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main()
{
    Node *root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    levelOrderTraversal(root);

    return 0;
}
