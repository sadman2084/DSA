#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "element is: " << ptr->data;
        ptr = ptr->next;
    }
}

struct Node *deleteAtIndex(struct Node *head, int value)
{
    if (head == NULL)
    {
        return NULL;
    }

    // If the head node itself holds the value to be deleted
    if (head->data == value)
    {
        struct Node *ptr = head;
        head = head->next;
        free(ptr);
        return head;
    }

    struct Node *ptr = head;
    while (ptr->next != NULL && ptr->next->data != value)
    {
        ptr = ptr->next;
    }

    if (ptr->next != NULL && ptr->next->data == value)
    {
        struct Node *temp = ptr->next;
        ptr->next = ptr->next->next;
        free(temp);
    }

    return head;
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
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = NULL;

    printf("Linked list before deletion\n");
    linkedListTraversal(head);

    int item = 4;
    head = deleteAtIndex(head, item);

    printf("Linked list after deletion\n");
    linkedListTraversal(head);

    return 0;
}
