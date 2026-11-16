#include <iostream>
#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int minDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    if (root->left == nullptr)
    {
        return minDepth(root->right) + 1;
    }

    if (root->right == nullptr)
    {
        return minDepth(root->left) + 1;
    }

    return std::min(minDepth(root->left), minDepth(root->right)) + 1;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    // root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int depth = minDepth(root);

    std::cout << depth << std::endl;

    return 0;
}
