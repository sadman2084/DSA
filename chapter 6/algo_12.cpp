#include <bits/stdc++.h>
using namespace std;

int v = 5;
void Qdelete(int queue[], int &front, int &rear)
{
    if (front == -1)
    {
        cout << "underflow" << endl;
        return;
    }
    int item = queue[front];
    cout<<"deleted item:"<<item<<endl;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == v)
    {
        front = 1;
    }
    else
    {
        front = front + 1;
    }
}
int main()
{
    int queue[v];
    int front = -1, rear = -1;

    front = 0;
    rear = 4;
    queue[0] = 10;
    queue[1] = 20;
    queue[2] = 30;
    queue[3] = 40;
    queue[4] = 50;
    Qdelete(queue, front, rear);
    Qdelete(queue, front, rear);
    Qdelete(queue, front, rear);
    Qdelete(queue, front, rear);
    Qdelete(queue, front, rear);
    Qdelete(queue, front, rear);
}