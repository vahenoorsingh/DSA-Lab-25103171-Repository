#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void serializeHelper(TreeNode *root, ostream &out)
{
    if (!root)
    {
        out << "#,";
        return;
    }
    out << root->val << ",";
    serializeHelper(root->left, out);
    serializeHelper(root->right, out);
}

string serialize(TreeNode *root)
{
    stringstream ss;
    serializeHelper(root, ss);
    return ss.str();
}

TreeNode *deserializeHelper(istringstream &in)
{
    string token;
    if (!getline(in, token, ','))
        return nullptr;
    if (token == "#" || token.empty())
        return nullptr;

    TreeNode *root = new TreeNode(stoi(token));
    root->left = deserializeHelper(in);
    root->right = deserializeHelper(in);
    return root;
}

TreeNode *deserialize(const string &data)
{
    istringstream in(data);
    return deserializeHelper(in);
}

int main()
{
    string data = "1,2,4,#,#,5,#,#,3,#,#";
    TreeNode *root = deserialize(data);
    cout << serialize(root) << endl;
    return 0;
}