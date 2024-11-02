#include <bits/stdc++.h>
using namespace std;
int v = 5;
void Qinsert(int queue[], int &front, int &rear, int item)
{
    if (front == 1 &&rear == v || front == rear + 1)
    {
        cout << "overflow kaka"<<endl;
        return;
    }
    else if (front == -1)
    {
        front = 1;
        rear = 1;
    }
    else if (rear == v)
    {
        rear = 1;
    }
    else
    {
        rear = rear + 1;
    }

    queue[rear] = item;

    cout << "item " << item << " is inserted"<<endl;
}
int main()
{

    int queue[v];
    int front = -1, rear = -1;

    Qinsert(queue, front, rear, 10);
    Qinsert(queue, front, rear, 20);
    Qinsert(queue, front, rear, 30);
    Qinsert(queue, front, rear, 40);
    Qinsert(queue, front, rear, 50);
    Qinsert(queue, front, rear, 60);
    Qinsert(queue, front, rear, 70);
}