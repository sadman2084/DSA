#include <iostream>
#include <stack>

using namespace std;

const int V = 4;
int adjMatrix[V][V] = {0};

void addEdge(int src, int dest)
{
    adjMatrix[src][dest] = 1; 
}

void topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;

    for (int i = 0; i < V; i++)
    {
        if (adjMatrix[v][i] == 1 && !visited[i])
        {
            topologicalSortUtil(i, visited, Stack);
        }
    }

    Stack.push(v);
}

void topologicalSort()
{
    stack<int> Stack;
    bool visited[V] = {false};

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topologicalSortUtil(i, visited, Stack);
        }
    }

    cout << "Topological Sort:\n";
    while (!Stack.empty())
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 3);

    cout << "Performing topological sort:\n";
    topologicalSort();

    return 0;
}
