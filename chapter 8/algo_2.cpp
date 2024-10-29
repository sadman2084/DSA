#include <bits/stdc++.h>
using namespace std;
#define INF 99999
#define v 4
void printDisplay(int graph[][v]);
void floydwarshall(int graph[][v])
{
    int i, j, k;
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            for (k = 0; k < v; k++)
            {
                if (graph[i][j] > (graph[i][k] + graph[k][j]) && graph[i][k] != INF && graph[k][j] != INF)
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    printDisplay(graph);
}

void printDisplay(int graph[][v])
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (graph[i][j] == INF)
            {
                cout << "INF"
                     << " ";
            }
            else
            {
                cout << graph[i][j] << "   ";
            }
        }
        cout << endl;
    }
}
int main()
{

    int graph[v][v] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};
    floydwarshall(graph);
}
