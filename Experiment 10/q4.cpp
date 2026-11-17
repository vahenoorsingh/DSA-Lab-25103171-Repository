#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> extractIntegers(const string &str)
{
    vector<int> res;
    stringstream ss(str);
    int val;
    while (ss >> val)
    {
        res.push_back(val);
    }
    return res;
}

TreeNode *buildTree(const vector<int> &nodes)
{
    if (nodes.empty() || nodes[0] == -1)
        return nullptr;

    TreeNode *root = new TreeNode(nodes[0]);
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size())
    {
        TreeNode *curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != -1)
        {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1)
        {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

void inorderTraversal(TreeNode *root, vector<int> &elements)
{
    vector<TreeNode *> stack;
    TreeNode *curr = root;

    while (curr != nullptr || !stack.empty())
    {
        while (curr != nullptr)
        {
            stack.push_back(curr);
            curr = curr->left;
        }
        curr = stack.back();
        stack.pop_back();
        elements.push_back(curr->val);
        curr = curr->right;
    }
}

int main()
{
    string line1, line2;
    if (!getline(cin, line1) || !getline(cin, line2))
        return 0;

    vector<int> treeNodes = extractIntegers(line1);
    vector<int> queries = extractIntegers(line2);

    TreeNode *root = buildTree(treeNodes);
    vector<int> sortedElements;
    inorderTraversal(root, sortedElements);

    for (size_t i = 0; i < queries.size(); ++i)
    {
        int k = queries[i];
        if (k <= 0 || k > sortedElements.size())
        {
            cout << -1;
        }
        else
        {
            cout << sortedElements[k - 1];
        }
        cout << " ";
    }
    cout << endl;

    return 0;
}