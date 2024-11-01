#include <iostream>
#include <queue>

using namespace std;

const int V = 4;
int adjMatrix[V][V] = {0};

void addEdge(int src, int dest)
{
    adjMatrix[src][dest] = 1; // SHOB EDGE ER VALUE 1
    adjMatrix[dest][src] = 1; // SHOB EDGE ER VALUE 1
}

void BFS(int start)
{
    bool visited[V] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int currVertex = q.front();
        cout << "Visited " << currVertex << " ";
        q.pop();

        for (int i = 0; i < V; i++)
        {
            if (adjMatrix[currVertex][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 3);

    cout << "BFS starting from vertex 2:\n";
    BFS(2);

    return 0;
}
