#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    bool lthread;
    bool rthread;
    int size;
    Node(int v) : val(v), left(nullptr), right(nullptr), lthread(false), rthread(false), size(1) {}
};

int getSize(Node *n) { return n ? n->size : 0; }

Node *insert(Node *root, int val)
{
    if (!root)
        return new Node(val);
    if (val < root->val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    root->size = 1 + getSize(root->left) + getSize(root->right);
    return root;
}

void convert(Node *root)
{
    if (!root)
        return;
    vector<Node *> stack;
    Node *curr = root;
    Node *prev = nullptr;

    while (curr || !stack.empty())
    {
        while (curr)
        {
            stack.push_back(curr);
            curr = curr->left;
        }
        curr = stack.back();
        stack.pop_back();

        if (prev)
        {
            if (!prev->right)
            {
                prev->right = curr;
                prev->rthread = true;
            }
        }
        if (!curr->left)
        {
            curr->left = prev;
            curr->lthread = true;
        }
        prev = curr;
        curr = curr->right;
    }
}

Node *find(Node *root, int x)
{
    Node *curr = root;
    while (curr)
    {
        if (curr->val == x)
            return curr;
        if (x < curr->val)
        {
            if (curr->lthread)
                return nullptr;
            curr = curr->left;
        }
        else
        {
            if (curr->rthread)
                return nullptr;
            curr = curr->right;
        }
    }
    return nullptr;
}

Node *getNext(Node *curr)
{
    if (!curr)
        return nullptr;
    if (curr->rthread)
        return curr->right;
    curr = curr->right;
    while (curr && !curr->lthread)
    {
        curr = curr->left;
    }
    return curr;
}

Node *getPrev(Node *curr)
{
    if (!curr)
        return nullptr;
    if (curr->lthread)
        return curr->left;
    curr = curr->left;
    while (curr && !curr->rthread)
    {
        curr = curr->right;
    }
    return curr;
}

Node *findLowerBound(Node *root, int L)
{
    Node *curr = root;
    Node *ans = nullptr;
    while (curr)
    {
        if (curr->val >= L)
        {
            ans = curr;
            if (curr->lthread)
                break;
            curr = curr->left;
        }
        else
        {
            if (curr->rthread)
                break;
            curr = curr->right;
        }
    }
    return ans;
}

Node *kthSmallest(Node *root, int k)
{
    if (!root || k <= 0 || k > root->size)
        return nullptr;
    Node *curr = root;
    while (curr)
    {
        int leftSize = curr->lthread ? 0 : getSize(curr->left);
        if (k == leftSize + 1)
        {
            return curr;
        }
        else if (k <= leftSize)
        {
            curr = curr->left;
        }
        else
        {
            k -= (leftSize + 1);
            curr = curr->right;
        }
    }
    return nullptr;
}

int main()
{
    string line;
    Node *root = nullptr;
    while (getline(cin, line))
    {
        if (line.empty())
            continue;

        stringstream ss(line);
        string cmd;
        ss >> cmd;

        if (cmd == "BUILD")
        {
            int v;
            while (ss >> v)
            {
                root = insert(root, v);
            }
        }
        else if (cmd == "CONVERT")
        {
            convert(root);
        }
        else if (cmd == "NEXT")
        {
            int x;
            ss >> x;
            Node *curr = find(root, x);
            Node *next = getNext(curr);
            if (next)
            {
                cout << "NEXT " << x << " = " << next->val << "\n";
            }
            else
            {
                cout << "NEXT " << x << " = NULL\n";
            }
        }
        else if (cmd == "PREV")
        {
            int x;
            ss >> x;
            Node *curr = find(root, x);
            Node *prev = getPrev(curr);
            if (prev)
            {
                cout << "PREV " << x << " = " << prev->val << "\n";
            }
            else
            {
                cout << "PREV " << x << " = NULL\n";
            }
        }
        else if (cmd == "RANGE")
        {
            int L, R;
            ss >> L >> R;
            vector<int> res;
            Node *curr = findLowerBound(root, L);
            while (curr && curr->val <= R)
            {
                res.push_back(curr->val);
                curr = getNext(curr);
            }
            cout << "RANGE = ";
            for (size_t i = 0; i < res.size(); ++i)
            {
                cout << res[i];
                if (i + 1 < res.size())
                    cout << " ";
            }
            cout << "\n";
        }
        else if (cmd == "KTH")
        {
            int k;
            ss >> k;
            Node *curr = kthSmallest(root, k);
            if (curr)
            {
                cout << "KTH " << k << " = " << curr->val << "\n";
            }
            else
            {
                cout << "KTH " << k << " = NULL\n";
            }
        }
    }
    return 0;
}