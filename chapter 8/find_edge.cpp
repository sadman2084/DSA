#include <bits/stdc++.h>
using namespace std;
#define V 5

int adj[V][V] = {0};

void addEdge(int src, int dest)
{
    adj[src][dest] = 1;
    adj[dest][src] = 1;
}

int findEdge(int src, int dest)
{
    if (adj[src][dest] == 1)
    {
        cout << "found";
        return 0;
    }
    return -1;
}
int main()
{

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);

    int src = 1, dest = 3;
    int c = findEdge(src, dest);

    if (c == -1)
    {
        cout << "not found";
    }
}
