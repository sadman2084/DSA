#include <bits/stdc++.h>
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

Node *root = NULL; // universally declared

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

// Recursive inorder traversal
void inOrderTraversal_Recursion(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    inOrderTraversal_Recursion(node->left);
    cout << node->data << " ";
    inOrderTraversal_Recursion(node->right);
}

// Iterative inorder traversal
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
// FIND function
void FIND(Node *INFO, Node *LEFT, Node *RIGHT, Node *ROOT, int ITEM, Node *&LOC, Node *&PAR)
{
    LOC = ROOT;
    PAR = NULL;

    while (LOC != NULL)
    {
        if (ITEM == LOC->data)
        {
            return; // Item found
        }
        PAR = LOC;
        if (ITEM < LOC->data)
        {
            LOC = LOC->left;
        }
        else
        {
            LOC = LOC->right;
        }
    }
}

int main()
{
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);

    cout << "Inorder Traversal (Recursion): ";
    inOrderTraversal_Recursion(root);
    cout << endl;

    cout << "Inorder Traversal (Iterative): ";
    inOrderTraversal_Iterative(root);
    cout << endl;

    Node *LOC = NULL;
    Node *PAR = NULL;
    int ITEM = 70;
    FIND(root, NULL, NULL, root, ITEM, LOC, PAR);

    if (LOC != NULL)
    {
        cout << "Item " << ITEM << " found in the tree." << endl;
        if (PAR != NULL)
        {
            cout << "Parent of the item is: " << PAR->data << endl;
        }
        else
        {
            cout << "Item is the root of the tree." << endl;
        }
    }
    else
    {
        cout << "Item " << ITEM << " not found in the tree." << endl;
        if (PAR != NULL)
        {
            cout << "Item can be added as a child of: " << PAR->data << endl;
        }
        else
        {
            cout << "The tree is empty." << endl;
        }
    }

    return 0;
}
