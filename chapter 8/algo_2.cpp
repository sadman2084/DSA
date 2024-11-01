#include <bits/stdc++.h>
using namespace std;
#define INF 99999
#define v 4
void floydwarshall(int graph[][v])
{
    int i, j, k;
    for (k = 0; k < v; k++)
    {
        for (i = 0; i < v; i++)
        {
            for (j = 0; j < v; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
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

    int graph[v][v] = {{7, 5, INF, INF},
                       {7, INF, INF, 2},
                       {INF, 3, INF, INF},
                       {4, INF, 1, INF}};
    floydwarshall(graph);
}
