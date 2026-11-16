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

vector<int> kClosestBST(Node *root, int x, int k)
{
    vector<Node *> lower, upper;
    Node *cur = root;

    while (cur)
    {
        if (cur->data <= x)
        {
            lower.push_back(cur);
            cur = cur->right;
        }
        else
        {
            upper.push_back(cur);
            cur = cur->left;
        }
    }

    vector<int> result;

    while ((int)result.size() < k && (!lower.empty() || !upper.empty()))
    {
        if (lower.empty())
        {
            Node *s = upper.back();
            upper.pop_back();
            result.push_back(s->data);
            cur = s->right;
            while (cur)
            {
                upper.push_back(cur);
                cur = cur->left;
            }
        }
        else if (upper.empty())
        {
            Node *p = lower.back();
            lower.pop_back();
            result.push_back(p->data);
            cur = p->left;
            while (cur)
            {
                lower.push_back(cur);
                cur = cur->right;
            }
        }
        else
        {
            int pv = lower.back()->data;
            int sv = upper.back()->data;
            long long dp = llabs((long long)pv - x);
            long long ds = llabs((long long)sv - x);

            if (dp <= ds)
            {
                Node *p = lower.back();
                lower.pop_back();
                result.push_back(p->data);
                cur = p->left;
                while (cur)
                {
                    lower.push_back(cur);
                    cur = cur->right;
                }
            }
            else
            {
                Node *s = upper.back();
                upper.pop_back();
                result.push_back(s->data);
                cur = s->right;
                while (cur)
                {
                    upper.push_back(cur);
                    cur = cur->left;
                }
            }
        }
    }

    return result;
}

int main()
{
    Node *root = nullptr;
    vector<int> values = {10, 5, 15, 2, 7, 12, 20, 6, 8};

    for (int v : values)
    {
        root = insert(root, v);
    }

    int target = 9;
    int k = 4;

    vector<int> ans = kClosestBST(root, target, k);

    for (int i = 0; i < (int)ans.size(); i++)
    {
        if (i)
            cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}