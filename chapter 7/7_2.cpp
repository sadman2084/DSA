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

void inOrderTraversal_Recursion(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal_Recursion(root->left);
    cout << root->data << " ";
    inOrderTraversal_Recursion(root->right);
}

void inOrderTraversal_Iterative(Node *node)
{
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
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

    cout << "inorder Traversal (Recursion): ";
    inOrderTraversal_Recursion(root);
    cout << endl;
    cout << "inorder Traversal (Iterative): ";
    inOrderTraversal_Iterative(root);
    cout << endl;

    return 0;
}
