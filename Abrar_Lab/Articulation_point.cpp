#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    vector<int> disc, low, parent;
    vector<bool> visited, ap;
    int timer;

public:
    // Constructor
    Graph(int V) {
        this->V = V;

        adj.resize(V);
        disc.resize(V);
        low.resize(V);
        parent.resize(V);
        visited.resize(V, false);
        ap.resize(V, false);

        timer = 0;

        for (int i = 0; i < V; i++) {
            parent[i] = -1;
        }
    }

    // Add edge
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected Graph
    }

    // DFS Function
    void DFS(int u) {
        int children = 0;

        visited[u] = true;
        disc[u] = low[u] = ++timer;

        for (int v : adj[u]) {

            // If not visited
            if (!visited[v]) {
                children++;
                parent[v] = u;

                DFS(v);

                // Update low value
                low[u] = min(low[u], low[v]);

                // Case 1: Root node with more than 1 child
                if (parent[u] == -1 && children > 1) {
                    ap[u] = true;
                }

                // Case 2: Non-root node
                if (parent[u] != -1 && low[v] >= disc[u]) {
                    ap[u] = true;
                }
            }

            // Back edge
            else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    // Find articulation points
    void findArticulationPoints() {

        // Run DFS for all components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i);
            }
        }

        // Print articulation points
        cout << "\nArticulation Points:\n";

        bool found = false;

        for (int i = 0; i < V; i++) {
            if (ap[i]) {
                cout << i << " ";
                found = true;
            }
        }

        if (!found) {
            cout << "No Articulation Point";
        }

        cout << endl;
    }
};

int main() {

    int V, E;

    // User input
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    // Input edges
    cout << "Enter edges (u v):\n";

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v);
    }

    // Find articulation points
    g.findArticulationPoints();

    return 0;
}