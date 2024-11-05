#include <bits/stdc++.h>
using namespace std;
#define V 5

int adj[V][V] = {0};

void addEdge(int src, int dest)
{
    if (src >= 0 && src < V && dest >= 0 && dest < V)  // Index range check
    {
        adj[src][dest] = 1;
        adj[dest][src] = 1;
    }
    else
    {
        cout << "Error: Invalid edge between " << src << " and " << dest << endl;
    }
}

int findEdge(int src, int dest)
{
    if (src >= 0 && src < V && dest >= 0 && dest < V) // Range check for `findEdge`
    {
        if (adj[src][dest] == 1)
        {
            cout << "found" << endl;
            return 0;
        }
        else
        {
            cout << "not found" << endl;
            return -1;
        }
    }
    else
    {
        cout << "Error: Invalid nodes " << src << " or " << dest << " are out of range." << endl;
        return -1;
    }
}

int main()
{
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);

    int src = 1, dest = 9;
    int c = findEdge(src, dest);

    if (c == -1)
    {
        cout << "not found" << endl;
    }

    return 0;
}
