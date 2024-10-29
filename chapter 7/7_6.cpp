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

void CASEA(Node *LOC, Node *PAR)
{
    Node *CHILD;

    if (LOC->left != NULL && LOC->right == NULL)
    {
        CHILD = LOC->left;
    }
    else if (LOC->left == NULL && LOC->right != NULL)
    {
        CHILD = LOC->right;
    }
    else
    {
        CHILD = NULL;
    }

    if (PAR == NULL)
    {
        root = CHILD;
    }
    else
    {
        if (LOC == PAR->left)
        {
            PAR->left = CHILD;
        }
        else
        {
            PAR->right = CHILD;
        }
    }

    delete LOC; // Free the memory of the deleted node
    cout << "Node deleted from the tree." << endl;
}

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

        CASEA(LOC, PAR);
        cout << "Node with item " << ITEM << " deleted." << endl;
    }
    else
    {
        cout << "Item " << ITEM << " not found in the tree." << endl;
    }

    cout << "Inorder Traversal (After Deletion): ";
    inOrderTraversal_Recursion(root);
    cout << endl;

    return 0;
}
