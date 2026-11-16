#include <iostream>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

bool ismirror(struct node *left, struct node *right);

int main()
{
    struct node *root = new struct node;

    root->left = new struct node;
    root->right = new struct node;
    root->left->data = 1;
    root->right->data = 1;

    std::cout << (ismirror(root->left, root->right) ? "Symmetric" : "Non Symmetric") << std::endl;
}

bool ismirror(struct node *left, struct node *right)
{
    if (left == nullptr && right == nullptr)
        return true;

    if (left == nullptr || right == nullptr)
        return false;

    return (left->data == right->data) && ismirror(left->left, right->right) && ismirror(left->right, right->left);
}