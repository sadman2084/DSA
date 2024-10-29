#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    if (head == NULL)
    {
        cout << "The list is empty.\n";
        return;
    }

    struct Node *ptr = head;
    do
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

Node *searchValue(struct Node *head, int value)
{
    if (head == NULL)
    {
        return NULL;
    }

    struct Node *ptr = head;
    do
    {
        if (ptr->data == value)
        {
            return ptr;
        }
        ptr = ptr->next;
    } while (ptr != head);

    return NULL;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 6;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = head;

    linkedListTraversal(head);

    int value = 6;
    Node *result = searchValue(head, value);
    if (result)
    {
        cout << "Value " << value << " found in the list at " << result << endl;
    }
    else
    {
        cout << "Value " << value << " not found in the list.\n";
    }

    return 0;
}
