#include <iostream>
#include <vector>
#include <utility>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode *root, std::vector<int> &values)
{
    if (root == nullptr)
        return;
    inorder(root->left, values);
    values.push_back(root->val);
    inorder(root->right, values);
}

std::pair<int, int> kthSmallestAndLargest(TreeNode *root, int k)
{
    std::vector<int> values;
    inorder(root, values);
    return {values[k - 1], values[values.size() - k]};
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    int k = 2;
    auto result = kthSmallestAndLargest(root, k);
    std::cout << "kth smallest: " << result.first << "\n";
    std::cout << "kth largest: " << result.second << "\n";

    return 0;
}