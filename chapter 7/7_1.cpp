#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *root = NULL; // universal declared

void insert(int data)
{
    Node *newNode = new Node(data);
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left == NULL)
        {
            temp->left = newNode;
            return;
        }
        else
        {
            q.push(temp->left);
        }
        if (temp->right == NULL)
        {
            temp->right = newNode;
            return;
        }
        else
        {
            q.push(temp->right);
        }
    }
}

void preOrderTraversal_Recursion(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " ";
    preOrderTraversal_Recursion(node->left);
    preOrderTraversal_Recursion(node->right);
}

void preOrderTraversal_Iterative(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    stack<Node *> stack;
    stack.push(node);
    while (!stack.empty())
    {
        Node *temp = stack.top();
        stack.pop();
        cout << temp->data << " ";
        if (temp->right != NULL)
        {
            stack.push(temp->right);
        }
        if (temp->left != NULL)
        {
            stack.push(temp->left);
        }
    }
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    insert(70);
    insert(80);
    insert(90);
    insert(100);

    cout << "Preorder Traversal (Recursion): ";
    preOrderTraversal_Recursion(root);
    cout << endl;
    cout << "Preorder Traversal (Iterative): ";
    preOrderTraversal_Iterative(root);
    cout << endl;

    return 0;
}
