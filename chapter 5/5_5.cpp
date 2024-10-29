#include <bits/stdc++.h>
#include <cstddef>
#include <cstdlib>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    if (ptr != NULL)
    {
        while (ptr != NULL)
        {
            cout << "element: " << ptr->data << "\n";
            ptr = ptr->next;
        }
    }
    else
    {
        cout << "element: " << 0 << "\n";
    }
}
// Case 4
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    if (head == NULL)
    {
        head = (struct Node *)malloc(sizeof(struct Node));
        head->data = data;
        head->next = NULL;
        return head;
    }
    else
    {
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = prevNode->next;
        prevNode->next = ptr;

        return head;
    }
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

    // head = NULL;

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;

    printf("Linked list before insertion\n");
    linkedListTraversal(head);

    head = insertAfterNode(head, third, 45);

    printf("\nLinked list after insertion\n");
    linkedListTraversal(head);
    return 0;
}
