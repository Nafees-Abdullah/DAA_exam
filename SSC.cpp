#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Add directed edge
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // First DFS (store finish order)
    void dfs1(int v, vector<bool>& visited, stack<int>& st) {
        visited[v] = true;

        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs1(u, visited, st);
            }
        }

        st.push(v);
    }

    // Second DFS (print SCC)
    void dfs2(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs2(u, visited);
            }
        }
    }

    // Reverse Graph
    Graph getTranspose() {
        Graph g(V);

        for (int v = 0; v < V; v++) {
            for (int u : adj[v]) {
                g.addEdge(u, v);
            }
        }

        return g;
    }

    // Kosaraju Algorithm
    void kosarajuSCC() {
        stack<int> st;
        vector<bool> visited(V, false);

        // Step 1: DFS and fill stack
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs1(i, visited, st);
            }
        }

        // Step 2: Reverse graph
        Graph gr = getTranspose();

        // Step 3: DFS on reversed graph
        fill(visited.begin(), visited.end(), false);

        cout << "\nStrongly Connected Components:\n";

        while (!st.empty()) {
            int v = st.top();
            st.pop();

            if (!visited[v]) {
                gr.dfs2(v, visited);
                cout << endl;
            }
        }
    }
};

int main() {
    int V, E;

    // Input number of vertices and edges
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    // Input edges
    cout << "Enter directed edges (u v):\n";

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    // Find SCCs
    g.kosarajuSCC();

    return 0;
}