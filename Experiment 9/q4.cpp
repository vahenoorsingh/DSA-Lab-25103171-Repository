#include <bits/stdc++.h>
using namespace std;

struct Node
{
    long long val;
    Node *left;
    Node *right;
    Node(long long v) : val(v), left(nullptr), right(nullptr) {}
};

struct Info
{
    bool isBST;
    long long mn;
    long long mx;
    long long sum;
};

Info dfs(Node *root, long long &ans)
{
    if (!root)
        return {true, LLONG_MAX, LLONG_MIN, 0};

    Info l = dfs(root->left, ans);
    Info r = dfs(root->right, ans);

    long long sum = l.sum + r.sum + root->val;
    bool bst = l.isBST && r.isBST;

    if (bst && root->left && root->val <= l.mx)
        bst = false;
    if (bst && root->right && root->val >= r.mn)
        bst = false;

    long long mn = root->val;
    long long mx = root->val;

    if (root->left)
    {
        mn = min(mn, l.mn);
        mx = max(mx, l.mx);
    }

    if (root->right)
    {
        mn = min(mn, r.mn);
        mx = max(mx, r.mx);
    }

    if (bst)
        ans = max(ans, sum);

    return {bst, mn, mx, sum};
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    long long ans = LLONG_MIN;
    dfs(root, ans);

    if (ans == LLONG_MIN)
        ans = 0;

    cout << "Maximum BST subtree sum = " << ans << endl;

    return 0;
}