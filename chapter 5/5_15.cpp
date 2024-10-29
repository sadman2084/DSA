#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
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

    // Case 1: If head is the node to be deleted
    if (head->data == value)
    {
        // If there's only one node
        if (head->next == head)
        {
            free(head);
            return NULL;
        }

        // Find the last node
        struct Node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }

        // Update head and the last node's next and prev pointers
        head = head->next;
        last->next = head;
        head->prev = last;
        free(ptr);
        return head;
    }

    // Case 2: If the node to be deleted is not the head
    do
    {
        if (ptr->data == value)
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
            return head;
        }
        ptr = ptr->next;
    } while (ptr != head);

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
    head->prev = fourth; // Circular doubly linked list

    // Link second and third nodes
    second->data = 3;
    second->next = third;
    second->prev = head;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;
    third->prev = second;

    // Terminate the list at the fourth node
    fourth->data = 1;
    fourth->next = head;
    fourth->prev = third;

    head->prev = fourth; // Complete the circular doubly linked list

    cout << "Linked list before deletion" << endl;
    linkedListTraversal(head);

    int item = 5;
    head = deleteAtIndex(head, item);

    cout << "Linked list after deletion" << endl;
    linkedListTraversal(head);

    return 0;
}
