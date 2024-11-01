#include <iostream>
using namespace std;

#define V 5

int adj[V][V] = {0};

void addEdge(int src, int dest)
{
    adj[src][dest] = 1;
    adj[dest][src] = 1;
}

void deleteNode(int node)
{
    for (int i = 0; i < V; i++)
    {
        adj[node][i] = 0;
        adj[i][node] = 0;
    }
}

int main()
{
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);

    deleteNode(2);

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}
