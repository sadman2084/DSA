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

void postOrderTraversal_Recursion(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    postOrderTraversal_Recursion(node->left);
    postOrderTraversal_Recursion(node->right);
    cout << root->data << " ";
}

void postOrderTraversal_Iterative(Node *node)
{
    stack<pair<Node *, bool>> s;

    s.push(make_pair(root, true));

    while (!s.empty())
    {
        Node *temp = s.top().first;
        bool right_sided = s.top().second;

        if (right_sided)
        {
            s.pop();
            while (temp != NULL)
            {
                s.push(make_pair(temp, false));
                if (temp->right != NULL)
                {
                    s.push(make_pair(temp->right, true));
                }
                temp = temp->left;
            }
        }

        right_sided = s.top().second;

        if (!right_sided)
        {
            cout << s.top().first->data << " ";
            s.pop();
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

    cout << "postorder Traversal (Recursion): ";
    postOrderTraversal_Recursion(root);
    cout << endl;
    cout << "postorder Traversal (Iterative): ";
    postOrderTraversal_Iterative(root);
    cout << endl;

    return 0;
}
