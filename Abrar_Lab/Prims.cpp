#include <iostream>
#include <vector>
#include <queue>
#include<climits>
using namespace std;

typedef pair<int, int> pii; // (weight, vertex)

// Function to implement Prim's Algorithm
void primMST(int n, vector<vector<pii>> &adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);

    int start = 0; // starting vertex
    key[start] = 0;
    pq.push({0, start});

    int totalCost = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        totalCost += weight;

        for (auto edge : adj[u]) {
            int v = edge.second;
            int w = edge.first;

            if (!visited[v] && w < key[v]) {
                key[v] = w;
                pq.push({w, v});
                parent[v] = u;
            }
        }
    }

    cout << "\nEdges in MST:\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << endl;
    }

    cout << "Total cost of MST: " << totalCost << endl;
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<pii>> adj(n);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        // Undirected graph
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    primMST(n, adj);

    return 0;
}