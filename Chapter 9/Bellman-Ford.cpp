#include <iostream>
#include <climits>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

int convertToEdges(int V, int graph[][9], Edge edges[])
{
    int edgeCount = 0;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] != 0)
            { // if there's an edge
                edges[edgeCount++] = {i, j, graph[i][j]};
            }
        }
    }
    return edgeCount;
}

void BellmanFord(int V, Edge edges[], int E, int start)
{
    int dist[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[start] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (int i = 0; i < E; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            cout << "Graph contains a negative weight cycle" << endl;
            return;
        }
    }

    cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << " \t\t " << dist[i] << endl;
    }
}

int main()
{
    int V = 9;
    int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    Edge edges[81];

    int E = convertToEdges(V, graph, edges);

    BellmanFord(V, edges, E, 0);

    return 0;
}
