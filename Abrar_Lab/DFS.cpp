#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// DFS Function
void dfs(vector<vector<int>> &graph, int start)
{
    int vertices = graph.size();

    // Track visited nodes
    vector<bool> visited(vertices, false);

    // Stack for DFS
    stack<int> s;

    // Push starting node
    s.push(start);
    visited[start] = true;

    cout << "DFS Traversal: ";

    // Continue until stack becomes empty
    while (!s.empty())
    {
        // Take top node from stack
        int node = s.top();
        s.pop();

        // Print current node
        cout << node << " ";

        // Visit all neighbors
        for (int neighbor : graph[node])
        {
            // If not visited
            if (!visited[neighbor])
            {
                s.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    cout << endl;
}

int main()
{
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    // Create adjacency list
    vector<vector<int>> graph(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):" << endl;

    // Input edges
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u); // Undirected graph
    }

    int start;

    cout << "Enter starting node for DFS: ";
    cin >> start;

    // Call DFS
    dfs(graph, start);

    return 0;
}