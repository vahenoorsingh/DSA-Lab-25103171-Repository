#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    bool lthread;
    bool rthread;

    Node(int value) : data(value), left(nullptr), right(nullptr), lthread(false), rthread(false) {}
};

void createThreads(Node *root, Node *&prev)
{
    if (!root)
        return;

    createThreads(root->left, prev);

    if (root->left == nullptr)
    {
        root->left = prev;
        root->lthread = true;
    }
    else
    {
        root->lthread = false;
    }

    if (prev != nullptr)
    {
        if (prev->right == nullptr)
        {
            prev->right = root;
            prev->rthread = true;
        }
        else
        {
            prev->rthread = false;
        }
    }

    if (root->right == nullptr)
    {
        root->rthread = true;
    }
    else
    {
        root->rthread = false;
    }

    prev = root;

    createThreads(root->right, prev);
}

void convertToDoubleThreaded(Node *&root)
{
    Node *prev = nullptr;
    createThreads(root, prev);
}

void inorderTraversal(Node *root)
{
    if (!root)
        return;

    Node *current = root;
    while (!current->lthread)
    {
        current = current->left;
    }

    while (current)
    {
        cout << current->data << " ";

        if (current->rthread)
        {
            current = current->right;
        }
        else
        {
            current = current->right;
            if (current)
            {
                while (!current->lthread)
                {
                    current = current->left;
                }
            }
        }
    }

    cout << endl;
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    convertToDoubleThreaded(root);
    inorderTraversal(root);

    return 0;
}