#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void topView(Node *root)
{
    if (!root)
        return;
    map<int, int> m;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto node = q.front().first;
        auto hd = q.front().second;
        // auto [node, hd] = q.front();
        q.pop();
        if (m.find(hd) == m.end())
            m[hd] = node->data;
        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
    }
    for (auto &p : m)
        cout << p.second << " ";
    cout << endl;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    topView(root);
}