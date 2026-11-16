#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int v)
{
    if (!root)
        return new Node(v);
    if (v < root->data)
        root->left = insert(root->left, v);
    else if (v > root->data)
        root->right = insert(root->right, v);
    return root;
}

void inorder(Node *root, vector<int> &out)
{
    if (!root)
        return;
    inorder(root->left, out);
    out.push_back(root->data);
    inorder(root->right, out);
}

void recoverUtil(Node *root, Node *&first, Node *&mid, Node *&last, Node *&prev)
{
    if (!root)
        return;
    recoverUtil(root->left, first, mid, last, prev);
    if (prev && root->data < prev->data)
    {
        if (!first)
        {
            first = prev;
            mid = root;
        }
        else
        {
            last = root;
        }
    }
    prev = root;
    recoverUtil(root->right, first, mid, last, prev);
}

void recoverBST(Node *root)
{
    Node *first = nullptr, *mid = nullptr, *last = nullptr, *prev = nullptr;
    recoverUtil(root, first, mid, last, prev);
    if (first && last)
        swap(first->data, last->data);
    else if (first && mid)
        swap(first->data, mid->data);
}

int main()
{
    // Node *root = nullptr;
    // for (int v : {50, 30, 70, 20, 40, 60, 80})
    //     root = insert(root, v);

    Node *root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(7);
    root->right->left = new Node(4);
    root->right->right = new Node(9);
    // swap(root->left->data, root->right->data);
    recoverBST(root);
    vector<int> out;
    inorder(root, out);
    for (int x : out)
        cout << x << " ";
    cout << endl;
    return 0;
}