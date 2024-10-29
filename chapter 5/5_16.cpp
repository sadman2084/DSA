#include <bits/stdc++.h>
#include <cstddef>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void linkedListTraversal(struct Node *ptr)
{
    if (ptr != NULL)
    {
        while (ptr != NULL)
        {
            cout << "Element: " << ptr->data << "\n";
            ptr = ptr->next;
        }
    }
    else
    {
        cout << "The list is empty.\n";
    }
}

// Insert the new node between two given nodes
struct Node *insertBetweenNodes(struct Node *head, struct Node *node1, struct Node *node2, int data)
{
    if (node1 == NULL || node2 == NULL)
    {
        cout << "Invalid positions provided.\n";
        return head;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (node1->next == node2)
    {
        newNode->next = node2;
        newNode->prev = node1;
        node1->next = newNode;
        node2->prev = newNode;
    }
    else
    {
        cout << "Provided nodes are not consecutive.\n";
        free(newNode);
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
    head->data = 7;
    head->next = second;
    head->prev = NULL;

    // Link second and third nodes
    second->data = 11;
    second->next = third;
    second->prev = head;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;
    third->prev = second;

    // Terminate the list at the fourth node
    fourth->data = 66;
    fourth->next = NULL;
    fourth->prev = third;

    printf("Linked list before insertion\n");
    linkedListTraversal(head);
    int data = 45;
    // Insert between third and fourth nodes
    head = insertBetweenNodes(head, second, third, data);

    printf("\nLinked list after insertion\n");
    linkedListTraversal(head);

    return 0;
}
