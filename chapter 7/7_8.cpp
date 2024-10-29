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

// Function to find the inorder successor of a node
void FIND_INORDER_SUCCESSOR(Node *LOC, Node *&SUC, Node *&PARSUC)
{
    PARSUC = LOC;
    SUC = LOC->right;
    while (SUC->left != NULL)
    {
        PARSUC = SUC;
        SUC = SUC->left;
    }
}

// Function to delete a node from the BST
void DEL(Node *&root, int ITEM)
{
    Node *LOC = NULL;
    Node *PAR = NULL;
    FIND(root, ITEM, LOC, PAR);

    if (LOC == NULL)
    {
        cout << "Item " << ITEM << " not found in the tree." << endl;
        return; // Item not found
    }

    // Case 1: Node to be deleted has two children
    if (LOC->left != NULL && LOC->right != NULL)
    {
        Node *SUC = NULL;
        Node *PARSUC = NULL;
        FIND_INORDER_SUCCESSOR(LOC, SUC, PARSUC);
        LOC->data = SUC->data; // Copy successor's data to LOC
        if (PARSUC->left == SUC)
        {
            PARSUC->left = SUC->right;
        }
        else
        {
            PARSUC->right = SUC->right;
        }
        delete SUC;
    }
    // Case 2: Node to be deleted has one or no child
    else
    {
        Node *CHILD;
        if (LOC->left != NULL)
        {
            CHILD = LOC->left;
        }
        else
        {
            CHILD = LOC->right;
        }

        if (PAR == NULL)
        {
            root = CHILD; // Node to be deleted is root
        }
        else if (LOC == PAR->left)
        {
            PAR->left = CHILD;
        }
        else
        {
            PAR->right = CHILD;
        }
        delete LOC;
    }
    cout << "Item " << ITEM << " deleted from the tree." << endl;
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

    // Deleting a node
    int ITEM = 70;
    DEL(root, ITEM);

    cout << "Inorder Traversal (After Deletion): ";
    inOrderTraversal_Recursion(root);
    cout << endl;

    return 0;
}
