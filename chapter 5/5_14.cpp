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
        cout << "The list is empty." << endl;
        return;
    }

    struct Node *ptr = head;
    do
    {
        cout << "Element is: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *deleteAtIndex(struct Node *head, int value)
{
    if (head == NULL)
    {
        return NULL;
    }

    struct Node *ptr = head;
    struct Node *prev = NULL;

    // Case 1: If head is the node to be deleted
    if (head->data == value)
    {
        // Find the last node
        do
        {
            prev = ptr;
            ptr = ptr->next;
        } while (ptr != head);

        // If there's only one node
        if (head == head->next)
        {
            free(head);
            return NULL;
        }

        // Update head and the last node's next pointer
        prev->next = head->next;
        ptr = head;
        head = head->next;
        free(ptr);
        return head;
    }

    // Case 2: If the node to be deleted is not the head
    ptr = head;
    do
    {
        prev = ptr;
        ptr = ptr->next;
    } while (ptr != head && ptr->data != value);

    // If node found, delete it
    if (ptr->data == value)
    {
        prev->next = ptr->next;
        free(ptr);
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

    // Terminate the list at the fourth node
    fourth->data = 1;
    fourth->next = head; // Make the list circular

    printf("Linked list before deletion\n");
    linkedListTraversal(head);

    int item = 4;
    head = deleteAtIndex(head, item);

    printf("Linked list after deletion\n");
    linkedListTraversal(head);

    return 0;
}
