#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};

Node *linkedListTraversal(struct Node *ptr, int item)
{
    while (ptr != NULL)
    {
        if (item == ptr->data)
        {
            cout << ptr->next << "\n";
            return ptr;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    return NULL;
}

Node *searchSorted(struct Node *ptr, int item)
{
    if (ptr == NULL)
    {
        cout << "List is empty!\n";
        return NULL;
    }
    // Node *temp = start;
    while (ptr != NULL)
    {
        if (ptr->data < item)
            ptr = ptr->next;
        else if (ptr->data == item)
            return ptr; // jodi value pay
        else
            return NULL; // jodi value na pay
    }
    return NULL; // jodi value list e thaka value er theke boro hole
}

int main()
{
    // node er naam declare
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
    head->data = 10;
    head->next = second;

    // Link second and third nodes
    second->data = 20;
    second->next = third;

    // Link third and fourth nodes
    third->data = 30;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 40;
    fourth->next = NULL;

    int item = 20;


    auto searchedResult = linkedListTraversal(head, item);
    auto searchedSortedResult = searchSorted(head, item);


    
    if (searchedResult)
    {
        cout << "Found unsorted: " << searchedResult->data
             << endl;
    }
    else
    {
        cout << "Not found" << "\n";
    }

    if (searchedSortedResult)
    {
        cout << "Found sorted: " << searchedSortedResult->data << endl;
    }
    else
    {
        cout << "Not found" << "\n";
    }

    return 0;
}
