#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Deleting the element at a given index from the linked list
struct Node *deleteAtIndex(struct Node *head, int index)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    if (index == 0)
    {
        struct Node *ptr = head;
        head = head->next;
        free(ptr);
        return head;
    }

    struct Node *p = head;
    struct Node *q = NULL;

    for (int i = 0; i < index-1; i++)
    {
        if (p->next == NULL)
        {
            printf("Index out of range\n");
            return head;
        }
        p = p->next;
    }

    q = p->next;
    if (q != NULL)
    {
        p->next = q->next;
        free(q);
    }
    else
    {
        printf("Index out of range\n");
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

    int index = 0; 
    head = deleteAtIndex(head, index);

    printf("Linked list after deletion\n");
    linkedListTraversal(head);

    return 0;
}
