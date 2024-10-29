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

// Function to find the item in the tree or where it can be inserted
void FIND(Node *ROOT, int ITEM, Node *&LOC, Node *&PAR)
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

// Function to insert an item into the BST
void INSBST(int ITEM)
{
    Node *LOC = NULL;
    Node *PAR = NULL;
    FIND(root, ITEM, LOC, PAR);

    if (LOC != NULL)
    {
        cout << "Item " << ITEM << " already exists in the tree." << endl;
        return;
    }

    Node *newNode = new Node(ITEM);
    if (PAR == NULL)
    {
        root = newNode; // Tree was empty, new node is now root
    }
    else if (ITEM < PAR->data)
    {
        PAR->left = newNode;
    }
    else
    {
        PAR->right = newNode;
    }

    cout << "Item " << ITEM << " inserted into the tree." << endl;
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

int main()
{
    INSBST(50);
    INSBST(30);
    INSBST(70);
    INSBST(20);
    INSBST(40);
    INSBST(60);
    INSBST(80);

    cout << "Inorder Traversal (Recursion): ";
    inOrderTraversal_Recursion(root);
    cout << endl;

    cout << "Inorder Traversal (Iterative): ";
    inOrderTraversal_Iterative(root);
    cout << endl;

    Node *LOC = NULL;
    Node *PAR = NULL;
    int ITEM = 70;
    FIND(root, ITEM, LOC, PAR);

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
