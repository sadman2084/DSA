#include <iostream>
#include <queue>
using namespace std;

#define V 5               
int adjMatrix[V][V] = {0}; 

void addEdge(int src, int dest)
{
    adjMatrix[src][dest] = 1;
    adjMatrix[dest][src] = 1;
}

int findNode(int ITEM)
{
    bool visited[V] = {false}; 
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        if (node == ITEM)
        {
            return node; 
        }

        for (int i = 0; i < V; i++)
        {
            if (adjMatrix[node][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    return -1; 
}

int main()
{
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);

    int ITEM = 8;
    int location = findNode(ITEM);

    if (location != -1)
    {
        cout << "First node containing ITEM " << ITEM << " is at node: " << location << endl;
    }
    else
    {
        cout << "ITEM " << ITEM << " not found in the graph." << endl;
    }

    return 0;
}
