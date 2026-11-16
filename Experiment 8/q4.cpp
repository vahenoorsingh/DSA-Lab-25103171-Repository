#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int val)
{
    if (!root)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void inorder(Node *root, vector<int> &res)
{
    if (!root)
        return;
    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right, res);
}

void destroy(Node *root)
{
    if (!root)
        return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

int main()
{
    int n;
    cout << "Enter number of integers: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Node *root = nullptr;
    for (int x : a)
        root = insert(root, x);

    vector<int> sorted;
    inorder(root, sorted);

    cout << "Sorted: ";
    for (int x : sorted)
        cout << x << ' ';
    cout << '\n';

    destroy(root);
    return 0;
}